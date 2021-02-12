#include <stdio.h>

void main(){
    char charray[100];
    int num_chars=0;
    char input = 0;
    int i;

    while(input != '\n'){
        input = getchar();
        charray[num_chars] = input;
        num_chars++;
    }

    for (i=0;i<num_chars;i++){
        if ((charray[i] >= 'a') && (charray[i] <= 'z')){
            printf("%c", charray[i] - 'a' + 'A');
        }
        else if ((charray[i] >= 'A') && (charray[i] <= 'Z'))
        {
            printf("%c", charray[i] - 'A' + 'a');
        }
        else printf("%c", charray[i]);
    }
    
}