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
        shell->bytesInBuffer = 0;
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

    // Freeing up shell buffer;
    free(shell->buffer);
};

/**
 *  Returns whether or not the shell has been initailized.
 */ 
bool isRunning(Shell * shell) {
    return shell->running;
}

/**
 *  -- Shell Loop -- 
 *  This loop reads lines of user input, parses the input, and 
 */
void run(Shell * shell) {
    // Change the running state.
    shell->running = true;

    // Start the shell loop.
    while(isRunning(shell)) {
        // Getting user input from keyboard.
        getKeyboardInput(shell);



    }
}

// ---------------- HELPER FUNCTIONS ---------------


/**
 *  This function is responsible for getting user input from the keyboard
 *  and saving it to the shell's input buffer. It also handles special
 *  cases such as when an error occurs or the user wants to exit the shell.
 */
void getKeyboardInput(Shell * shell) {
    printf("\n%s", shell->prefix);

    fgets(shell->buffer, SHELL_BUFFER_SIZE, stdin)

    // char * tok = strtok(shell->buffer, " ");
    char *tok = strtok(shell->buffer, " ");
    shell->bytesInBuffer = sizeof(tok);

    while(tok != NULL) {
        printf("Got input: ");
        printf("%s ", tok);
        tok = strtok(NULL, " ");
    }
    
    // if(toupper(shell->buffer) == "exit") {
    //     shutdown(shell);
    // }
}