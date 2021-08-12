#include <stdio.h>
#include <ncurses.h>

void main(void){
    WINDOW *vin;
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
    // noecho();
    // clear();
    
    vin = newwin(4,10,5,7);
    start_color();
    init_pair(1,COLOR_YELLOW,COLOR_BLUE);
    init_pair(2,COLOR_BLUE,COLOR_YELLOW);
    init_pair(3,COLOR_BLUE,COLOR_WHITE); 
    wattron(vin,COLOR_PAIR(3));
    box(vin, 0 , 0); // -> test
    //wbkgd(vin,COLOR_PAIR(1));
    
    // wmove(vin,1,5);
    // wprintw(vin,"Fuck!  World. Hello\n");
        getch();
    wrefresh(vin);
    mvaddch(12, 12, '*');
    getch();
    
    wprintw(vin,"Hello, World2.\n");
    wclear(vin);
        getch();
    wattron(vin,COLOR_PAIR(1));
    wprintw(vin,"Hello, World.3\n");
    wrefresh(vin);
    mvaddstr(10, 1, "Press any key to quit");
    mvaddch(2, 2, '#');
    // refresh(); // <- test
    getch();
    printw("\nHello World!!!\n_->");
    wprintw(vin,"Hello, World2.\n");
    wrefresh(vin);
    getch();
    delwin(vin);
    endwin();


}