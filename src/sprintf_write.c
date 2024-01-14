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
        //printf("int buff: %d\n", buff);

    if (number < 0) {
        buf[0] = '-';
        number *= (-1);
        for (int i = 0; i < result-1; i++) {
            buf[result-1-i] = (buff % 10) + '0';
            number /= 10;
        }
    } else {
        for (int i = 0; i < result; i++) {
            buf[result-1-i] = (buff % 10) + '0';
            buff /= 10;
        }
    }

    printf("строка без дробной части: %s\n", buf);



    buf[result] = '.';
    buff = number / 1;
    double bufff = number - buff * 1.0;
    buff = 1000000 * bufff;
    printf("int buff: %lf\n", bufff);

    for (int i = 0; i < precision; i++) {
        buf[result+1+i] = buff / pow(10, 5-i) + '0';
        buff = buff % (int)pow(10, 5-i);
    }

    result += (1+precision);


    return result;



}