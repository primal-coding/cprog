#include <stdio.h>

void next_char(char *ch){
    *ch = *ch + 1; // are *ch++ and ++*ch valid?
}

int main(){
    char input = 0, charray[50];
    int i = 0, num_chars = 0;


    while (input != '\n'){
        input = getchar();
        charray[num_chars] = input;
        ++num_chars;
    }
    --num_chars;        // no NULL character at the end because charray is not a string
    // printf("Input: %s\n", charray);
    for (i=0; i<num_chars; i++)
        next_char(&charray[i]);
    charray[i] = 0;     // add the NULL chatracter to make it a string
    printf("Result: %s\n - %d characters\n", charray, num_chars);
    return 0;
}