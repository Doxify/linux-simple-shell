/**************************************************************
* Written by Andrei Georgescu
*
* File: Shell.c
*
* Description: This is the Shell Program where all of the Shell's
*              methods are implemented. Shell is a program that
*              uses linux system calls to re-create a linux shell
*              through the use of fork, execvp, and wait system
*              calls.
*
**************************************************************/
#include "Shell.h"

#define SHELL_BUFFER_SIZE 512

/**
 *  Initializes a shell and allocates memory as needed.
 *  @return 1 if success, -1 if an error occurred.
 */ 
int init(Shell * shell) {
    // Verifying that the shell has not yet been initialized.
    if(!shell->running) {
        shell->buffer = (char*)malloc(SHELL_BUFFER_SIZE);
        shell->args = (char **)malloc(sizeof(char *));
        shell->argsCount = 0;
        return 1;
    } else {
        printf("This shell has already been initialized");
        return -1;
    }
}

/**
 *  Shutsdown a Shell and frees any memory allocated by the shell.
 */ 
void shutdown(Shell * shell) {
    // Do shutdown stuff.
    shell->running = false;

    // Freeing up allocated memory by the shell.
    freeArgs(shell);
    free(shell->buffer);
};

/**
 *  -- Shell Loop -- 
 *  The shell loop is the main driver of the shell. Each loop consists of 
 *  getting user input from the keyboard, parsing it into individual arguments,
 *  and executing the user input via the execvp system call.
 */
void run(Shell * shell) {
    int status;
    shell->running = true;

    while(shell->running) {
        status = getUserInput(shell);
        // If an error occurs while grabbing input, the shell must gracefully exit.
        if(status == 0) {
            printf("** An error occurred while getting input from keyboard. **\n");
            shell->running = false;
            continue;
        }

        // If the shell has arguments from a previous call, we need to free
        // the previous stored arguments.
        if(shell->argsCount > 0) {
            freeArgs(shell);
            shell->args = (char **)malloc(sizeof(char *));
            shell->argsCount = 0;
        }

        status = parseBuffer(shell);
        // If the user enters an invalid input or exits the shell,
        // then we should stop the shell from running and exit.
        if(status == 0) {
            shell->running = false;
            continue;
        }
        
        // Forking before we exec so that the parent doesn't get killed
        // and verifying that the fork was successful.
        pid_t fork_pid = fork();
        if(fork_pid == -1) {
            printf("** An error occurred during shell runtime. (fork) **\n");
            shell->running = false;
            continue;
        }

        // If fork succeeds, we need to detect which process we are in.
        // If we are in the child process, we need to execute the shell's args.
        // If we are in the main process, we need to wait for the child.
        if(fork_pid == 0) {
            // When we are in the child process, we should execute.
            int execResult = execvp(shell->args[0], shell->args);
            if(execResult == -1) {
                printf("** An error occurred during shell execution (child) **\n");
            }
            exit(0);
        } else {
            // The main process is responsible for waiting on the child process
            // to finish executing and reporting the result of the child process'
            // execution to the user.
            int child_status;
            int child_pid = wait(&child_status);
            if(WIFEXITED(child_status)) {
                int childResult = WEXITSTATUS(child_status);
                printf("Child %d, exited with %d", child_pid, childResult);
            }
        }
    }
}

/**
 *  Prompts the user for input and stores it in the shell's buffer.
 */ 
int getUserInput(Shell * shell) {    
    printf("\n%s", shell->prefix);
    if(fgets(shell->buffer, SHELL_BUFFER_SIZE, stdin) == NULL) {
        return 0;
    }
    return 1;
}

/**
 *  Parses the shell's buffer. 
 *  This function is responsible for parsing each word or token from the buffer
 *  and stores it in the shell's args array.
 * 
 *  -- This function should be called after user input has been fetched. --
 * @param shell
 * @return 1 on success, 0 if an error occurred or shell should quit
 */ 
int parseBuffer(Shell * shell) {
    // Parsing each individual argument in the shell's buffer and storing it in 
    // the shell's args array.
    int tokenCount = 0;
    char * tok = strtok(shell->buffer, " \t\n");
    while(tok != NULL) {
        // Allocating memory for the token that's being read and storing it
        // in the shell's args array.
        shell->args[tokenCount] = malloc(sizeof(char) * ((strlen(tok) + 1)));
        strcpy(shell->args[tokenCount], tok);
        tokenCount++;
        shell->argsCount = tokenCount;

        tok = strtok(NULL, " \t\n");        
        if(tok != NULL) {
            // If a next token exists, we allocate memory for it.
            // NOTE ABOUT (tokenCount + 2): The 2 is very important because
            // it not only allocates memory for the next pointer, but also
            // for the pointer after that which MAY be a null pointer.
            char ** temp = (char **)realloc(shell->args, sizeof(char *) * (tokenCount + 2));
            if(temp != NULL) {
                shell->args = temp;
            }
        }
    }
    // This line will crash the program if memory is not allocated above, see note.
    shell->args[shell->argsCount] = NULL;

    // printf("\ntokens: %d\n", shell->argsCount);
    // for(int i = 0; i < shell->argsCount; i++) {
    //     printf("{%s}", shell->args[i]);
    // }
    // printf("\n");
    
    // Validating parsed input.
    if(tokenCount == 1) {
        // If the user quits, return 0.
        if(strncmp(shell->args[0], "quit", 4) == 0 || strncmp(shell->args[0], "exit", 4) == 0) {
            return 0;
        }

        // If the user enters a blank line, prompt them for input again.
        if(strncmp(shell->args[0], "\n", 1) == 0) {
            printf("Detected empty input, please try again.");
            return getUserInput(shell);
        }
    }

    return 1;
}

/**
 *  This function is responsible for freeing up memory allocated by 
 *  the shell's args array of pointers as well as the array itself.
 */
void freeArgs(Shell * shell) {
    for(int i = 0; i < shell->argsCount; i++) {
        free(shell->args[i]);
    }
    free(shell->args);
}