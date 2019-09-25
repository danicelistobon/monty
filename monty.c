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
