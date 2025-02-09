#include <stdio.h>
#include <string.h>
#include "cat.h"

/*
    Implementaion of the unix cat command
    To be compilied into the a single executable with other source files
*/

void cat(char* filename) { // MVP implementation of cat, expand as needed
    FILE *file = fopen(filename, "r");

    //Attempt to open the file, early return if fail
    if (file == NULL) {
        printf("Unable to open file %s\n", filename);
        return;
    }

    // Read char from the file
    char c;
    while ((c = fgetc(file)) != EOF) //Get unsigned char, then print the unsigned char to the output stream
        putchar(c);

    // Format then close the file
    putchar('\n');
    fclose(file);
}