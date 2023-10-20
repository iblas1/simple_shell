#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_INPUT_LENGTH 64
#define MAX_LENGTH 1024

extern char **environ;
char *m_environ();
char *get_location(char *command);
int execmd(char *command, char **args);
void print_string(char *str);
void print_error(char *str);
void show_shell_name(void);
int start_shell(char **env, char **aargv);
char *location(char *path, char *arg);
char *get_location(char *arg);
void exit_cmd(char *buffer, char *buffer_copy);
void cd_cmd(int argc, char **argv);
void print_env(char **env);
char *get_path(char **argv_copy);
char *my_strtok(char *string, const char *delimeter);
void exec_cmd(char **argv_c, char *buf, char *buf_c, char **env, char **argv);
void special_cmd(char **argv_c, char *buf, char *buf_cpy, char **env);
void exit_with_ctrl_D(ssize_t char_count, char *buffer);
ssize_t my_getline(char **buffer, size_t *buffer_size, FILE *input);
char *path_process(char *path, char *command);

int _strncmp(char *str1, char *str2, size_t n);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
void _puts(char *str);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
char *str_cpy(char *dest, char *src);
int _strlen(char *s);

#endif /*MAIN_H*/
