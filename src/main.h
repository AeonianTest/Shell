#ifndef MAIN_H
#define MAIN_H

// Macros
#define BUFFER_SIZE 1024 // Buffer char size for input
#define TOKENS_AMT 64 // Amount of tokens allowed in a line

// Function declerations
void shell_start(); // The main function responsible for handling user input
void tokenise_inputs(char *input, char **args); // Turn a line of input into tokens
void execute_inputs(char **args); // TODO: Handle the execution of the args (ie call the correct command and then ). 

#endif