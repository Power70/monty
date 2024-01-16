#include "monty.h"

/**
 * nop - Doesn't do anything
 *
 * @stack: pointer to a pointer, points to the top of the stack
 * @line_number: line number where the opcode is found
 *
 * Return: void (nothing)
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
