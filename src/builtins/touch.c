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
    struct stat fileStat;
    args += 1;
    int fileDesc;
    int i = 0;

    if (args[0] == NULL) {
        fprintf(stderr, "touch: missing file operand\n");
        return;
    }

    // While arguments still exist
    while (args[i] != NULL) {

        // Check if file exists, if true update access timestamps
        if (stat(args[i], &fileStat) == 0) {
            // File exists, update access time
            if (utime(args[i], NULL) != 0) {
                // If error occured in updating
                perror("Error updating time stamps");
            }
        }
        else { // Else if 0 (Success) not returned by stat, file not exist so we can create it
            // Open the file in write mode,
            fileDesc = open(args[i], STD_OPEN_FLAGS, DEFAULT_PERMS);
            
            // Basic err handling
            if (fileDesc < 0) {
                perror("error creating file");
                continue;;
            }

            // Close file on use
            close(fileDesc);
        }

        i++;
    }
}