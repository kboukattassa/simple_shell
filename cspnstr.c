#include "sshell.h"
/**
 * cspnstr - iterates through two stirngs
 * @s: string
 * @reject: string to reject
 * Return: count
 */
size_t cspnstr(const char *s, const char *reject)
{
	const char *p = s;
	size_t count = 0;

	while (*p)
	{
		const char *q = reject;

		while (*q)
		{
			if (*p == *q)
				return (count);
			++q;
		}
		++p;
		++count;
	}
	return (count);
}
