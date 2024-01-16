#include "monty.h"

/**
 * add_elem - function that adds the top two elements of the stack
 * the result is stored in the second top element of the stack and
 * the top element is removed, so that at the end:
 * the top element of the stack contains the result
 * the stack is one element shorter
 *
 * @stack: pointer to a pointer, points to the top of the stack
 * @line_number: line number where opcode is found
 *
 * Return: void (nothing)
 */
void add_elem(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;
	int temp;
	int count = 0;

	ptr = *stack;

	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}

	if (count < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(instance_vars.file);
		free_struct(*stack);
		free(instance_vars.line);

		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	temp = (ptr->n) + (ptr->next->n);
	ptr->next->n = temp;
	*stack = ptr->next;

	free(ptr);
}
