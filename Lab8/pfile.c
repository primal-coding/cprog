#include <stdio.h>
#include <stdlib.h>


void main(int argc, char *argv){
    FILE *f;
    char in;
    f = fopen("ex1.dat", "r");

    while ((in = fgetc(f)) != EOF){
        printf("%c", in);
    }

}