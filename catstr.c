#include "sshell.h"
/**
 * catstr - Concatenates two strs
 * @dest: Destination
 * @src: Source
 * Return: Result
 */
char *catstr(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
