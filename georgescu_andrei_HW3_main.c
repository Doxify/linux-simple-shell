/**************************************************************
* Class: CSC-415-01 Fall 2020
* Name: Andrei Georgescu
* Github Name: Doxify
* Student ID: 920776919
* Project: Assignment 3 – Simple Shell
*
* File: georgescu_andrei_HW3_main.cpp
*
* Description: 
*
**************************************************************/
#include <stdio.h>
#include "Shell.h"

int main(int argc, char * argv[]) {
    // Declaring variables.
    Shell * shell;

    // Initializing the shell and verifying that it's initialized.
    init(shell);
    if(!isInitialized(shell)) {
        printf("Error occurred while initializing the shell.");
        return -1;
    }

    /**
     *  -- Shell Loop -- 
     *  This loop reads lines of user input, parses the input, and 
     *  executes commands by forking/creating new processes.
     */ 
    do {
        // do shell loop stuff.
    } while(isInitialized(shell));

    
}