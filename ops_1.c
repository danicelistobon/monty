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
	int num = 0;

	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(NULL, " \r\n\t");

	if (token == NULL || stack == NULL)
	{
		printf("L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
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
