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
    char * prefix;
    char * buffer;
    char * args;
    int argsCount;
} Shell;

int init(Shell *); // Initializes a shell.
void run(Shell *); // Starts the "shell loop".
void shutdown(Shell *); // Shutsdown the shell loop and frees any allocated memory.
bool isRunning(const Shell *); // Returns running state.


int handleUserInput(Shell *);

int shell_execvp(const char *file, char *const argv[]);

#endif