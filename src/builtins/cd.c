#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "cd.h"

/*
    Implementaion of the unix cd command
    To be compilied into the a single executable with other source files
*/

void cd(char *filepath) { // mvp implementation of the cd commandf
    char finalPath[EXPANDED_PATH_LENGTH];

    if (filepath[0] == '~') { 
        const char *home = getenv("HOME"); // Safely write the HOME env var to the finalPath
        snprintf(finalPath, sizeof(finalPath), "%s%s", home, filepath + 1);
    } 
    else {
        strncpy(finalPath, filepath, sizeof(finalPath) - 1);
        finalPath[sizeof(finalPath) - 1] = '\0';
    }

    //Run the change in dir, if err returned print
    if (chdir(finalPath))
        perror("Failure to access the given path");

    return;
}