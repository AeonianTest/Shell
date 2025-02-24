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

    // Check if file exists
    if (stat(args[1], &fileStat) != 0) {
        perror("rm");
        return; // rep w cont in final copy
    }

    // Bless stackoverflow
    // Check if file is a directory
    if (S_ISDIR(fileStat.st_mode)) {
        perror("rm: cannot remove target, is a Directory");
        return;
    }

    // Basic unlinking of a file to free it up once no proccess' on it
    if (unlink(args[1]) != 0) {
        perror("rm: error when unlinking");
    }
}