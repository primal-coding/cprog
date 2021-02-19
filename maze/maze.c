#include <stdio.h>
#include <ncurses.h>
#include "maze_gen.c"

struct cell uPos;           // position of the user on the map
struct cell map_enterance;          
struct cell map_exit;

void displayM(struct maze m);
char ** get_maze_inputs();
void convert_inputs(char** inputs, int* converted_inputs);
void quest(struct maze dungeon, int fog);


void main(void){
    int i;
    int row,col;            // terminal screen dimensions
    unsigned int width, height, cell_size;
    int rand_seed, fog;
    char** inputs;     // arrays of strings for height/width/cell_size/seed/fog ([5][10])
    int maze_attributes[5];    // array of int as above
    struct maze dungeon;

    initscr();
    getmaxyx(stdscr,row,col);		/* get the number of rows and columns of the terminal*/
    if(has_colors() == FALSE){	
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
	if (can_change_color() == ERR){
        endwin();
        printf("Your terminal can not change color\n");
        exit(1);
    }
    start_color();			/* Start color 			*/
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2,   COLOR_WHITE, COLOR_BLACK);
	init_pair(3,  COLOR_RED, COLOR_BLACK);

    inputs = get_maze_inputs();     // user input for the attributes of the maze
    convert_inputs(inputs, maze_attributes);    // convertion of attriutes from char* to int
    for (i=0;i<5;i++){           
        free (inputs[i]);           // releasing the memory allocated for the arrays of 
    }                                   // 5 attributes for the maze
    free (inputs);                  // relasing the memory for the array of pointers to the attributes

    // mvprintw(3,3,"Inputs: ");
    // for (i=0;i<5;i++){
    //     printw("%d ", maze_attributes[i]);
    // }
    height = maze_attributes[0];
    width = maze_attributes[1];
    cell_size = maze_attributes[2];
    rand_seed = maze_attributes[3];
    fog = maze_attributes[4];
    
    dungeon = generate_maze(width,height,cell_size,rand_seed);
    displayM(dungeon);
    // //TEST
    // mvaddch(2, 15, ' ');
    // printw("<Entrance:%d - Exit:%d>",map_enterance.y,map_exit.y);

    quest(dungeon, fog);

    refresh();
    getch();

    endwin();
}

/************************************************
 * converts the string values entered by the user
 * of the properties for the maze
 * to integers, one character at a time
 * */
void convert_inputs(char** inputs, int* converted_inputs){
    int i, j, e;
    for (i=0;i<5;i++){              // looping through each value of char*(inputs[]) to get converted to int
        converted_inputs[i] = 0;    // ... with each (int) value starting at zero, and 'reconstructed'
        e = 1;                      // exponent (1, then 10, then 100...)
        for (j=0;j<strlen(inputs[i]);j++){
            inputs[i][j] = inputs[i][j] - '0';  // converting each digit from ASCII
            converted_inputs[i] = (converted_inputs[i]*e) + inputs[i][j];
            e *= 10;
        }
    }
}

/************************************************
 * inputs the maze properties
 * height / width / cell_size / seed / fog
 * using an array(5) of pointers to char arrays(10)
 */
char ** get_maze_inputs(){
    int i;
    char str[10];
    char** inputs;

    inputs = malloc (sizeof(char*) * 5 + sizeof(char) * 10);            // array of pointers to char[10]
    for (i=0;i<5;i++){
        inputs[i] = malloc(sizeof(char) * 10);      // ... pointing to char arrays
    }
    
    mvprintw(2,2," Enter the height of the maze: ");
    getstr(str);
    mvprintw(LINES - 2, 1, "Height: %s", str);
    // inputs[0] = str; WONT WORK as str will change and..
    // inputs[0..4] will all point to the same address (str)
    strcpy(inputs[0],str);
    mvprintw(2,2,"  Enter the width of the maze: ");
    getstr(str);
    mvprintw(LINES - 3, 1, "Width: %s", str);
    strcpy(inputs[1],str);
    mvprintw(2,2,"  Enter the size of the cells: ");
    getstr(str);
    mvprintw(LINES - 4, 1, "Cell size: %s", str);
    strcpy(inputs[2],str);
    mvprintw(2,2,"  Enter the seed for the maze: ");
    getstr(str);
    mvprintw(LINES - 5, 1, "Seed: %s", str);
    strcpy(inputs[3],str);
    mvprintw(2,2,"Enter the size of fog(0-none): ");
    getstr(str);
    mvprintw(LINES - 6, 1, "Fog: %s ", str);
    getch();                // TEMP FOR TEST
    strcpy(inputs[4],str);

    return inputs;
}

/**
 * outputs the map for the first time
 * and initialses the cells entrance and exit
 * as well as the user's position cell
**/
void displayM(struct maze m){
    int y, x;
    int width = m.w;    //no need for: *2*m.cell_size + 1;
    int height = m.h;   // already done in maze_gen
    //for test:
    //printw("W=%d - H=%d",width,height);
 
    for (y=0;y<height;y++){
        for (x=0;x<width;x++){
            switch (m.a[y][x]){
                case '#':
                    attron(COLOR_PAIR(3));
                    m.a[y][x] = 'o';
                    mvaddch(y+4, x+4, m.a[y][x]);
                    attroff(COLOR_PAIR(3));
                break;
                case 'w':
                    m.a[y][x] = '#';
                default:
                    mvaddch(y+4, x+4, m.a[y][x]);   // displays all maze chars @(4,4)
            }
            // if (m.a[y][x] == '#'){
            //     attron(COLOR_PAIR(3));
            //     m.a[y][x] = 'o';
            //     mvaddch(y+4, x+4, m.a[y][x]);
            //     attroff(COLOR_PAIR(3));
            //     }
            // else if (m.a[y][x] == 'w')
            //         m.a[y][x] = '#';
            // else 
            //     mvaddch(y+4, x+4, m.a[y][x]);       // displays all maze chars @(4,4)
            if (x==0 && m.a[y][x]==' '){         // entrance in column 0
                map_enterance.y = y;
                uPos.x = x;                      // init: user position on map
                uPos.y = y;                      // @entrance
            }
            if (x==width-1 && m.a[y][x]==' ')    // exit in last column (width-1)
                map_exit.y = y; 
        }
    }
    attron(COLOR_PAIR(1));
    mvaddch(uPos.y+4,uPos.x+4,'@');             // user char on map
    attroff(COLOR_PAIR(1));
    mvaddstr(2, 2, "Continue ->... ");
    refresh();
    getch();
    
}

/**************************
 * handling of the movement
 * of the user in the maze
 * */
void quest(struct maze dungeon, int fog){
    int potions = 0;        // potions found so far

    
}