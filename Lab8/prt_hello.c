#include <stdio.h>

void main (int argc, char *argv[]){
    int i;
    printf("Hello");
    if (argc > 1){
        for (i=1;i<argc;i++){
            printf(" %s", argv[i]);
        }
    } else {
        printf("Game over.");
    }
    printf("\n");
}