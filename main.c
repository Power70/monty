#define _POSIX_C_SOURCE 200809L
#include "monty.h"
monty_inst instance_vars = {NULL, NULL, NULL};

/**
 * main - Entry point, interpreter for Monty bytecodes files
 *
 * @argc: argument count
 * @argv: argument vector, monty file location
 *
 * Return: 0 (on Success)
 */

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read = 1;
	FILE *file;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	instance_vars.file = file;

	while (read > 0)
	{
		read = getline(&line, &len, file);
		instance_vars.line = line;
		line_number++;
		if (read != -1)
			execute(&stack, line_number, line, file);
	}

	free(line);
	free_struct(stack);
	fclose(file);

	return (0);
}
