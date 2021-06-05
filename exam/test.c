#include <stdio.h>



void main(int argc, char *argv){
    char *string="Hello"; if (string) printf("False1");
    //char *string1=NULL; if (!string1[5]) printf("False");
    //char *string2=NULL; if (string2[5]) printf("False");
    char *string3="Hello"; if (!string3[5]) printf("False4");
     //char *string4="Hello"; if (string4[5]) printf("False5");
     //char *string5="Hello"; if (!string5) printf("False6");
    char *string6=NULL; if (!string6) printf("False7");
    //char *string7=NULL; if (string7) printf("False");
}