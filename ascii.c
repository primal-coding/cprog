#include <stdio.h>

void main(void){
    int i;
/*
    for (i='a';i<='z';i++){
        printf("ASCII of %c -> %d\n", i, i);
    }
*/
    for (i=0;i<26;i++){
        char ucase = i+65;
        printf("ASCII of %c -> %d\n", ucase, ucase);
    }
}