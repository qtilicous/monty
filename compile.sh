#!/bin/bash

gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

if [ $? -eq 0 ]; then
    ./monty "$1"
fi

