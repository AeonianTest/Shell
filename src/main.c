#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/*
    Core of the program
*/

// Entry point to start running the program
int main() {
    shell_start(); // Start the shell
    return EXIT_SUCCESS; // TODO: HANDLE EXIT STATUS DYNAMICALLY
}

// The main function responsible for handling user input
void shell_start() {
    char input[BUFFER_SIZE];

    // Always loop. Exits are manual breaks
    while (1) {
        // Display the shell prompt
        printf("BACI Shell > ");
        fflush(stdout); 

        // Look for EOF or ctrl+d to exit the program
        if (fgets(input, BUFFER_SIZE, stdin) == NULL) { // Read up to BUFFER_SIZE - 1 off a line
            printf("\n\nExiting BACI. Have a pleasant day!\n"); // If EOF or ctrl+d, break
            break;
        }

        // Remove newline character to make the input an acceptable string
        input[strcspn(input, "\n")] = '\0';

        // Exit condition. If true that input is exit is given, then quit
        if (strcmp(input, "exit") == 0) {
            printf("\nExiting BACI. Have a pleasant day!\n");
            break;
        }

        //Execution of input would start here
    }
}