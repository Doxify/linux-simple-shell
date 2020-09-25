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
        handleUserInput(shell);
        
        // // Forking before we exec so that the parent doesn't get killed
        // // and verifying that the fork was successful.
        // pid_t fork_pid = fork();
        // if(fork_pid == -1) {
        //     printf("** An error occurred during shell runtime. (fork) **");
        //     return;
        // }

        // // If fork succeeds and we are in the child process,
        // // we can then use the exec system call.
        // if(fork_pid != 0) {

        // }

        // // If fork succeeds and we are in main, we wait for
        // // the child process to finish.
        // if(fork_pid == 0) {
        //     // wait(); ??
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
 */
void handleUserInput(Shell * shell) {
    int tokenCount = 0;
    char args[SHELL_BUFFER_SIZE];
    
    // Getting and saving user input to the shell's buffer.
    printf("\n%s", shell->prefix);
    fgets(shell->buffer, SHELL_BUFFER_SIZE, stdin);
    
    // Parsing input with strtok_r.
    char * r = NULL;
    char * tok = strtok_r(shell->buffer, " ", &r);
    while(tok != NULL) {
        // Storing args in the shell's arg array.
        strcpy(&args[tokenCount++], tok);
        tok = strtok_r(NULL, " ", &r);
    }

    // Checking for errors.
    if(tokenCount == 0) {
        // If the user doesn't enter any input, prompt them again.
        printf("Error: Please enter at least one input.");
        handleUserInput(shell);
    } 

    // If only one token exists, check if it is exit or quit.
    if(tokenCount == 1) {
        if(strncmp(&args[0], "quit", 4) || strncmp(&args[0], "exit", 4)) {
            printf("Shutting down...");
            shutdown(shell);
        }
    }

    printf("printing args: (%d)", tokenCount);
    for(int i = 0; i < tokenCount; i++) {
        printf("%s ", &args[i]);
    }
}