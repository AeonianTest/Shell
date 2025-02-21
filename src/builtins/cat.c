#include <stdio.h>
#include <string.h>
#include "cat.h"

/*
    Implementaion of the unix cat command
    To be compilied into the a single executable with other source files
*/

void cat(char **args) { // MVP implementation of cat, expand as needed
    int i = 0;
    args += 1;
    FILE *file;
    
    while (args[i] != NULL) {
        file = fopen(args[i], "r");

        //Attempt to open the file, continue if fail
        if (file == NULL) {
            perror(args[i]);
            i++;
            continue;
        }

        // Read char from the file, format after
        int c;
        while ((c = fgetc(file)) != EOF) //Get unsigned char, then print the unsigned char to the output stream
            putchar(c);
        printf("\n");

        // Close the file 
        fclose(file);
        i++; 
    }
}