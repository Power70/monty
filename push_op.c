#include "monty.h"

/**
 * stack_push - function that inserts elements into a stack
 *
 * @stack: pointer to a pointer, points to the top of the stack
 * @line_number: the line number where the opcode is found
 *
 * Return: Nothing (void)
 */
void stack_push(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int n, i = 0;
	int flag = 0;

	if (instance_vars.monty_arg != NULL)
	{
		if (instance_vars.monty_arg[0] == '-')
			i++;
		while (instance_vars.monty_arg[i] != '\0')
		{
			if (instance_vars.monty_arg[i] < '0' || instance_vars.monty_arg[i] > '9')
				flag = 1;
			i++;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(instance_vars.file);
			free_struct(*stack), free(instance_vars.line);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(instance_vars.file);
		free_struct(*stack), free(instance_vars.line);
		exit(EXIT_FAILURE);
	}
	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		free(top);
		fprintf(stderr, "Error: malloc failed\n");
	}
	n = atoi(instance_vars.monty_arg);
	if ((*stack) != NULL)
		(*stack)->prev = top;
	top->n = n, top->next = *stack, top->prev = NULL;
	*stack = top;
}
