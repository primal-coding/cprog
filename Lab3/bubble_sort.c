#include <stdio.h>

void sort(int* a, int *b){
    int temp;
    if (*a > *b){
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

void main(void){
    char input = 0;
    int num[50];
    int i = 1, j = 0, sizeArray = 0, digit = 0; // sizeArray = value of last (valid) element!!!

    while (input != '\n'){
        input = getchar();
        if (input == ','){
            ++sizeArray;
            digit = 0;
        }
        if (input >= '0' && input <= '9'){
            digit = (digit * 10) + input - '0';
            num[sizeArray] = digit;
            printf("%c\n", input);
        }
    }
    printf("\nsA: %d\n", sizeArray);    // number of element -1 in array!!!
    printf("Before: ");
    for(i=0; i<sizeArray+1; i++)
        printf("%d, ", num[i]);
    printf("\n");
    for (i=0; i<sizeArray; i++){
        for (j=i+1; j<sizeArray+1; j++)
            sort(&num[i], &num[j]);
    }
    printf("After: ");
    for(i=0; i<sizeArray+1; i++)
        printf("%d, ", num[i]);
    printf("\n");
}