#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* read/write buffers*/
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/*commanf chaining*/
#define CMD_NORM     0
#define CMD_OR       1
#define CMD_AND      2
#define CMD_XHAIN    3

/*convert_number()*/
#define CONVERT_LOWERCASE  1
#define CONVERT_UNSIGNED   2

/* 1 if using system getline*/
#define USE_GETLINE  ".simple_shell_history"
#define HIST_MAX        4096
extern char **environ;
/**
 * struct liststr - singly linked list
 * @num: the number fieled
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr;
*next;
} list_t;
/**
 * struct passinfo - contains pseudo arguements to pass into a function
 * allowing uniform protoype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv: an array of strings generated from arg
 * @histcount: the history line number count
 * @path: a string path for  the  current command
 * @readfd: the fd from which to read line input
 * @argc: the argument count
 * env_changed: on if environ was changed
 * @line_count: the error count
 * @status: the return stus of the last execd command
 * @err_rum: the error code for exit()
 * @cmd_buf: address of pointer to cmd_buf
 * @cmd_buf_type: CMD_type ||,&&,;
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @alias: the alias node
 * @history: the history node
 * @environ: custom modified copy of environ from LL env
 * @env: linked list local copy of environ
 */
typedef struct passinfo
{
	char **cmd_buf;
	int cmd_buf_type;
	int resdfd;
	int histcount;
	char *arg;
	char **argv;
	char *path;
	int argc;
	int status;
	int env_changed;
	char **eviron;
	list_t *env;
	list_t *history;
	list_t *alias;
	unsigned int line_count;
	int err_num;
	int linecount_flog;
	char *env;
} info_t;
#define INFO_INT\
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t*);
} builtin_table;
/*string_fun*/
int _len(char *s);
int _cmp(char *s1, char *s2);
char *_with(const char *haystack, const char *needle);
char *_cat(char *dest, char *src);
/*string*/
char *_cpy(char *dest, char *src);
char *_dup(const char *str);
void _puts(char *str);
int _putchar(char c);
/*string1.c*/
char *_stcpy(char *dest, char *src, int n);
char *_stcat(char *dest, char *src, int n);
char *_stchr(char *s, char c);
/*string2*/
char **strtow(char *str, char *d);
char **strto(char *str, char d);
/*memory_func*/
char *_mems(char *s, char b, unsigned int n);
void fre(char *p);
void *_lloc(void  **ptr, unsigned int old, unsigned int new_s);
/*memory_func2*/
int bfree(void **ptr);
/* more1*/
int _erratoi(char *s);
void print_error(info_t *info, char *estr);
int print_d(int input, int fd);
char *convert_number(long int num, int base, int flags);
void remove_comments(char *buf);
/*more*/
#endif
