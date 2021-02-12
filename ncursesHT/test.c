#include <stdio.h>
#include <ncurses.h>

void main(void){
       // initscr();
    // printw("Hello World!!!\n->");
    // refresh();
    // getch();
    // printw("_\n_Thank you!\n->");
    // refresh();
    // getch();
    // endwin();
    initscr();
    cbreak();
    noecho();
    clear();
    WINDOW *vin;
    
    start_color();
    init_pair(1,COLOR_YELLOW,COLOR_BLUE);
    init_pair(2,COLOR_BLUE,COLOR_YELLOW);
    init_pair(3,COLOR_BLUE,COLOR_WHITE); 
    vin=newwin(12,20,13,0);
    //wbkgd(vin,COLOR_PAIR(1));
    wattron(vin,COLOR_PAIR(3));
    wmove(vin,0,5);
    mvaddch(4, 4, '*');
    wprintw(vin,"Hello, World.");
    mvaddstr(10, 0, "Press any key to quit");
    mvaddch(2, 2, '.');
    wrefresh(vin);
    getch();
    printw("Hello World!!!\n->");
    wrefresh(vin);
    getch();
    delwin(vin);
    endwin();


}