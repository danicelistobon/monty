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
		printf("L%u: can't add, stack too short\n", line_num);
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
