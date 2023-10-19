#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void execute_file(const char *filename);

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Always 0 (success)
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	execute_file(argv[1]);

	return (0);
}

/**
 * execute_file - Reads and executes Monty bytecodes from a file
 * @filename: Name of the file containing Monty bytecodes
 */
void execute_file(const char *filename)
{
	FILE *file = fopen(filename, "r");
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++; /* Implement opcode execution based on the line content */
	}

	free(line);
	fclose(file);
}

