#ifndef MAIN_H
#define MAIN_H

// Macros
#define BUFFER_SIZE 1024 // Buffer char size for input
#define TOKENS_AMT 64 // Amount of tokens allowed in a line - 1 for null term
#define ANSI_COLOR_CYAN "\x1b[36m" // Used for printing colour to the terminal
#define ANSI_COLOR_RESET "\x1b[0m"

// Function declerations
void shell_start(); // The main function responsible for handling user input
void tokenise_inputs(char *input, char **args); // Turn a line of input into tokens
void execute_command(char **args); // Handles the execution of the built in commands. 
void format_prompt(); // Format the shell prompt printout with relative position

#endif