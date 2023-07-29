#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

char *line_getter(void);
char **_tokenizer(char *line);
int _execute(char **args, char **dirs);
char **extract_dirs(char **envp);

int run_fork(char **args, char **dirs);
int execute_cmd(char **args, char **drs);

int _cd(char **args);
int _help(void);
int execute_exit(void);

int _puts(char *str);
int _strlen(char *str);
int cmd_size(char *str, char delim);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *s1, char *s2);
char *_strncat(char *s1, char *s2, int n);
char *_strchr(char *str, char c);

void ctrlc_handler(__attribute__((unused)) int n);

#endif
