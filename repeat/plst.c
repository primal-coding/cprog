#include <stdio.h>
#include <ncurses.h>


struct song {
    char title[32];
    char artist[32];
    int duration;
};

// having the name of the playlist for each position of the song being waste of memory
// the playlist struct has been in two
struct node{
    int position;   // for indexing and easier implementation of search, as well as shuffling in place 
    struct song s;  // for clarity of reading, as song's attributes could be implemented here
    struct node *next;
};

struct playlist {
    char name[32];
    struct node *head;
};

void menu_choice_up(int c);
void menu_choice_down(int c);
void menu_choice(int c);

// clears terminal screen and sets the cursor position to the top-left
void cls(){
    printf("\e[1;1H\e[2J");
}

void main(int argc, char *argv[]){
    int i, c, ch;

    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    start_color();
    init_pair(1,COLOR_RED,COLOR_BLACK);
    init_pair(2,COLOR_BLACK,COLOR_RED);
    init_pair(3,COLOR_YELLOW,COLOR_RED);
    init_pair(4,COLOR_YELLOW,COLOR_BLACK);
    attron(COLOR_PAIR(1));
    printw("Test 1\n");
    attron(COLOR_PAIR(2));
    printw("Test 2\n");
    attron(COLOR_PAIR(3));
    printw("Test 3\n");
    attron(COLOR_PAIR(4));
    printw("Test 4\n");
    getch();
    attron(0);
    refresh();
    printw("???\n");
    getch();

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
    mvprintw(7,4,"4_ Search a song within the Playlist Playlist");
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


/*
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

    cls();


    /// TODO : Menu and Stuff \\\
    nah?
    printf("0");
    printf("\e[3;3HHoly good Lord?\n");

*/
    c = 1;
    while((ch = getch()) != '\n') {	
        switch(ch) {
			case KEY_UP:
                if (c > 1) {
                    --c;
                    menu_choice_up(c);
                }
				break;
			case KEY_DOWN:
				if (c < 12) {
                    ++c;
                    menu_choice_down(c);
                }
				break;
            default:
                move(17,10);
            break;
		}
	}
    if (c!=12) menu_choice(c);
    
    getch();
    endwin();
}

void menu_choice_up(int c){
    switch (c){
        case 1:
            attron(COLOR_PAIR(2));
            mvprintw(4,4,"1_ Create a new Playlist");
            attron(COLOR_PAIR(1));
            mvprintw(5,4,"2_ Add a song to the end of the playlist");
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
            mvprintw(7,4,"4_ Search a song within the Playlist Playlist");
            move(17,10);
        break;
        case 4:
            attron(COLOR_PAIR(2));
            mvprintw(7,4,"4_ Search a song within the Playlist Playlist");
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

void menu_choice(int c){

}

void menu_choice_down(int c){
    switch (c){
        case 2:
            attron(COLOR_PAIR(1));
            mvprintw(4,4,"1_ Create a new Playlist");
            attron(COLOR_PAIR(2));
            mvprintw(5,4,"2_ Add a song to the end of the playlist");
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
            mvprintw(7,4,"4_ Search a song within the Playlist Playlist");
            move(17,10);
        break;
        case 5:
            attron(COLOR_PAIR(1));
            mvprintw(7,4,"4_ Search a song within the Playlist Playlist");
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

