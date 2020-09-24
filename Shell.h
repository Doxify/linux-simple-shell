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
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> 
#include <string.h>

typedef struct Shell {
    bool running;
    char *prefix;
    char *buffer;
    int bytesInBuffer;
} Shell;

int init(Shell *);
void run(Shell *); // Starts the "shell loop".
void shutdown(Shell *); // Shutsdown the shell loop.
bool isRunning(Shell *); // Returns running state.
void getKeyboardInput(Shell *);

#endif