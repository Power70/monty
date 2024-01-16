#include "monty.h"

/**
 * sub_elem - subtracts the top element of the stack from the second
 * top element of the stack
 *
 * @stack: pointer to a pointer, points to the top of the stack;
 * @line_number: line number where opcode is found
 *
 * Return: Nothing (void)
 */
void sub_elem(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(instance_vars.file);
		free_struct(*stack);
		free(instance_vars.line);

		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	temp = (ptr->next->n) - (ptr->n);
	ptr->next->n = temp;
	*stack = ptr->next;

	free(ptr);
}


/**
 * div_elem - divides the second top element of the stack by the
 * top element of the stack
 *
 * @stack: pointer to the top of the stack
 * @line_number: line number where opcode is found
 *
 * Return: Nothing (void)
 */
void div_elem(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(instance_vars.file);
		free_struct(*stack);
		free(instance_vars.line);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;

	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(instance_vars.file);
		free_struct(*stack);
		free(instance_vars.line);
		exit(EXIT_FAILURE);
	}
	temp = (ptr->next->n) / (ptr->n);
	ptr->next->n = temp;
	*stack = ptr->next;

	free(ptr);
}
