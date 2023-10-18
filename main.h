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

void prompt(char **env);
int _putchar(char c);
char **tokenize_input(char *input);
void free_tokens(char **tokens);
void exec_input(char *argv[], char *envp[]);
size_t input_length;
void free_token(char **token);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *s);
size_t _strlen(const char *s);
void _strcpy(char *dest, const char *src);
int _isatty(int fd);

#endif
