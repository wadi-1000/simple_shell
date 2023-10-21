#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <error.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <time.h>
#include <stdarg.h>

void ctrl_d(int signa);

extern char **environ;

int _putchar(char c);
void prompt(void);
int _printf(char *s);
void input(char *cmd, size_t size);
void exec_input(char *cp, char **cmd);
void free_buf(char **buf);
char *a_p(char *path, char *command);
int _strngcmp(char *s1, char *s2, int n);
int cmd_check(char **cmd, char *buf);
void mode_handler(int s);
char **parse_args(char *cmd);
char *printerror(void);
int stricmp(char *s1, char *s2);
char **tokenize_input(char *cmd);
int _strlen(char *s);
void exec_env(void);
int handle_builtins(char **cmd, char *command);
void exec_exit(char **cmd, char *command);
char *_strdup(char *s);
char *_strchr(char *s, char c);
char *check_path(char **path, char *cmd);
char *get_path(void);
int my_strcmp(const char *s1, const char *s2);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *my_strtok(char *str, char *delimiters);
void _strcpy(char *dest, const char *src);
void exec_unsetenv(char **cmd, char *command);
void exec_setenv(char **cmd, char *command);
int _setenv(const char *name, const char *value, int overwrite);
int _fprintf(FILE *stream, const char *format, ...);
int _strcmp(const char *s1, const char *s2);
char *_getenv(char *name);


/**
 * struct m_handler - handle modes of the shell
 * @active: mode
 */
struct m_handler
{
	bool active;
} m_handler;

/**
 * struct builtins - builtin commands of the shell
 * @env: prints environment varibales
 * @exit: exits th shell
 * @setenv: intializes a new environment variable
 * @cd: changes directory
 * @unsetenv: removes an environment variable
 *
 */
struct builtins
{
	char *env;
	char *exit;
	char *setenv;
	char *cd;
	char *unsetenv;
} builtins;

/**
 * struct cond - current shell condition
 * @done: done with command and exits shell
 * @count: counts arguments in command
 */
struct cond
{
	int done;
	int count;
} cond;

#endif
