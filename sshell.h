#ifndef _SIMPLE_SHELL_H
#define _SIMPLE_SHELL_H
#define _GNU_SOURCE
/* Header files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Prototypes */
void d_prompt(void);
void read_in(char *cmd, size_t size);
void exe_cmd(const char *cmd);
#endif
