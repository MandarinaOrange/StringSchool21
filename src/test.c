#include  <stdio.h>
#include <string.h>

int main() {
            
               char buffer[200];
               int i, j;
               double fp;
               char *s = "computer";
               char c = '!';
               
         
               
               
            
               /*  форматирует и печатает различные данные */
            
               j = sprintf(buffer, "%s\n", s);
               printf("1~~~~~~~%d\n", j);

               j += sprintf(buffer+j, "%c\n", c);
               printf("2~~~~~~~%d\n", j);

               j += sprintf(buffer+j, "%d\n",i);
               printf("3~~~~~~~%d\n", j);

               j += sprintf(buffer+j, "%f\n",fp);
               printf("4~~~~~~~%d\n", j);
               printf("~~~~~~~%s\n\n\n", buffer);

                printf("~~~~~~%c\n", buffer[8]);
                printf("~~~~~~%d\n", buffer[8]);
}