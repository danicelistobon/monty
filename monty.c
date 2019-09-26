#include "monty.h"
global_t global;
/**
* main - main function
*
* @argc: number of things in the command line
*
* @argv: array of string values
*
* Return: EXIT_SUCCESS or EXIT_FAILURE
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read(argv[1]);
	exit(EXIT_SUCCESS);
}
/**
* read - reads user input
*
* @filename: is the path to the file
*
* Return: EXIT_SUCCESS or EXIT_FAILURE
*/
int read(char *filename)
{
	stack_t *stack = NULL;
	size_t size = 0;
	char *tokens = NULL;
	unsigned int line_num = 0;

	if (!filename)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	global.filenm = fopen(filename, "r");

	if (global.filenm == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&global.line, &size, global.filenm) != -1)
	{
		line_num++;

		tokens = strtok(global.line, " \r\n\t");

		if (tokens == NULL)
		{
			continue;
		}
		else
		{
			operations(tokens, &stack, line_num);
		}
	}
	fclose(global.filenm);
	free(global.line);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
/**
* operations - selects the correct option from tokens
*
* @tokens: instruction taken from the user input
*
* @stack: pointer to head
*
* @line_num: line where the instruction appears
*
* Return: no return
*/
void operations(char *tokens, stack_t **stack, unsigned int line_num)
{
	instruction_t ops[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{NULL, NULL}
	};
	unsigned int i = 0;

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(tokens, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_num);
			return;
		}
	}
	if (strlen(tokens) != 0 && tokens[0] != '#')
	{
		printf("L%d: unknown instruction %s\n", line_num, tokens);
		exit(EXIT_FAILURE);
	}
}
/**
* free_stack - frees stack
*
* @stack: pointer to head
*
* Return: no return
*/
void free_stack(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		return;
	}
	while (*stack != NULL)
	{
		temp = (*stack)->next;

		free(*stack);

		if (temp == NULL)
		{
			return;
		}
		temp->prev = NULL;
		*stack = temp;
	}
	free(*stack);
}
