#include "sprintf_write.h"

#include <stdio.h>
#include <math.h>

int count_integer(int number) {
    int count = (number == 0);
    if (number < 0) {
        count++;
        number *= (-1);
    }
    while (number > 0) {
        number /= 10;
        count++;
    }
    return count;
}

int write_integer(char* buf, int number) {
    int result = count_integer(number);
    if (number < 0) {
        buf[0] = '-';
        number *= (-1);
        for (int i = 0; i < result-1; i++) {
            buf[result-1-i] = (number % 10) + '0';
            number /= 10;
        }
    } else {
        for (int i = 0; i < result; i++) {
            buf[result-1-i] = (number % 10) + '0';
            number /= 10;
        }
    }

    return result;

}


int count_double(double number) {
    int count = 7;

    if (number < 0) {
        count++;
        number *= (-1);
    }


    int buff = number / 1;
    count += (number == 0);
    while (buff > 0) {
        buff /= 10;
        (count) += 1;
    }

    return count;
}

int write_double(char* buf, double number, int precision) {
    int result = count_double(number) - 7;
    int buff = number / 1;

    if (number < 0) {
        buf[0] = '-';
        number *= (-1);
        buff *= (-1);
        for (int i = 0; i < result-1; i++) {
            buf[result-1-i] = (buff % 10) + '0';
            buff /= 10;
        }
    } else {
        for (int i = 0; i < result; i++) {
            buf[result-1-i] = (buff % 10) + '0';
            buff /= 10;
        }
    }

    printf("число внутри функции: %f\n", number);
    printf("строка без дробной части: %s\n", buf);



    buf[result] = '.';
    buff = number / 1;
    double bufff = number - buff * 1.0;
    //bufff = 10 * bufff / 0.00001;
    //buff = 100000 * bufff;
    printf("дробная часть: %f\n", bufff);
    //printf("дробная часть умноженная: %d\n", buff);

    for (int i = 1; i < precision+1; i++) {
        double k = bufff / pow(0.1, i);
        printf("~%lf~", k);
        //buf[result+1+i] = (bufff / pow(0.1, i)) + '0';
        //printf("~%c~", buf[result+1+i]);
        //bufff = bufff - pow(0.1, i) * (buf[result+1+i] + '0');
    }

    /*for (int i = 0; i < precision; i++) {
        buf[result+1+i] = buff / pow(10, 5-i) + '0';
        buff = buff % (int)pow(10, 5-i);
    }*/

    result += (1+precision);


    return result;

}

int CifraPosleZpt(double *number, int razrad) {
   
    double a = pow(0.1, razrad);
    printf("!!!%lf, ", a);
    int buf = *number / 1;
    *number = *number - buf;
    printf("%lf\n", *number);
    int result = 0;
    while (a <= *number) {
        *number -= a;
        result++;
    }
    return result;

}