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

/**
 *  Shutsdown a Shell, _
 */ 
void shutdown(Shell * shell) {
    // Do shutdown stuff.
    shell->running = false;
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
        char input[256];
        printf("\nprefix ");
        scanf("%s", input);
        printf("Got input: %s", input);
    }
}