#include <dirent.h>
#include <stdio.h>
#include "ls.h"

/*
    Implementaion of the unix ls command
    To be compilied into the a single executable with other source files
*/

void ls() { // TODO: mvp implementation of the list directory contents command
    //Get a ptr to the current relative dir and the declare a pointer to the struct representing dir
    DIR *dirPtr = opendir("."); 
    struct dirent *dirRead;

    // Return if unable to open the local directory
    if (dirPtr == NULL) {
        printf("Unable to open local dir\n");
        return;
    }

    // read then write the internals of the dir until no entries
    while ((dirRead = readdir(dirPtr)) != NULL) {
        printf("%s\n", dirRead->d_name);
    }

    //Return
    closedir(dirPtr);
    return;
}