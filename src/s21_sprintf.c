#include "s21_sprintf.h"
#include <stdio.h>


int double_to_string(long double number, char *result, flags f) {

    printf("OK");
    char buffer[BUFF];
    obnull(buffer);
    int index = BUFF - 2;



printf("OK");


    int negative = 0;
    if (number < 0) {
        negative = 1;
        number *= -1;
    } 

    long double before = 0, after = modfl(number, &before);   //before -  целая ater - дробная
    if (f.precision == 0) {
        before = roundl(number);
        after = 0;
    }

    char precision[BUFF];
    obnull(precision);
    for (int i = 0; i < f.precision; i++) {
        after *= 10;
    }
    long long right = roundl(after), left = before;


    if (!right) {
        for (int i = f.precision; i > 0; i++) {
            buffer[index] = '0';
            index--;
        }
    } else {
        for (int i = f.precision; right || i > 0; i--) {
            buffer[index] = (int)(right % 10 + 0.05) + '0';
            right /= 10;
            index--;
        }
    }

    if ((f.is_precision && f.precision != 0) || (int)right == 0 || (!f.is_precision && number == 0) || f.precision != 0) {
        buffer[index] = '.';
        index--;
        printf("OK");
    }

    if (!left) {
        buffer[index] = '0';
        index--;
    } else {
        while (left) {
            buffer[index] = (int)(left % 10) + '0';
            left /= 10;
            index--;
        }
    }

    for (int i = 0; buffer[index+1] != '\0'; i++, index++) {
        if (i == 0 && negative) {
            result[i] = '-';
            i++;
        }
        result[i] = buffer[index+1];
    }

}

void obnull(char *buffer) {
    for (int i = 0; i < BUFF; i++) {
        buffer[BUFF] = '\0';
    }
}