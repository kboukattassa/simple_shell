#include "shell.h"
/**
 * split_string - split the input into commands and args
 * @buff: buffer
 * @deli: delimiter
 *
 * Return: string of tokens
 */
char **split_string(char *buff, char *deli)
{
	char **tokkens = NULL;
	char *tokken = NULL, *temp = NULL;
	int i = 0, count = 0;

	if (!buff)
		return (NULL);
	temp = dupstr(buff);
	tokken = strtok(temp, deli);
	while (tokken)
	{
		count++;
		tokken = strtok(NULL, deli);
	}
	free(temp), temp = NULL;

	tokkens = malloc(sizeof(char *) * (count + 1));
	if (!tokkens)
	{
		free(buff);
		return (NULL);
	}
	tokken = strtok(buff, deli);
	while (tokken)
	{
		tokkens[i] = dupstr(tokken);
		if (tokkens[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		tokken = strtok(NULL, deli);
		i++;
	}
	free(buff), buff = NULL;
	tokkens[i] = NULL;
	return (tokkens);
}
