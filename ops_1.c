#include "monty.h"
/**
* op_push - pushes an element to the stack
*
* @stack: pointer to head
*
* @line_num: line where the instruction appears
*
* Return: no return
*/
void op_push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	char *token = NULL;
	int num = 0, i = 0;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		error_free(*stack);
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " \r\n\t");
	if (token == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		error_free(*stack);
		free(new_node);
		exit(EXIT_FAILURE);
	}
	i = strlen(token);

	if (i--)
	{
		if (token[i] < 48 || token[i] > 57)
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_num);
			error_free(*stack);
			free(new_node);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(token);
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (new_node->next != NULL)
	{
		(new_node->next)->prev = new_node;
	}
	*stack = new_node;
}
/**
* op_pall - prints all the values on the stack, starting from the top
*
* @stack: pointer to head
*
* @line_num: line where the instruction appears (unused)
*
* Return: no return
*/
void op_pall(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
	stack_t *nodes = *stack;

	while (nodes != NULL)
	{
		printf("%d\n", nodes->n);
		nodes = nodes->next;
	}
}
/**
* op_pint - prints the value at the top of the stack
*
* @stack: pointer to head
*
* @line_num: line where the instruction appears
*
* Return: no return
*/
void op_pint(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		error_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
* op_pop - removes the top element of the stack
*
* @stack: pointer to head
*
* @line_num: line where the instruction appears
*
* Return: no return
*/
void op_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		error_free(*stack);
		exit(EXIT_FAILURE);
	}
	node  = *stack;
	(*stack) = (*stack)->next;
	free(node);
}
/**
* op_swap - swaps the top two elements of the stack
*
* @stack: pointer to head
*
* @line_num: line where the instruction appears (unused)
*
* Return: no return
*/
void op_swap(stack_t **stack, unsigned int line_num __attribute__((unused)))
{
	stack_t *temp;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		error_free(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = temp->next;
	temp->prev = NULL;
	(*stack)->prev = temp;

	if (temp->next)
	{
		temp->next->prev = *stack;
	}
	temp->next = *stack;
	(*stack) = (*stack)->prev;
}
