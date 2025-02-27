# BACI: BAsic Commandline Interface

This project is a personal exercise in creating a basic shell imitation that connects to the kernel/OS, for unix systems. Considerable amount of simplifying assumptions are currently done for this implementations, such as all the current commands being implementated by being pre compilied into the executable, and the lack of forking of proccess'.

## Building

Building is done using the makefile tool for compilation, default using gcc. If using alternative compiler change the CC flag to the appropriate in the makefile. In the root of the repository, execute the command 

    make

to build the project into an binary executable `BAci`. In order to remove the binary and compiled .o files run.

    make clean

Please note that the safest way to compile this project is to run 

    make clean && make

## Inbuilt cmds

Currently bare minimum support for commands are cat, cd, echo, ls, pwd, rm and touch. Please note that they not very sophisticated examples, and do not currently support any flags to enhance function currently.