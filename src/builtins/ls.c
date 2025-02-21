#include <dirent.h>
#include <stdio.h>
#include "ls.h"

/*
    Implementaion of the unix ls command
    To be compilied into the a single executable with other source files
*/

void ls(char **args) { // mvp implementation of the list directory contents command
    int i = 0;
    args += 1;
    struct dirent *dirRead;
    DIR *dirPtr;

    // Default to local dir if no arguments provided
    if (args[0] == NULL) { 
        args[0] = ".";
        args[1] = NULL;
    }

    while (args[i] != NULL) {  // Loop through dir args
        dirPtr = opendir(args[i]);

         // Print detailed error then continue to next arg
        if (dirPtr == NULL) {
            perror("ls");
            i++;
            continue; 
        }

        printf("%s:\n", args[i]);  // Print directory name

        while ((dirRead = readdir(dirPtr)) != NULL) {
            printf("%s\n", dirRead->d_name);
        }

        if (args[i+1] != NULL) 
            printf("\n");

        closedir(dirPtr);  // Close directory after reading
        i++;
    }
}