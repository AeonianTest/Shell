#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "builtins/cat.h"
#include "builtins/echo.h"
#include "builtins/ls.h"
#include "builtins/cd.h"

/*
    Core of the program
    MAIN TODO:
        - Relative navigation commands (ls, pwd, cd)
        - expand mvps
*/

// Entry point to start running the program
int main() {
    shell_start(); // Start the shell
    return EXIT_SUCCESS; // TODO: HANDLE EXIT STATUS DYNAMICALLY
}

// The main function responsible for handling user input
void shell_start() {
    char input[BUFFER_SIZE]; // Line of input
    char *args[TOKENS_AMT]; // Arguments broken into seperate tokens

    // Always loop. Exits are manual breaks
    while (1) {
        // Display the shell prompt
        printf("BACI Shell > ");
        fflush(stdout); 

        // Look for EOF or ctrl+d to exit the program
        if (fgets(input, BUFFER_SIZE, stdin) == NULL) { // Read up to BUFFER_SIZE - 1 off a line, rewriting every new loop
            printf("\n\nExiting BACI. Have a pleasant day!\n"); // If EOF or ctrl+d, break
            break;
        }

        // Remove newline character to make the input an acceptable string
        input[strcspn(input, "\n")] = '\0';

        // Exit commands. If true that input is exit or quit is given, then terminate the loop and thus program
        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0) {
            printf("\nExiting BACI. Have a pleasant day!\n");
            break;
        }

        // Parse the input here into tokens
        tokenise_inputs(input, args);

        // if (args[0] != NULL) { // TESTING
        //     printf("TESTING: args[0]: %s\n", args[0]);
        // }

        // if (args[1] != NULL) { // TESTING
        //     printf("TESTING: args[1]: %s\n", args[1]);
        // }

        // Execute the command
        execute_command(args);
    }
}

// Turn the arguments into tokens
void tokenise_inputs(char *input, char **args) {
    char *token = strtok(input, " \n\t");
    int i = 0;
    
    // While tokens exist, keep appending
    while (token != NULL && i < TOKENS_AMT - 1) {
        args[i++] = token;
        token = strtok(NULL, " \n\t");
    }

    // Null terminate the argument list
    args[i] = NULL;  
}

// Handle the execution of the main command called
void execute_command(char **args) {
    //Check for the given command
    if (strcmp(args[0], "cat") == 0) {
        cat(args);
    }
    else if (strcmp(args[0], "echo") == 0) {
        echo(args);
    }
    else if (strcmp(args[0], "ls") == 0) {
        ls(args);
    }
    else if (strcmp(args[0], "cd") == 0) {
        cd(args[1]);
    }
    else {
        printf("Invalid command %s\n", args[0]);
    }
}