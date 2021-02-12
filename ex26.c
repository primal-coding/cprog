#include <stdio.h>

void main(){
    char chmatrix[4][4];
    char input = 0;
    int num_chars = 0;
    int row=0; int col=0; int i,j;

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

    printf("Char row(0-3): ");
    row = getchar() - '0';
    getchar();
    printf("Char column(0-3): ");
    col = getchar() - '0';
    getchar();

    if (row<0 || row>3 || col<0 || col>3){
        printf("Row and Column must between 0 and 3\n");
        return;
    }
    
    for (i=row-1;i<=row+1;i++){
        for (j=col-1;j<=col+1;j++){
            if (i<0 || j<0 || i>3 || j>3) continue;
            printf("%c ",chmatrix[i][j]);
        }
        printf("\n");
    }
}