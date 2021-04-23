/**
 * to opposite case (lower/upper)
 * */
#include <stdio.h>
#include <ctype.h>



char *convert(char *s){
    int i;
    for (i=0;s[i]!='\0';i++){
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = toupper(s[i]);
        }
        else {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = tolower(s[i]);
                }
        }
    }
    return s;
}

void main(int argc, char *argv[]){
    int i;
    if (argc > 1){
        for (i=1;i<argc;i++) {
            argv[i] = convert(argv[i]);
            printf("%s ", argv[i]);
        }
    } else {
        printf("Game over.\n");
    }
    printf("\n");
}