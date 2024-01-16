#include "monty.h"

/**
 * struct_pall - function that prints all the values on the stack,
 * starting from the top of the stack.
 *
 * @top: pointer to a pointer, pointing to the top of the stack
 * @line_number: number of file lines counted (not used)
 *
 * Return: nothing (void)
 */
void struct_pall(stack_t **top, unsigned int line_number)
{
	stack_t *ptr;
	(void)line_number;

	ptr = *top;

	if (*top == NULL)
		return;
	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
