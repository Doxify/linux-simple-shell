/**************************************************************
* Class: CSC-415-01 Fall 2020
* Name: Andrei Georgescu
* Github Name: Doxify
* Student ID: 920776919
* Project: Assignment 3 – Simple Shell
*
* File: Shell.h
*
* Description: 
*
**************************************************************/
#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

// This is the Shell Struct, in theory you can have multiple shells.
typedef struct Shell {
    bool running;
    char *prefix;
    char *buffer;
} Shell;

int init(Shell *); // Initializes a shell.
void run(Shell *); // Starts the "shell loop".
void shutdown(Shell *); // Shutsdown the shell loop and frees any allocated memory.
bool isRunning(Shell *); // Returns running state.

/**
 * Helper function that handles user input.
 * It's responsible for pasring input so that the shell can
 * exit when a user requests it and it's also responsible for
 * handling errors that occur when users input text.
 */
void handleUserInput(Shell *);

int shell_execvp(const char *file, char *const argv[]);

#endif