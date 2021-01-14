/**************************************************************
* Written by Andrei Georgescu
*
* File: Shell.h
*
* Description: Defines the Shell struct as well as prototypes
*              for the methods that it should implement.
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
    char ** args;
    int argsCount;
} Shell;

int init(Shell *); // Initializes a shell.
void run(Shell *); // Starts the "shell loop".
void shutdown(Shell *); // Shutsdown the shell loop and frees any allocated memory.
void freeArgs(Shell *); // Frees all memory allocated by args.
int getUserInput(Shell *); // Gets user input and stores it in the buffer.
int parseBuffer(Shell *); // Parses the buffer and stores arguments in args.

#endif