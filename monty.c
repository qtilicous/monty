#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * main - The entry point
 * @argc: amount of arguments
 * @argv: list of aguments
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	free(line);
	fclose(file);
	return (EXIT_SUCCESS);
}

