#include <stdio.h>

enum type {INT,CHAR, STRING};

struct node{
    enum type data_type;
    void *data;
    struct node *next;
};



struct node *create(void *data, int data_type){
    
}