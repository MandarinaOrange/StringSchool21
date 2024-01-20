#ifndef SPRINTF_H
#define SPRINTF_H


#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include <string.h> //!!!!!!!!!!

#define BUFF 1024

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


typedef long unsigned s21_size_t;



void double_to_string(long double number, char *result, flags f);
void obnull(char *buffer);

int is_digit(char c);
int s21_sprintf(char *str, const char *format, ...);
const char *get_flags(const char *format, flags *f);


const char *get_width(const char *format, flags *f, va_list va);
const char *get_precision(const char *format, flags *f, va_list va);
const char *get_length(const char *format, flags *f);



void num_to_string(int64_t val, char *ret, int base);
void unum_to_string(uint64_t val, char *ret, int base);
void format_precision(char *buffer, flags f);
int int_flags(char c);



void writing(flags f, char *buffer, va_list va);
void parse_uint(flags f, char *buffer, va_list va);
void parse_int(flags f, char *buffer, va_list va);




void parse_char(flags f, char *buffer, va_list va);
void format_wchar(flags f, char *buffer, wchar_t w_c);
void format_char(flags f, char *buffer, char c);
void parse_string(flags f, char *buffer, va_list va);
void format_string(flags f, char *buffer, char *str);
void format_wide_string(flags f, char *buffer, wchar_t *wstr);












#endif