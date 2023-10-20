#include "sshell.h"
/**
 * len_of_str - returns length of a string
 * @s: para
 * Return: length
 */
int len_of_str(char *s)
{
	int lstr;

	while (s[lstr])
		lstr++;
	return (lstr);
}
