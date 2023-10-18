#ifndef SHELL_H
#define SHELL_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/**
* struct lstr - struct namee
* @num: field number
* @str: string
* @next: linked list
*/

typedef struct lstr
{
	int num;
	char *str;
	struct lstr *next;
} l_t;

/**
* struct passinfo - arguments to be passed
* @arg: string arg
* @argv: array of strings
* @path: path of string command
* @argc: counter
* @count_line: errors
* @err: error for exit
* @count_line_flag: if input count
* @fname: program file name
* @env: linked list copy of environ
* @environ: modified copy of environ
* @his: node of history
* @alias: node of alias
* @enviroment_change: on of change in environ
* @status: status of exec command
* @ptr_buf_cmd: pointer of buf cmd of chain
* @readfd:  fd to read line input
* @type_cmd_buf: || && ;
* @histcount: number count
*/

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int count_line;
	int err;
	int count_line_flag;
	char *fname;
	l_t *env;
	l_t *his;
	l_t *alias;
	char **environ;
	int enviroment_change;
	int status;

	char **ptr_buf_cmd;
	int type_cmd_buf;
	int readfd;
	int histcount;
} info_t;


/***********************************************/
/*                      hashtags          */
/**********************************************/
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define INPUT_BUF_SIZE 1024

#define HIST_FILE  ".simple_shell_history"
#define HIST_MAX 4096

extern char **environ;
/**********************************************/
/**               string functions.c        */
/*********************************************/
int _strlen(const char *str);
int _strcmp(const char*, const char *);
char *starts_with(const char *, const char *);
char *_strcat(char*, char*);

/**********************************************/
/**               string functions2.c        */
/*********************************************/
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/**********************************************/
/**               string functions3.c        */
/*********************************************/
char *_strncpy(char *destination, const char *source, int copy_numbers);
char *_strncat(char *destination, char *source, int copy_numbers);
char *_strchr(char *source, char c);

/**********************************************/
/**               string functions4.c        */
/*********************************************/
char **strtow(char *d, char *str);
char **strtow2(char *d, char *str);

/***********************************************/
/*                      info.c          */
/**********************************************/
void clear_info(info_t *info);
void set_info(info_t *info, char **av);
void free_info(info_t *info, int all);

/***********************************************/
/*                      env                   */
/**********************************************/
int _setenv(info_t *info, char *var, char *value);
int _unsetenv(info_t *info, char *var);
char **get_environ(info_t *info);
int populate_env(info_t *info);
int _myunsetenv(info_t *info);
int _mysetenv(info_t *info);
char *_getenv(info_t *info, const char *name);
int _myenv(info_t *info);

/***********************************************/
/*                      file_io_functions      */
/**********************************************/
char *get_history_file(info_t *info);
int write_history_file(info_t *info);
int read_history_file(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/***************Memory**************/
char *_memset(char*, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/**************atoi_isdelim_interactive_*******/
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

int _help(info_t *info);
int _mycurrentdir(info_t *info);
int _myex(info_t *info);


int _myhist(info_t *inf);
int unsetalias(info_t *info, char *str);
int s_alias(info_t *info, char *str);
int p_alias(l_t *node);
int _myalias(info_t *info);

char *find_path(info_t *, char *, char *);
char *duplicatechars(char *, int , int );
int iscmd(info_t *, char *);

int ischaining(info_t *, char *, size_t *);
void checkforchain(info_t *info, char *, size_t , size_t , size_t );
int replaceAlias(info_t *info);
int replacing_vars(info_t *info);
int replacingStrings(char **o, char *n);

l_t *add_node(l_t **head, const char *str, int num);
l_t *add_node_end(l_t **head, const shar *str, int num);
size_t p_list_str(const l_t *head);
int delete_node_i(l_t **head, unsigned int i);
void free_list(l_t **head);


#endif
