#include "monty.h"

/**
 * execute - executes the opcode
 *
 * @stack: pointer to a pointer, pointing to the top of the stack
 * @line_number: the number of file lines counted,
 * line number where opcode is found
 * @file: the Monty bytecode file
 * @content: content of the current file line
 *
 * Return: 0 (Success)
 */
int execute(stack_t **stack, unsigned int line_number, char *content,
		FILE *file)
{
	unsigned int i = 0;
	char *op;

	instruction_t op_list[] = {
		{"push", stack_push},
		{"pall", struct_pall},
		{"pint", pint_top},
		{"pop", pop_top},
		{"swap", swap_elem},
		{"add", add_elem},
		{"nop", nop},
		{"sub", sub_elem},
		{"div", div_elem},
		{NULL, NULL}
	};

	op = strtok(content, " \n\t");

	if (op != NULL && op[0] == '#')
		return (0);
	instance_vars.monty_arg = strtok(NULL, " \n\t");

	while (op != NULL && op_list[i].opcode)
	{
		if (strcmp(op, op_list[i].opcode) == 0)
		{
			op_list[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (op && op_list[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(content);
		free_struct(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
