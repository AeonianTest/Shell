#include <stdio.h>
#include <unistd.h>
#include "pwd.h"

/*
    Implementaion of the unix pwd command
    To be compilied into the a single executable with other source files
*/

void pwd() { // 
    char currentDir[MAX_CWD_LENGTH]; 

    if (getcwd(currentDir, sizeof(currentDir)) != NULL) {
        printf("%s\n", currentDir);
    }
    else {
        perror("Error is accessing the directory");
    }
}