#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}
/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;
void betty_test(void);
/* Lists */
list_t *add_node_e(list_t **head, const char *str, int num);
int delete_node_at_index(list_t **head, unsigned int index);
void free_l(list_t **head);
size_t list_len(const list_t *h);
char **list_to_str(list_t *head);
size_t print_list(const list_t *h);
list_t *node_starts(list_t *node, char *prefix, char c);
ssize_t get_node_index(list_t *head, list_t *node);
int pfree(void **ptr);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(info_t *info, char *pathstr, char *cmd);
/* Memory Helper */
char *_memset(char *s, char b, unsigned int n);
void ffree(char **pp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/* Strings */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *starts_with(const char *haystack, const char *needle);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);
char *_strchr(char *, char);
/* Numbers */
char *convert_number(long int, int, int);
/* cmd */
int check_cmd(info_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(info_t *info, char *pathstr, char *cmd);
void fork_cmd(info_t *info);
void find_cmd(info_t *info);
int find_builtin(info_t *info);
int hsh(info_t *info, char **av);
/* Strings Utils */
char **custom_strtow2(char *str, char d);
char **custom_strtow(char *str, char *d);
int replace_string(char **old, char *new);
int replace_env_vars(info_t *info);
int replace_cmd_alias(info_t *info);
void check_chain_status(info_t *info, char *buf, size_t *p, size_t i, size_t len);
int is_chain_delimiter(info_t *info, char *buf, size_t *p);
int is_delim(char ch, const char *delimiters);
/* Environ */
int _myenv(info_t *info);
char *_getenv(info_t *info, const char *name);
int _mysetenv(info_t *info);
int _myunsetenv(info_t *info);
int populate_env_list(info_t *info);
#endif /* SHELL_H */
