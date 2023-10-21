#include "shell.h"
/**
 * dupstr - duplicates a string
 * @str: String to be copied
 * Return: Result
 */
char *dupstr(char *str)
{
	char *cpy;
	int len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	cpy = malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
		return (NULL);
	len = 0;
	while (str[len])
	{
		cpy[len] = str[len];
		len++;
	}
	cpy[len] = '\0';
	return (cpy);
}
