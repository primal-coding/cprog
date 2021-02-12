#include <stdio.h>

void main(){
    char charray[100];
    int num_chars=0;
    char input = 0;
    int i;
    char test;
    int pos[100];

    while(input != '\n'){
        input = getchar();
        charray[num_chars] = input;
        num_chars++;
    }

    test = getchar();  
    for (i=0;i<num_chars;i++){
        if (charray[i] == test)
            printf("%d ", i);
    }
    printf("\n");
}