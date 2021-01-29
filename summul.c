#include <stdio.h>

void main(void){
    int sum=0;
    int max=10;
    int i;
    int mul=1;

    for (i=0;i<max;i++){
        sum +=i;
        mul *= (i+1);
    }


    printf("The sum of the first %d numbers is %d\n", max, sum);
    printf("The multiplication of the first %d numbers is %d\n", max, mul);
}