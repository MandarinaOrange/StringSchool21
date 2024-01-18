#ifndef SPRINTF_H
#define SPRINTF_H


#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include <string.h> //!!!!!!!!!!

#define BUFF 2000

typedef struct {
  int minus;
  int plus;
  int space;
  int precision;
  int is_precision;
  int width;
  char length;
  char specificator;
} flags;



int double_to_string(long double number, char *result, flags f);
void obnull(char *buffer);
















#endif