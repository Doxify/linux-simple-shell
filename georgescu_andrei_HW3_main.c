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
    Shell * shell;

    // // Setting the prefix is one is specified.
    // if(argc == 1) {
    //     shell->prefix = argv[0];
    // } else {
    //     shell->prefix = ">";
    // }

    // Starting the shell loop and verifing that it's running.
    run(shell);
    if(!isRunning(shell)) {
        printf("Error occurred while initializing the shell.");
        return -1;
    }
    
    return 1;
}