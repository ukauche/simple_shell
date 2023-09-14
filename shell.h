#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

void error_msg(char *progm, int cnt, char *cmmd);
int put_char(char x);
void putss(char *strng);
extern char **environ;
int execs(char **args, char **argv);
int exit_num;
int exec_s(char **args, char **argv, char *cmmd);
char *path_val(char *path, char *cmmd);
void arr_free(int argc, char *argv[]);
char *dup_path(void);
void check_buf(char *buff);
int built_in(char **args, char *prog, char *buff);
char **tokenize(char *strng);




#endif
