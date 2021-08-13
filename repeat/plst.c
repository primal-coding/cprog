#include <stdio.h>
#include <string.h>
#include <ncurses.h>

// sperated from the node for reading clarity of the source code
struct Song {
    char *title;
    char *artist;
    int duration;
};

// having the name of the playlist for each position of the song being waste of memory
// the playlist struct has been split in two
struct Node{
    int index;   // for easier implementation of search, as well as shuffling in place 
    struct Song s;  // for clarity of reading, as song's struct attributes could be implemented here
    struct Node *next;
} head;

struct Playlist {
    char *name;
    struct Node *head;
} pl;

void display_main_menu();
void display_title();
void menu_choice_up(int c);
void menu_choice_down(int c);
void menu_choice(int c);
void create_playlist();
void add_song();
void play_playlist();
void search_song();
void delete_song();
void swap_songs();
void play_random_song();
void shuffle_playlist();
void calc_duration();
void save_playlist();
void load_playlist();

// clears terminal screen and sets the cursor position to the top-left
void cls(){
    printf("\e[1;1H\e[2J");
}

void main(int argc, char *argv[]){
    int i, c, ch;
    head.index = 0;
    pl.name="";

    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    start_color();
    init_pair(1,COLOR_RED,COLOR_BLACK);
    init_pair(2,COLOR_BLACK,COLOR_RED);
    init_pair(3,COLOR_YELLOW,COLOR_RED);
    init_pair(4,COLOR_YELLOW,COLOR_BLACK);

    display_main_menu();
// if (pl.name[0] == '\0') mvprintw(1,1,"0");
    // main menu choice selection loop
    while (1){
        c = 1;
        while((ch = getch()) != '\n') {	
            switch(ch) {
                case KEY_UP:
                    if (c > 1) {
                        --c;
                        menu_choice_up(c);      // UI menu selection update
                    }
                    break;
                case KEY_DOWN:
                    if (c < 12) {
                        ++c;
                        menu_choice_down(c);    // UI menu selection update
                    }
                    break;
                default:
                    move(17,10);                // cursor location update
                break;
            }
        }
        if (c!=12) menu_choice(c);
        else {
            // todo SAVE FILE?
            break; 
        }
    }
    endwin();
}

void menu_choice_up(int c){
    switch (c){
        case 1:
            attron(COLOR_PAIR(2));
            mvprintw(4,4,"1_ Create a new Playlist");                   // updating to inversed colors (selected)
            attron(COLOR_PAIR(1));
            mvprintw(5,4,"2_ Add a song to the end of the playlist");   // updating to non-inversed colors (deselect)
            move(17,10);
        break;
        case 2:
            attron(COLOR_PAIR(2));
            mvprintw(5,4,"2_ Add a song to the end of the playlist");
            attron(COLOR_PAIR(1));
            mvprintw(6,4,"3_ Play the Playlist");
            move(17,10);
        break;
        case 3:
            attron(COLOR_PAIR(2));
            mvprintw(6,4,"3_ Play the Playlist");
            attron(COLOR_PAIR(1));
            mvprintw(7,4,"4_ Search a song within the Playlist");
            move(17,10);
        break;
        case 4:
            attron(COLOR_PAIR(2));
            mvprintw(7,4,"4_ Search a song within the Playlist");
            attron(COLOR_PAIR(1));
            mvprintw(8,4,"5_ Delete a song from the Playlist");
            move(17,10);
        break;
        case 5:
            attron(COLOR_PAIR(2));
            mvprintw(8,4,"5_ Delete a song from the Playlist");
            attron(COLOR_PAIR(1));
            mvprintw(9,4,"6_ Swap two songs from the playlist");
            move(17,10);
        break;
        case 6:
            attron(COLOR_PAIR(2));
            mvprintw(9,4,"6_ Swap two songs from the playlist");
            attron(COLOR_PAIR(1));
            mvprintw(10,4,"7_ Play a random song from Playlist");
            move(17,10);
        break;
        case 7:
            attron(COLOR_PAIR(2));
            mvprintw(10,4,"7_ Play a random song from Playlist");
            attron(COLOR_PAIR(1));
            mvprintw(11,4,"8_ Shuffle the play the Playlist");
            move(17,10);
        break;
        case 8:
            attron(COLOR_PAIR(2));
            mvprintw(11,4,"8_ Shuffle the play the Playlist");
            attron(COLOR_PAIR(1));
            mvprintw(12,4,"9_ Playlist total time");
            move(17,10);
        break;
        case 9:
            attron(COLOR_PAIR(2));
            mvprintw(12,4,"9_ Playlist total time");
            attron(COLOR_PAIR(1));
            mvprintw(13,4,"10_ Save Playlist");
            move(17,10);
        break;
        case 10:
            attron(COLOR_PAIR(2));
            mvprintw(13,4,"10_ Save Playlist");
            attron(COLOR_PAIR(1));
            mvprintw(14,4,"11_ Load Playlist");
            move(17,10);
        break;

        case 11:
            attron(COLOR_PAIR(2));
            mvprintw(14,4,"11_ Load Playlist");
            attron(COLOR_PAIR(1));
            mvprintw(15,4,"12_ Exit Playlist Manager");
            move(17,10);
        break;

        default:
            mvprintw(20,5,"Error Processing Choice %d",c);
            move(17,10);
        break;
    }
}

void menu_choice_down(int c){
    switch (c){
        case 2:
            attron(COLOR_PAIR(1));
            mvprintw(4,4,"1_ Create a new Playlist");                   // updating to non-inversed colors (deselect)
            attron(COLOR_PAIR(2));
            mvprintw(5,4,"2_ Add a song to the end of the playlist");   // updating to inversed colors (selected)
            move(17,10);
        break;
        case 3:
            attron(COLOR_PAIR(1));
            mvprintw(5,4,"2_ Add a song to the end of the playlist");
            attron(COLOR_PAIR(2));
            mvprintw(6,4,"3_ Play the Playlist");
            move(17,10);
        break;
        case 4:
            attron(COLOR_PAIR(1));
            mvprintw(6,4,"3_ Play the Playlist");
            attron(COLOR_PAIR(2));
            mvprintw(7,4,"4_ Search a song within the Playlist");
            move(17,10);
        break;
        case 5:
            attron(COLOR_PAIR(1));
            mvprintw(7,4,"4_ Search a song within the Playlist");
            attron(COLOR_PAIR(2));
            mvprintw(8,4,"5_ Delete a song from the Playlist");
            move(17,10);
        break;
        case 6:
            attron(COLOR_PAIR(1));
            mvprintw(8,4,"5_ Delete a song from the Playlist");
            attron(COLOR_PAIR(2));
            mvprintw(9,4,"6_ Swap two songs from the playlist");
            move(17,10);
        break;
        case 7:
            attron(COLOR_PAIR(1));
            mvprintw(9,4,"6_ Swap two songs from the playlist");
            attron(COLOR_PAIR(2));
            mvprintw(10,4,"7_ Play a random song from Playlist");
            move(17,10);
        break;
        case 8:
            attron(COLOR_PAIR(1));
            mvprintw(10,4,"7_ Play a random song from Playlist");
            attron(COLOR_PAIR(2));
            mvprintw(11,4,"8_ Shuffle the play the Playlist");
            move(17,10);
        break;
        case 9:
            attron(COLOR_PAIR(1));
            mvprintw(11,4,"8_ Shuffle the play the Playlist");
            attron(COLOR_PAIR(2));
            mvprintw(12,4,"9_ Playlist total time");
            move(17,10);
        break;
        case 10:
            attron(COLOR_PAIR(1));
            mvprintw(12,4,"9_ Playlist total time");
            attron(COLOR_PAIR(2));
            mvprintw(13,4,"10_ Save Playlist");
            move(17,10);
        break;
        case 11:
            attron(COLOR_PAIR(1));
            mvprintw(13,4,"10_ Save Playlist");
            attron(COLOR_PAIR(2));
            mvprintw(14,4,"11_ Load Playlist");
            move(17,10);
        break;
        case 12:
            attron(COLOR_PAIR(1));
            mvprintw(14,4,"11_ Load Playlist");
            attron(COLOR_PAIR(2));
            mvprintw(15,4,"12_ Exit Playlist Manager");
            move(17,10);
        break;

        default:
            mvprintw(20,5,"Error Processing Choice %d",c);
            move(17,10);
        break;
    }
}

void menu_choice(int c){
    switch (c){
        case 1:
            create_playlist();
        break;
        case 2:
            add_song();
        break;
        case 3:
            play_playlist();
        break;
        case 4:
            search_song();
        break;
        case 5:
            delete_song();
        break;
        case 6:
            swap_songs();
        break;
        case 7:
            play_random_song();
        break;
        case 8:
            shuffle_playlist();
        break;
        case 9:
            calc_duration();
        break;
        case 10:
            save_playlist();
        break;
        case 11:
            load_playlist();
        break;
    }
}

void create_playlist(){

    display_title();
    char s[32];
    attron(COLOR_PAIR(2));
    mvprintw(4,6,"1_ Create a new Playlist");
    attron(COLOR_PAIR(1));

    mvprintw(7,6,"Enter the name of the new Playlist :");
    mvprintw(9,6,"=>                               <=");
    attron(COLOR_PAIR(4));
    move(9,8);
    scanw("%s",s);
    pl.name = s;
    attron(COLOR_PAIR(1));
    getch();
    mvprintw(2,30,"%s",pl.name);
    getch();
    display_main_menu();

}
void add_song(){
    attron(COLOR_PAIR(2));
    mvprintw(4,6,"2_ Add a song to the end of the playlist");
    attron(COLOR_PAIR(1));


}
void play_playlist(){
    attron(COLOR_PAIR(2));
    mvprintw(4,6,"3_ Play the Playlist");
    attron(COLOR_PAIR(1));
}
void search_song(){
    attron(COLOR_PAIR(2));
    mvprintw(4,6,"4_ Search a song within the Playlist");
    attron(COLOR_PAIR(1));
}
void delete_song(){
    attron(COLOR_PAIR(2));
    mvprintw(4,6,"5_ Delete a song from the Playlist");
    attron(COLOR_PAIR(1));
}
void swap_songs(){
    attron(COLOR_PAIR(2));
    mvprintw(4,6,"6_ Swap two songs from the playlist");
    attron(COLOR_PAIR(1));
}
void play_random_song(){
    attron(COLOR_PAIR(2));
    mvprintw(4,6,"7_ Play a random song from Playlist");
    attron(COLOR_PAIR(1));
}
void shuffle_playlist(){
    attron(COLOR_PAIR(2));
    mvprintw(4,6,"8_ Shuffle the play the Playlist");
    attron(COLOR_PAIR(1));
}
void calc_duration(){
    attron(COLOR_PAIR(2));
    mvprintw(4,6,"9_ Playlist total time");
    attron(COLOR_PAIR(1));
}
void save_playlist(){
    attron(COLOR_PAIR(2));
    mvprintw(4,6,"10_ Save Playlist");
    attron(COLOR_PAIR(1));
}
void load_playlist(){
    attron(COLOR_PAIR(2));
    mvprintw(4,6,"11_ Load Playlist");
    attron(COLOR_PAIR(1));

/*
    printf("Hello... %s",argv[0]);
    if (argc > 1){
        printf("argc : %d\n", argc);
        for (i=1; i<argc; i++){
            printf("%d : %s \n",i, argv[i]);
        }
        printf("\n");
    }
*/
}


void display_title(){
    refresh();
    clear();
    attron(A_BOLD);
    attron(COLOR_PAIR(2));
    mvprintw(2,9,"_Playlist Manager_");
    attroff(A_BOLD);
    getch();
}
void display_main_menu(){
    clear();
    attron(A_BOLD);
    attron(COLOR_PAIR(2));
    mvprintw(2,9,"_Playlist Manager_");
    attroff(A_BOLD);
    attron(COLOR_PAIR(2));
    mvprintw(4,4,"1_ Create a new Playlist");
    attron(COLOR_PAIR(1));
    mvprintw(5,4,"2_ Add a song to the end of the playlist");
    mvprintw(6,4,"3_ Play the Playlist");
    mvprintw(7,4,"4_ Search a song within the Playlist");
    mvprintw(8,4,"5_ Delete a song from the Playlist");
    mvprintw(9,4,"6_ Swap two songs from the playlist");
    mvprintw(10,4,"7_ Play a random song from Playlist");
    mvprintw(11,4,"8_ Shuffle the play the Playlist");
    mvprintw(12,4,"9_ Playlist total time");
    mvprintw(13,4,"10_ Save Playlist");
    mvprintw(14,4,"11_ Load Playlist");
    mvprintw(15,4,"12_ Exit Playlist Manager");
    attron(A_BOLD);
    attron(COLOR_PAIR(4));
    mvprintw(17,8,"=> <=");
    attroff(A_BOLD);
    move(17,10);
}