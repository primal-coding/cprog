#include <stdio.h>
#include <ncurses.h>
#include "maze_gen.c"

struct cell uPos;           // position of the user on the map
struct cell map_enterance;          
struct cell map_exit;

void displayM(struct maze m);
char ** get_maze_inputs();
int[] convert_inputs(char** inputs);


void main(void){
    int i;
    int row,col;            // terminal screen dimensions
    unsigned int width, height, cell_size;
    int rand_seed, fog;
    map_enterance.x = 0;
    map_exit.x = width-1;
    char** inputs;     // arrays of strings for height/width/cell_size/seed/fog ([5][10])
    int converted_inputs[5];    // array of int as above
    struct maze original;

    initscr();
    getmaxyx(stdscr,row,col);		/* get the number of rows and columns of the terminal*/
    inputs = get_maze_inputs();
    converted_inputs = convert_inputs(inputs);
    for (i=0;i<5;i++){
        free (inputs[i]);
    }
    free (inputs);

    // original = generate_maze(width,height,cell_size,rand_seed);
    // displayM(original);
    // //TEST
    // mvaddch(2, 15, ' ');
    // printw("<Entrance:%d - Exit:%d>",map_enterance.y,map_exit.y);
    refresh();
    getch();

    endwin();
}


int[] convert_inputs(char** inputs){
    int i, j, e;
    int converted_inputs[5];
    for (i=0;i<5;i++){
        converted_inputs[i] = 0;
        e = 1;
        for (j=0;j<strlen(inputs[i]);j++){
            converted_inputs[i] = converted_inputs[i]*e + inputs[i][j];
            e *= 10;
        }
    }

    // A SUIVRE...
}

/**
 * inputs the maze properties
 * height / width / cell_size / seed / fog
 * using an array(5) of pointers to char arrays(10)
 */
char ** get_maze_inputs(){
    int i;
    char str[10];
    char** inputs;

    inputs = malloc (sizeof(char*) * 5);            // array of pointers...
    for (i=0;i<5;i++){
        inputs[i] = malloc(sizeof(char) * 10);      // ... pointing to char arrays
    }
    
    mvprintw(2,2,"Enter the height of the maze: ");
    getstr(str);
    mvprintw(LINES - 2, 1, "Height: %s", str);
    // inputs[0] = str; WONT WORK as str will change and..
    // inputs[0..4] will all point to the same address (str)
    strcpy(inputs[0],str);
    mvprintw(2,2,"Enter the width of the maze: ");
    getstr(str);
    mvprintw(LINES - 3, 1, "Width: %s", str);
    strcpy(inputs[1],str);
    mvprintw(2,2,"Enter the size of the cells: ");
    getstr(str);
    mvprintw(LINES - 4, 1, "Cell size: %s", str);
    strcpy(inputs[2],str);
    mvprintw(2,2,"Enter the seed for the maze: ");
    getstr(str);
    mvprintw(LINES - 5, 1, "Seed: %s", str);
    strcpy(inputs[3],str);
    mvprintw(3,2,"Enter the size of fog(0-none): ");
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
            mvaddch(y+4, x+4, m.a[y][x]);       // displays all maze chars @(4,4)
            if (x==0 && m.a[y][x]==' '){         // entrance in column 0
                map_enterance.y = y;
                uPos.x = x;                      // init: user position on map
                uPos.y = y;                      // @entrance
            }
            if (x==width-1 && m.a[y][x]==' ')    // exit in last column (width-1)
                map_exit.y = y; 
        }
    }
    mvaddch(uPos.y+4,uPos.x+4,'@');             // user char on map
    mvaddstr(2, 2, "Continue ->... ");
    refresh();
    getch();
    
}