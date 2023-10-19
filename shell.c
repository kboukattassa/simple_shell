#include "sshell.h"
/**
 *
 *
 */


/* gets the path and returns it */
char *_getenv(const char *env_var)
{
	extern char **environ; /* evironment vars*/
	int i = 0; /*index*/
	char *key;/*var to search*/

	while (environ[i])
	{
		key = strtok(environ[i], "=");/*to check if the thats the item we looking for*/
		if (strcmp(env_var, key) == 0) /*compares the env var with the key, if its the same*/
			return (strtok(NULL, "\n")); /*if yes, continue*/
		i++;
	}
	return (NULL);/* if env var not founds return null*/
}

/*returns the whole path for the command*/
char *get_cmmd(char *cmmd)
{
	char *path = _getenv("PATH");/*gets the path*/
	char *token;/*look for char by char*/
	char *cmd_full;/*the full path of the command to be returned*/
	struct stat st;/*check if the fun exists or no*/

	if (strchr(cmmd, '/') != NULL)
	{
		return (strdup(cmmd));
	}

	token = strtok(path, ":");/*tokenize the string*/
	while (token)
	{
		cmd_full = malloc(strlen(token) + strlen(cmmd) + 2);/*allocate memory to the command string*/
		strcpy(cmd_full, token);/*copy the token to the path*/
		strcat(cmd_full, "/");/*pate / to the command path*/
		strcat(cmd_full, cmmd);/*paste the command of the user to the command path */
		if (stat(cmd_full, &st) == 0)/*the command path exists or not*/
			return (cmd_full);/*if yes, returns the path*/
		free(cmd_full);/*otherwise frees the command path*/
		token = strtok(NULL, ":");/*continues again*/
	}
	return (NULL);/*in case the command is not found*/
}

/*splits the input into commands & arguments*/
char **split_string(char *buffer, char *del)
{
	char **tokens;/*will hold all the tokens*/
	char *token;/*takes one by one*/
	int i = 0;/*index to traverse all the tokens*/

	tokens = malloc(sizeof(char *) * 1024);/*alloate memory to the tokens*/
	if (tokens == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, del);/*tokenize*/
	while (token)
	{
		tokens[i] = strdup(token);/*will put token in the first index of the array of tokens*/
		if (tokens[i] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, del);/*the new token*/
		i++;
	}
	tokens[i] = NULL;/*finish with null*/
	return (tokens);/*returns tokens*/
}

int main(int ac, char **av, char **env)
{
	char *buffer; /*buffer*/
	size_t buffer_size;/*buffer size*/
	char *cmd; /*command to be stored*/
	char **args;/*arguments*/
	pid_t pid;/*process to be forked*/
	int status, n_chars;

	(void)ac;
	(void)av;

	buffer = NULL;
	buffer_size = 0;

	while (1)
	{
		write(1, "$ ", 2);/*prints the prompt*/
		fflush(stdout);
		n_chars = getline(&buffer, &buffer_size, stdin);/*reads input from user*/
		if (n_chars == -1)
		{
			write(1, "\n", 1);/*write a new line and exits*/
			exit(1);
		}
		buffer[strcspn(buffer, "\n")] = '\0';
		args = split_string(buffer, " \t\n");/*tokenized*/
		pid = fork();/*create child process*/
		if (pid == 0)/*if child process*/
		{
			cmd = get_cmmd(args[0]);/*the command written by the user*/
			if (cmd)/*if command exist, then execute it*/
			{
				execve(cmd, args, env);
			}
			else
			{
				printf("command not found\n");
			}
			exit(0);
		}
		else/*if parent, then wait for child to finish*/
		{
			wait(&status);
		}
		free(args);
	}
	return (0);

}
