#include <stdio.h>
#include <ncurses.h>
#include "maze_gen.c"

void displayM(struct maze m);

void main(void){
    unsigned int width, height, cell_size;
    int rand_seed;
    //test
    struct maze original = generate_maze(5,5,1,1);
    initscr();
    displayM(original);

}

void displayM(struct maze m){
    char c;
    int y, x;
    int width = m.w;
    int height = m.h;   //no need for: *2*m.cell_size + 1;
    printw("W=%d - H=%d",width,height);
    // mvaddch(4, 4, m.a[0][0]);
    // m.a[y][x]
    for (y=0;y<height;y++){
        for (x=0;x<width;x++){
            mvaddch(y+4, x+4, m.a[y][x]);
        }
    }

    mvaddstr(2, 2, "Press any key to quit");
    refresh();
    getch();
    endwin();
}