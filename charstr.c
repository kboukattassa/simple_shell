#include "shell.h"
/**
 * chrstr - locates a char
 * @s: string
 * @c: charachter
 * Return: Always 0 (Success)
 */
char *chrstr(char *s, char c)
{
	int i = 0;

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}
