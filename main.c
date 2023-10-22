#include <stdio.h>
#include <stdlib.h>

/**
 * main - function is the entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on successful execution, EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	char *endptr = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <int>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	(void)strtol(argv[1], &endptr, 10);

	if (*endptr != '\0')
	{
		fprintf(stderr, "L4: usage: push integer\n");
		exit(EXIT_FAILURE);
	}

	return (0);
}

