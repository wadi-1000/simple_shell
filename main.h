#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <error.h>


void prompt(void);
int _putchar(char c);
char **tokenize_input(char *input);
void free_tokens(char **tokens);
void exec_input(char *argv[]);
size_t input_length;
void free_token(char **token);
void exec_exit(char *argv[]);
void exec_env(char *argv[]);

extern char **environ;
#endif
