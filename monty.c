#include "monty.h"
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
	FILE *file;
	char *line = NULL;
	size_t size = 0;
	char *tokens = NULL;
	unsigned int line_num = 0;

	if (!filename)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, file) != -1)
	{
		line_num++;

		tokens = strtok(line, " \r\n\t");

		if (tokens == NULL)
		{
			continue;
		}
		else
		{
			operations(tokens, &stack, line_num);
		}
	}
	fclose(file);
	free(line);
	free_stack(&stack);
	return (EXIT_SUCCESS);
}
