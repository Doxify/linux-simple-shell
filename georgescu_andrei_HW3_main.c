/**************************************************************
* Class: CSC-415-01 Fall 2020
* Name: Andrei Georgescu
* Github Name: Doxify
* Student ID: 920776919
* Project: Assignment 3 – Simple Shell
*
* File: georgescu_andrei_HW3_main.cpp
*
* Description: This is the driver program for the Shell. It is
*              responsible for initializing a shell and starting
*              the shell loop.      
*
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Shell.h"

int main(int argc, char * argv[]) {
    // Declaring variables.
    Shell * shell = (Shell*)malloc(sizeof(Shell*));

    // Setting the prefix if one is specified.
    if(argc == 2) {
        shell->prefix = argv[1];
        // memcpy(argv[1], shell->prefix, sizeof(argv[1]));
    } else {
        shell->prefix = "> ";
    }

    // Initializing the shell and verifying that it has been initialized.
    if(init(shell) == -1) {
        printf("Error occurred while initializing the shell.");
        return -1;
    }

    // Starting the shell loop and verifing that it's running.
    run(shell);
    if(!isRunning(shell)) {
        printf("Error occurred while starting the shell loop.");
        return -1;
    }
    
    return 1;
}