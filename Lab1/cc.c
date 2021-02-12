// changing case Lab 1

#include <stdio.h>

void main(void){
    char input = 0;
    char c = 0;

    while (input != '\n'){
        input = getchar();

        if (input >= 'a' && input <= 'z')
            input = (input - 'a') + 'A';
        else if (input >= 'A' && input <= 'Z')
            input = (input -'A') + 'a';
        printf("%c", input);
    }

}