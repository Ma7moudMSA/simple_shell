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
int _strcmp(const char*,const char *);
char *starts_with(const char *, const char *);
char *_strcat(char*, char*);

/**********************************************/
/**               string functions.c        */
/*********************************************/
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/**********************************************/
/**               string functions.c        */
/*********************************************/
char *_atrncpy(char *, char *, int);
char *_atrncat(char *, char *, int);
char *_atrchr(char *, char);

/**********************************************/
/**               string functions.c        */
/*********************************************/
char **strlow(char *, char *);
char **strlow2(char*, char);



#endif
