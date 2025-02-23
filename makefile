## makefile to build and compile the shell into an executable

# makefile variables
CC = gcc 
TARGET = BAci
CFLAGS = -Wall -Wextra -ggdb
SRC = src/main.c src/builtins/cat.c src/builtins/echo.c \
	src/builtins/ls.c src/builtins/cd.c src/builtins/pwd.c \
	src/builtins/touch.c
OBJ = $(SRC:.c=.o)

# Default target for the makefile, must construct the target bin prereq
all: $(TARGET)

# Build the target file, depends on all the .o files being created as a prereq
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Use this to build .o files from all the .c needed for above rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove all the .o files and the produced bin to clean up
clean:
	rm -f $(OBJ) $(TARGET)

# Disassociate 'all' and 'clean' pre-existing files from makefile recognition
.PHONY: all clean