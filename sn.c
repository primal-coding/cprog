// summing numbers Lab 1

#include <stdio.h>

void main(void){
    char input = 0;
    int digit = 0;
    int sum = 0;

    while (input != '\n'){
        input = getchar();
        if (input == ','){
            sum += digit;
            digit = 0;
        }
        if (input >= '0' && input <= '9')
            digit = (digit * 10) + input - '0';
    }
    sum += digit;
    printf ("Total = %d\n",sum);
}