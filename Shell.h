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
#include <stdbool.h>

typedef struct Shell {
    bool running;
    // char * prefix;
} Shell;

void run(Shell * shell); // Starts the "shell loop".
void shutdown(Shell * shell); // Shutsdown the shell loop.
bool isRunning(Shell * shell); // Returns running state.

#endif