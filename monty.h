#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Decription: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct monty_instance - variables needed across multiple file
 *
 * @file: pointer to the monty file
 * @monty_arg: opcode argument
 * @line: the content of the line
 *
 * Description: holds values needed in multiple files of the program
 */
typedef struct monty_instance
{
	FILE *file;
	char *monty_arg;
	char *line;
} monty_inst;

extern monty_inst instance_vars;

int execute(stack_t **stack, unsigned int line_number, char *content,
		FILE *file);
void stack_push(stack_t **stack, unsigned int line_number);
void free_struct(stack_t *head);
void struct_pall(stack_t **top, unsigned int line_number);
void pint_top(stack_t **stack, unsigned int line_number);
void pop_top(stack_t **stack, unsigned int line_number);
void swap_elem(stack_t **stack, unsigned int line_number);
void add_elem(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub_elem(stack_t **stack, unsigned int line_number);
void div_elem(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
