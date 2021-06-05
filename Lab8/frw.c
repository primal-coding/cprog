#include <stdio.h>
#include <stdlib.h>


void main(int argc, char *argv[]){
    FILE *f;

    f = fopen("ex1.dat", "a");

    if (argc >=2){
        int i;
        for (i=1; i<argc; i++){
            fputs(argv[i], f); // write command line argument i to the file
            fputs("\n", f);    // 
        }
    } else {
        char tmp[21];
        fgets(tmp, 20, stdin);
        fputs(tmp, f);
        fputs("\n", f);
    }
    fclose(f);

}