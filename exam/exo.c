#include <stdio.h>

// struct point { int x; int y; };

int *copy(int *src, int length){
int i;
int dest[length];
for (i=0;i<length;i++) dest[i] = src[i];
return dest;
}


void main(int argc, char *argv){

 int src[3]={0,1,2}; 
 int *dest=copy(src,3); 
 printf("%d\n", dest[0]);
// /* print contents of dest */

// char *s = malloc(10); scanf("%s", s);
// printf("%s\n", s);

// int a[]={1,0,1,0,1,0};
// int b[]={1,0,0,0,1,0};
// int i = 0, j = 0;

// for (j=0; j<6; j++){
// if (a[i++] == 0 && b[i] == a[i])
//     printf("true %d\n", i);
// }


//struct point p; scanf("%d", &(p.y));


//printf("x= %d, y= %d\n", p.x, p.y);

}