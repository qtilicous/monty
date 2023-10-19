#define _POSIX_C_SOURCE 200809L
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file) != -1))
	{
		if (!process_line(line, &stack))
		{
			fprintf(stderr, "Error: Invalid instruction on line %u\n", get_line_number(line));
			free_resources(file, line, stack);
			exit(EXIT_FAILURE);
		}
	}

	free_resources(file, line, stack);
	exit(EXIT_SUCCESS);
}

