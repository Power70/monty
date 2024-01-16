#include "monty.h"

/**
 * pint_top - function that prints the value at the top of the stack
 * followed by a new line
 *
 * @stack: pointer to a pointer, points to the top of the stack
 * @line_number: the line number where the opcode is found
 *
 * Return: void (nothing)
 */
void pint_top(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(instance_vars.file);
		free_struct(*stack);
		free(instance_vars.line);

		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}
