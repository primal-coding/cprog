#include <stdio.h>
#include <stdlib.h>
#include "linked_list.c"

struct student{
    char name[10];
    int year;
};

void create_student(struct student *s){
    printf("Enter student name and year: ");
    scanf("%s %d\n",s->name, &s->year);
}


int main(){
    struct student *s;
    s = malloc(sizeof(struct student));
    create_student(s);
    // printf("Enter student name and year: ");
    // scanf("%s %d\n",input->name, &input->year);
    printf("Name: %s\nYear: %d\n",s->name,s->year);
    return 0;
}