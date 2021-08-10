#include <stdio.h>

struct song {
    char title[32];
    char artist[32];
    int duration;
};

// having the name of the playlist for each position of the song being waste of memory
// the playlist struct has been in two
struct node{
    int position;   // for indexing and easier implementation of search 
    struct song s;
    struct node *next;
};

struct playlist {
    char name[32];
    struct node *head;
};

void cls(){
    printf("\e[1;1H\e[2J");
}

void main(int argc, char *argv[]){
    int i;
    printf("Hello... %s",argv[0]);
    if (argc > 1){
        printf("argc : %d\n", argc);
        for (i=1; i<argc; i++){
            printf("%d : %s \n",i, argv[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Game Over!\n");
    }



}