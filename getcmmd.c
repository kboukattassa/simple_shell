#include "shell.h"
/**
 * get_cmmd - gets the full path of the command typed by the user
 * @comm: The command typed by the user
 *
 * Return: full path
 */
char *get_cmmd(char *comm)
{
	char *path = g_envi("PATH");
	char *tokken;
	char *com_ful_path;
	struct stat st;

	if (chrstr(comm, '/') != NULL)
	{
		return (dupstr(comm));
	}

	tokken = strtok(path, ":");
	while (tokken)
	{
		com_ful_path = malloc(len_of_str(tokken) + len_of_str(comm) + 2);
		copy_of_string(com_ful_path, tokken);
		catstr(com_ful_path, "/");
		catstr(com_ful_path, comm);
		if (stat(com_ful_path, &st) == 0)
			return (com_ful_path);
		free(com_ful_path), com_ful_path = NULL;
		tokken = strtok(NULL, ":");
	}
	return (NULL);
}
