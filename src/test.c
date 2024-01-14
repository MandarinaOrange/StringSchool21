#include "sprintf_write.h"

#include  <stdio.h>
#include <string.h>



int main(int argc, char** argv) {
            
               char buffer[200];
               int i, j;
               double fp;
               char *s = "computer";
               char c = '!';
               
         
               
               
            
               /*  форматирует и печатает различные данные */
            
               /*j = sprintf(buffer, "%s\n", s);
               printf("1~~~~~~~%d\n", j);

               j += sprintf(buffer+j, "%c\n", c);
               printf("2~~~~~~~%d\n", j);

               j += sprintf(buffer+j, "%d\n",i);
               printf("3~~~~~~~%d\n", j);

               j += sprintf(buffer+j, "%f\n",fp);
               printf("4~~~~~~~%d\n", j);
               printf("~~~~~~~%s\n\n\n", buffer);

                printf("~~~~~~%c\n", buffer[2]);
                printf("~~~~~~%s\n", buffer);*/


                float a;
                char buff[200];



                while (a != 909) {
                    scanf("%f", &a);
                    printf("number: %f\n", a);

                    for (int i = 0; i < 200; i++) {
                        buff[i] = '\0';
                    }

                    printf("%d symbols\nstring: \"%s\"\n\n", sprintf(buff, "%f", a), buff);

                    for (int i = 0; i < 200; i++) {
                        buff[i] = '\0';
                    }

                    printf("%d symbols\nstring: \"%s\"\n\n", write_double(buff, a, 6), buff);

                }


}