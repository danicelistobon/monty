#ifndef _MONTY_
#define _MONTY_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
* struct global_s - global structure
* @line: pointer
* @filenm: pointer
*/
typedef struct global_s
{
	char *line;
	FILE *filenm;
} global_t;

extern global_t global;

int read(char *filename);
void free_stack(stack_t **stack);
void error_free(stack_t *stack);
void operations(char *tokens, stack_t **stack, unsigned int line_num);
void op_push(stack_t **stack, unsigned int line_num);
void op_pall(stack_t **stack, unsigned int line_num __attribute__((unused)));
void op_pint(stack_t **stack, unsigned int line_num);
void op_pop(stack_t **stack, unsigned int line_num);
void op_swap(stack_t **stack, unsigned int line_num __attribute__((unused)));
void op_add(stack_t **stack, unsigned int line_num);
void op_nop(stack_t **stack, unsigned int line_num);
void op_sub(stack_t **stack, unsigned int line_num);
void op_div(stack_t **stack, unsigned int line_num);
void op_mul(stack_t **stack, unsigned int line_num);
void op_mod(stack_t **stack, unsigned int line_num);
void op_pchar(stack_t **stack, unsigned int line_num);
void op_pstr(stack_t **stack, unsigned int line_num __attribute__((unused)));

#endif
