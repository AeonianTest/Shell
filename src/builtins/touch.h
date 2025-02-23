#ifndef TOUCH_H
#define TOUCH_H

// Macros
#define DEFAULT_PERMS 0644 // rw-r--r-- permission
#define STD_OPEN_FLAGS O_WRONLY | O_CREAT // Flags to open a file in write mode if not exist

// Functions
void touch(char **args); // Naive implementation of the file creation cmd touch

#endif