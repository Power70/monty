#include "monty.h"

/**
 * pop_top - removes the top element of the stack
 *
 * @stack: stack top
 * @line_number: line number where opcode is found
 *
 * Return: void (nothing)
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(instance_vars.file);
		free_struct(*stack);
		free(instance_vars.line);

		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = ptr->next;
	free(ptr);
}
