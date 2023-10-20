#include "sshell.h"
/**
 * split_string - split the input into commands and args
 * @buff: buffer
 * @deli: delimiter
 *
 * Return: string of tokens
 */
char **split_string(char *buff, char *deli)
{
	char **tokkens;
	char *tokken;
	int i = 0;
	int j;

	tokkens = malloc(sizeof(char *) * 1024);
	if (tokkens == NULL)
	{
		free(tokkens);
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	tokken = strtok(buff, deli);
	while (tokken)
	{
		tokkens[i] = strdup(tokken);
		if (tokkens[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		tokken = strtok(NULL, deli);
		i++;
	}
	tokkens[i] = NULL;

	for(j = 0; j < i; j++)
	{
		free(tokkens[j]);
	}
	free(tokkens);
	return (tokkens);
}
