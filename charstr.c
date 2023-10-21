#include "shell.h"
/**
 * chrstr - locates a char
 * @s: string
 * @c: charachter
 * Return: Always 0 (Success)
 */
char *chrstr(const char *s, char c)
{
	/*int i;*/

	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
