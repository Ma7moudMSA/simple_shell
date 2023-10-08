#ifndef SHELL_H
#define SHELL_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/***********************************************/
/*                      hashtags          */
/**********************************************/
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

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
char *_strncat(char *destination, char *source, int *copy_numbers);
char *_strchr(char *source, char c);

/**********************************************/
/**               string functions4.c        */
/*********************************************/
char **strtow(char *d, char *str);
char **strtow2(char *d, char *str);


#endif
