#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include "builtins/cat.h"
#include "builtins/echo.h"
#include "builtins/ls.h"
#include "builtins/cd.h"
#include "builtins/pwd.h"
#include "builtins/touch.h"
#include "builtins/rm.h"

/*
    Core of the program
    MAIN TODO:
        - File management cmds (rm touch)
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
        //Print out the shell prompt
        format_prompt();
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
    else if (strcmp(args[0], "pwd") == 0) {
        pwd();
    }
    else if (strcmp(args[0], "touch") == 0) {
        touch(args);
    }
    else if (strcmp(args[0], "rm") == 0) {
        rm(args);
    }
    else {
        printf("Invalid command %s\n", args[0]);
    }
}

// Handle the output of the shell prompt to the terminal
void format_prompt() {
    char currentDir[MAX_CWD_LENGTH];
    char *finalSlashPtr;

    // get the cwd, search for the current dir to display in Shell prompt
    if (getcwd(currentDir, sizeof(currentDir)) != NULL) {
        finalSlashPtr = strrchr(currentDir, '/');
        printf("BACI %s %s>%s ", finalSlashPtr, ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
    }
    else {
        perror("Can't find dir");
        printf("BACI /ERR %s>%s", ANSI_COLOR_CYAN, ANSI_COLOR_RESET);
    }
}