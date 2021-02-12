// strings to digit from Lab 1

#include <stdio.h>

void main(void){
    char input = 0;
    int sum = 0;

    while (input != '\n'){
        input = getchar();

        if (input >= '0' && input <= '9'){
            input = input - '0';
            sum = sum * 10;
            sum += input;
        }
    }
    sum++;
    printf("%d\n", sum);
}