#include "monty.h"
/**
* op_div - divides the top two elements of the stack
*
* @stack: pointer to head
*
* @line_num: line where the instruction appears
*
* Return: no return
*/
void op_div(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_num);
		error_free(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;

	if (temp == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		error_free(*stack);
		exit(EXIT_FAILURE);
	}
	op_pop(stack, line_num);
	(*stack)->n /= temp;
}
/**
* op_mod - computes the rest of the division of the top two elements stack
*
* @stack: pointer to head
*
* @line_num: line where the instruction appears
*
* Return: no return
*/
void op_mod(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_num);
		error_free(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;

	if (temp == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_num);
		error_free(*stack);
		exit(EXIT_FAILURE);
	}
	op_pop(stack, line_num);
	(*stack)->n %= temp;
}
/**
* op_pchar - prints the char at the top of the stack
*
* @stack: pointer to head
*
* @line_num: line where the instruction appears
*
* Return: no return
*/
void op_pchar(stack_t **stack, unsigned int line_num)
{
	int i;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;

	if (!(i >= 0 && i <= 127))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
	putchar(i);
	putchar('\n');
}
/**
* op_pstr - prints the string starting at the top of the stack
*
* @stack: pointer to head
*
* @line_num: line where the instruction appears (unused)
*
* Return: no return
*/
void op_pstr(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp != NULL)
	{
		if (isascii(tmp->n) && tmp->n != 0)
		{
			putchar(tmp->n);
		}
		else
		{
			break;
		}
		tmp = tmp->next;
	}
	putchar('\n');
}
