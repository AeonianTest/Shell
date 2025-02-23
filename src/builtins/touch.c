#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "touch.h"

/*
    Naive Implementaion of the unix touch command
    To be compilied into the a single executable with other source files
*/

void touch(char **args) {
    // v0.1 bare min tm

    // Open the file in write mode, if not exist
    int fileDesc = open(args[1], STD_OPEN_FLAGS, DEFAULT_PERMS);
    
    // Basic err handling
    if (fileDesc == -1) {
        perror("touch");
        return;
    }

    close(fileDesc);
}