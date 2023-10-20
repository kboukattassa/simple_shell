#include "sshell.h"
/**
 * brint - prints message
 * @message: Message to be printed
 * Return: result
 */
void brint(char *message)
{
	write(STDOUT_FILENO, message, len_of_str(message));
}
