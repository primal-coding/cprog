#include <stdio.h>

void main(){
    char chmatrix[4][4];
    char input = 0;
    int num_chars = 0;
    int row=0; int col=0; int i;

    while (input != '\n'){
        input = getchar();
        if (input == '\n') break;
            chmatrix[row][col] = input;
            col += 1;
            num_chars += 1;
        if (col == 4){
            row += 1;
            col = 0;
            if (row == 4){
                while (input != '\n'){
                    input = getchar();
                    }
                break;
            }
        }
    }
    for (i=num_chars;i<16;i++){
        chmatrix[row][col] = '#';
        col += 1;
        if (col == 4){
            col = 0;
            row += 1;
            if (row == 4){
                break;
            } 
        } 
    }
    for (row=0;row<4;row++){
        for (col=0;col<4;col++){
            printf("%c ", chmatrix[row][col]);
        }
        printf("\n");   
    }
}