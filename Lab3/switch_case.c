/**
 *  bubble sort
 * compare in a different function
 * 
 * */

#include <stdio.h>

void process(char *input){
        if (*input >= 'a' && *input <= 'z')
            *input = (*input - 'a') + 'A';
        else if (*input >= 'A' && (*input <= 'Z'))
            *input = (*input -'A') + 'a';
}


int main(){
    char input = 0;
    char c = 0;

    while (input != '\n'){
        input = getchar();
        process(&input);
        printf("%c", input);
    }

    return 0;
}