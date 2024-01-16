#include "monty.h"

/**
 * swap_elem - swaps the top two elements of the stack
 *
 * @stack: pointer to a pointer, points to the top of the stack
 * @line_number: the line number where opcode is found
 *
 * Return: void (nothing)
 */
void swap_elem(stack_t **stack, unsigned int line_number)
{
	int count = 0;
	int tmp;
	stack_t *ptr;

	ptr = *stack;

	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(instance_vars.file);
		free_struct(*stack);
		free(instance_vars.line);
		exit(EXIT_FAILURE);
	}

	ptr = *stack;
	tmp = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = tmp;
}
