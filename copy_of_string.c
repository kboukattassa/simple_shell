#include "sshell.h"
/**
 * copy_of_string - copies string
 * @dest: Destination to copy into
 * @src: Source to copy from
 * Return: string
 */
char *copy_of_string(char *dest, char *src)
{
	int strc;

	for (strc = 0; strc <= len_of_str(src); strc++)
		dest[strc] = src[strc];
	return (dest);
}
