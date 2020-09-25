/**************************************************************
* Class: CSC-415-01 Fall 2020
* Name: Andrei Georgescu
* Github Name: Doxify
* Student ID: 920776919
* Project: Assignment 3 – Simple Shell
*
* File: Shell.c
*
* Description: 
*
**************************************************************/
#include "Shell.h"

#define SHELL_BUFFER_SIZE 512

int init(Shell * shell) {
    // Verifying that the shell has not yet been initialized.
    if(!shell->running) {
        shell->buffer = (char*)malloc(SHELL_BUFFER_SIZE);
        // shell->args = (char*)malloc(SHELL_BUFFER_SIZE);
        return 1;
    } else {
        printf("This shell has already been initialized");
        return -1;
    }
}

/**
 *  Shutsdown a Shell, _
 */ 
void shutdown(Shell * shell) {
    // Do shutdown stuff.
    shell->running = false;

    // Freeing up shell allocated memory;
    free(shell->buffer);
    // free(shell->args);
};

/**
 *  Returns whether or not the shell has been initailized.
 */ 
bool isRunning(const Shell * shell) {
    return shell->running;
}

/**
 *  -- Shell Loop -- 
 *  This loop first reads lines of user input, parses the input.
 *  Next, it forks 
 */
void run(Shell * shell) {
    // Change the running state.
    shell->running = true;

    // Start the shell loop.
    // Responsible for parsing user input and executing it.
    while(isRunning(shell)) {
        // Getting user input from keyboard.
        int input = handleUserInput(shell);

        // If the user enters an invalid input or exits the shell,
        // then we should stop the shell from running and exit.
        if(input == 0) {
            shell->running = false;
            continue;
        };
        
        // // Forking before we exec so that the parent doesn't get killed
        // // and verifying that the fork was successful.
        // pid_t fork_pid = fork();
        // if(fork_pid == -1) {
        //     printf("** An error occurred during shell runtime. (fork) **");
        //     shell->running = false;
        //     continue;
        // }

        // // If fork succeeds, detect whether we are in the parent or child process.
        // if(fork_pid == 0) {
        //     // When we are in the child process, we should execute.
        //     int result = execvp(shell->args, shell->args)
        //     if(execvp(shell->args[0], *shell->args) == -1) {
        //         printf("An error occurred while running %s", shell->args);
        //     }
        //     exit(0);
        // } else {
        //     // When we are in the main or parent process, we should wait.
        //     wait(NULL);
        // }


        // // fork -> execvp -> wait -> DONE!
        // // pid_t fork(void);
        // int execvp(const char *file, char *const argv[]);
        // pid_t wait(int *wstatus);


    }
}

// ---------------- HELPER FUNCTIONS ---------------


/**
 *  This function is responsible for getting user input from the keyboard
 *  and saving it to the shell's input buffer. It also handles special
 *  cases such as when an error occurs or the user wants to exit the shell.
 *  @return 1 if input was parsed successfully, 0 if an error occurred
 */
int handleUserInput(Shell * shell) {    
    // Prompting the user for input, verifying it, and storing it in the shell's buffer.
    printf("\n%s", shell->prefix);
    fgets(shell->buffer, SHELL_BUFFER_SIZE, stdin);

    // Parsing input with strtok_r and storing it in the shell.
    int tokenCount = 0;
    char * r = NULL;
    char * tok = strtok_r(shell->buffer, " ", &r);
    while(tok != NULL) {
        // Storing args in the shell's arg array.
        // strcpy(&shell->args[tokenCount++], tok);
        shell->args[tokenCount] = *tok;
        tok = strtok_r(NULL, " ", &r);
        tokenCount++;
    }

    printf("tokens: %d\n", tokenCount);
    for(int i = 0; i < tokenCount; i++) {
        printf("%s ", &shell->args[i]);
    }


    // Validating parsed input.
    if(tokenCount == 1) {
        // If the user quits, return 0.
        if(strncmp(shell->args, "quit", 4) == 0 || strncmp(shell->args, "exit", 4) == 0) {
            return 0;
        }

        // If the user enters a blank line, prompt them for input again.
        if(strncmp(shell->args, "\n", 1) == 0) {
            printf("Detected empty input, please try again.");
            return handleUserInput(shell);
        }
    }

    return 1;
}