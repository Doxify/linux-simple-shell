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

#include <stdbool.h>

typedef struct Shell {
    bool init;
} Shell;

void init(Shell * shell); // Initializes the shell.
void shutdown(Shell * shell); // Shutsdown the shell.
bool isInitialized(Shell * shell); // Returns initialized state.

#endif