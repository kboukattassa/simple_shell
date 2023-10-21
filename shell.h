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
#include <stddef.h>
extern char **environ;

/* Prototypes */
char *g_envi(const char *ev_varia);
char *get_cmmd(char *comm);
char **split_string(char *buff, char *deli);
void brint(char *message);
char *catstr(char *dest, char *src);
char *chrstr(char *s, char c);
int cmpstr(const char *str1, const char *str2);
char *copy_of_string(char *dest, char *src);
size_t cspnstr(const char *s, const char *reject);
char *dupstr(char *str);
char *get_cmmd(char *comm);
char *g_envi(const char *ev_varia);
int len_of_str(char *s);
#endif
