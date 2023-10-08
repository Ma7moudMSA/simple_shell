#ifndef SHELL_H
#define SHELL_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**********************************************/
/**               string functions.c        */
/*********************************************/
int _strlen(char *str);
int _strcmp(char*, char *);
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
