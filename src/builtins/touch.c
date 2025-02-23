#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <utime.h>
#include <sys/stat.h>
#include "touch.h"

/*
    Naive Implementaion of the unix touch command
    To be compilied into the a single executable with other source files
*/

void touch(char **args) {
    // v0.2 bare min tm
    struct stat fileStat;
    int fileDesc;

    // Check if file exists, if true update access timestamps
    if (stat(args[1], &fileStat) == 0) {
        // File exists, update access time
        if (utime(args[1], NULL) != 0) {
            // If error occured in updating
            perror("Error updating time stamps");
        }
        else {
            printf("File %s already exists, updating timestamp\n", args[1]);
        }
    }
    else { // Else if 0 (Success) not returned by stat, file not exist so we can create it
        // Open the file in write mode,
        fileDesc = open(args[1], STD_OPEN_FLAGS, DEFAULT_PERMS);
        
        // Basic err handling
        if (fileDesc < 0) {
            perror("error creating file");
            return;
        }

        // Close file on use
        close(fileDesc);
    }
}