#include "shell.h"
/**
 * cmpstr - Compares two strings
 * @str1: string to compare n1
 * @str2: string to compare n2
 * Return: Result
 */
int cmpstr(const char *str1, const char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return (0);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
