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
 *  Initializes a Shell, _
 */  
void init(Shell * shell) {
    if(!shell->init) {
        // do init stuff here...
        shell->init = true;
    }
};

/**
 *  Shutsdown a Shell, _
 */ 
void shutdown(Shell * shell) {
    // Do shutdown stuff.
    shell->init = false;
};

bool isInitialized(Shell * shell) {
    return shell->init;
}