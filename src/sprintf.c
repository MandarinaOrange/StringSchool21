#include "sprintf.h"

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void record_arg(const char **format, char **str, struct Flags *flags, va_list vl) {






}

void Obnull(struct Flags *flags) {
  flags->length_h = 0;
  flags->length_l = 0;
  flags->minus = 0;
  flags->plus = 0;
  flags->precision = 0;
  flags->space = 0;
  flags->width = 0;
  flags->is_precision = 0;
}




int s21_sprintf(char *buf, const char *format, ...) {
  int result;

  va_list nachalo;
  va_start(nachalo, format);



  return result;
}

int parsing (const char **format, struct Flags *flags) {
  int flag_pars = 0;

  while (**format) {

    if (format == '-') {
      flags->minus = 1;
    } else if (**format == '+') {
      flags->plus = 1;
    } else if (**format == ' ') {
      flags->space = 1;
    }

    else if (**format == 'h') {
      flags->length_h = 1;
    } else if (**format == 'l') {
      flags->length_l = 1;
    }

//перебор длины символов
    else if (IsDigit(**format)) {
      while (IsDigit(**format)) {
        flags->width = (flags->width) * 10 + (**format - '0');
        (*format)++;
      }
    }
    
 //перебор точности для дробей   
    else if (**format == '.') {
      flags->is_precision = 1;
      (*format)++;
      while (IsDigit(**format)) {
        flags->precision = (flags->precision) * 10 + (**format - '0');
        (*format)++;
      }
    }

    else if (IsSpecifier(**format) == ON) {
      flag_pars = 1;
      break;
    }

    else {
      flag_pars = 0;
      break;
    }
  }

  return flag_pars;
}


int IsDigit(char c) {
  if (c >= '0' && c <= '9') return ON;
 else return OFF;
}

int IsSpecifier (char c) {
  if (ch == 'd' || ch == 'i' || ch == 'c' || ch == 'f' || ch == 's' || ch == 'u' || ch == '%') {
    return ON;
  }
  return OFF;
}