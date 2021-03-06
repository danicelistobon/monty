#include "monty.h"
/**
* op_add - adds the top two elements of the stack
*
* @stack: pointer to head
*
* @line_num: line where the instruction appears
*
* Return: no return
*/
void op_add(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		error_free(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	op_pop(stack, line_num);
	(*stack)->n += temp;
}
/**
* op_nop - doesn't do anything
*
* @stack: pointer to head
*
* @line_num: line where the instruction appears
*
* Return: no return
*/
void op_nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}
/**
* error_free - frees in error case
*
* @stack: pointer to head
*
* Return: no return
*/
void error_free(stack_t *stack)
{
	if (global.line)
	{
		free(global.line);
	}
	if (global.filenm)
	{
		free(global.filenm);
	}
	free(stack);
}
/**
* op_sub - subtracts the top two elements of the stack
*
* @stack: pointer to head
*
* @line_num: line where the instruction appears
*
* Return: no return
*/
void op_sub(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_num);
		error_free(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	op_pop(stack, line_num);
	(*stack)->n -= temp;
}
/**
* op_mul - multiplies the top two elements of the stack
*
* @stack: pointer to head
*
* @line_num: line where the instruction appears
*
* Return: no return
*/
void op_mul(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_num);
		error_free(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	op_pop(stack, line_num);
	(*stack)->n *= temp;
}
