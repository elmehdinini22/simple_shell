#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

void betty_test(void);
unsigned int check_delim(char c, const char *str);
char *_strtok(char *str, const char *delim);
char *_getline();
void hashtag_h(char *buff);
int _strlen(char *str);
void print_environment(void);
int check_c(int readBytes);
void _execute(void);
/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* handle built ins */
int checker(char **cmd, char *buf);
void propt_user(void);
void handle_signal(int m);
char **token(char *line);
char *testa_path(char **path, char *command);
char *append_path(char *path, char *command);
void exit_ccmd(char **command, char *line);

void print_env(void);

/* string handlers */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);

void execution(char *cp, char **cmd);
char *find_path(void);

/* helper function for efficient free */
void free_function(char **buf);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

#endif /* SHELL_H */
