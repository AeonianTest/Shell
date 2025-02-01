#include <stdio.h>
#include <string.h>
#include "echo.h"

/*
    Implementaion of the unix pwd command
    Compilied with the final bin
*/

void echo(char **args) { // mvp implementation of echo cmd, expand as needed
    // Set up variables, inc args one pointer to avoid echo command
    int i = 0;
    args += 1;

    // while args exist, print them. Add spaces
    while (args[i] != NULL) {
        printf("%s", args[i]);
        if (args[i++ + 1] != NULL) { printf(" "); }
    }
    putchar('\n');
}