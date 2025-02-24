#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "rm.h"

/*
    Naive Implementaion of the unix rm command
    To be compilied into the a single executable with other source files
*/

void rm(char **args) {
    struct stat fileStat;
    int i = 0;
    args += 1;

    if (args[0] == NULL) {
        fprintf(stderr, "rm: missing file operand\n");
        return;
    }

    // Loop for all the arguments
    while (args[i] != NULL) {
        // Check if file exists
        if (stat(args[i], &fileStat) != 0) {
            perror("rm");
            i++;
            continue; // rep w cont in final copy
        }

        // Bless stackoverflow
        // Check if file is a directory
        if (S_ISDIR(fileStat.st_mode)) {
            fprintf(stderr, "rm: cannot remove '%s': Is a directory\n", args[i]);
            i++;
            continue;
        }

        // Basic unlinking of a file to free it up once no proccess' on it
        if (unlink(args[i]) != 0) {
            perror("rm: error when unlinking");
        }

        i++;
    }
}