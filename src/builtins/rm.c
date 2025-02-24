#include <stdio.h>
#include <unistd.h>
#include "rm.h"

/*
    Naive Implementaion of the unix rm command
    To be compilied into the a single executable with other source files
*/

void rm(char **args) {
    // Bare min v0.1 tm

    if (unlink(args[1]) != 0) {
        perror("error when trying rm");
    }   
}