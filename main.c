#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define HEIGHT 40       // If you change HEIGHT and WIDTH, MUST change ARRAY_SIZE accordingly
#define WIDTH 70
#define ARRAY_SIZE (HEIGHT*WIDTH)
#define INITIAL_ALIVE_PERCENT 15

int current_grid[HEIGHT][WIDTH];
int next_grid[HEIGHT][WIDTH];

int all_bounded_nums[ARRAY_SIZE];


// In C, a function must be declared before it is called
int wrap_row(int row){

    if (row < 0){           // trying to go backward? sent to Last row
        return HEIGHT-1;
    }
    if (row >= HEIGHT){      // trying to go forward? sent to First row (>= cuz HEIGHT is 10, 10 isnt valid index)
        return 0;
    }

    return row;     // dont be rude, if check passed, return what was passed to YOU!
                    // more importantly: in C, non-void func must return something.
}
int wrap_col(int col){

    if (col < 0){
        return WIDTH-1;
    }
    if (col >= WIDTH){
        return 0;
    }

    return col;
}


int check_neighbour_state(int row, int col){

    int count_alive_neigbour = 0;
    
    // middle line
    if (current_grid[row][wrap_col(col-1)] == 1){
        ++count_alive_neigbour;
    }
    if (current_grid[row][wrap_col(col+1)] == 1){
        ++count_alive_neigbour;
    }

    // top line
    int cc_tc_row = wrap_row(row-1);          //CurrentCell's_TopCell_Row
    int cc_tc_col = col;

    if (current_grid[cc_tc_row][cc_tc_col] == 1){
        ++count_alive_neigbour;
    }
    if (current_grid[cc_tc_row][wrap_col(cc_tc_col-1)] == 1){
        ++count_alive_neigbour;
    }
    if (current_grid[cc_tc_row][wrap_col(cc_tc_col+1)] == 1){
        ++count_alive_neigbour;
    }

    // bottom line
    int cc_bc_row = wrap_row(row+1);          //CurrentCell's_BottomCell_Row
    int cc_bc_col = col;

    if (current_grid[cc_bc_row][cc_bc_col] == 1){
        ++count_alive_neigbour;
    }
    if (current_grid[cc_bc_row][wrap_col(cc_bc_col-1)] == 1){
        ++count_alive_neigbour;
    }
    if (current_grid[cc_bc_row][wrap_col(cc_bc_col+1)] == 1){
        ++count_alive_neigbour;
    }

    return count_alive_neigbour;

    // This is the updated one after adding wrap_row and wrap_col.
    // Would look better if:
    //      int left_col  = wrap_col(col - 1);
    //      int right_col = wrap_col(col + 1);
    // so we would remove:
    //      cc_tc_col
    //      cc_bc_col
    // since we can reuse left_col and right_col
}



void live_or_die(int alive_neigbours, int row, int col){

    int live = 0;
    if (current_grid[row][col] == 1) {
        if (alive_neigbours == 2 || alive_neigbours == 3) {
            live = 1;
        }
    } else {
        if (alive_neigbours == 3) {
            live = 1;
        }
    }

    // if (alive_neigbours < 2 || alive_neigbours > 3){     //my confusing code
    //     live = 0;
    // }
    // else if (current_grid[row][col] == 0) {
    //     if (alive_neigbours == 3){
    //         live = 1;   
    //     }
    // }

    if (live){
        next_grid[row][col] = 1;
    } else {
        next_grid[row][col] = 0;
    }

    return;
}

// calculates the next gen and stores it in next_grid
void compute_next_generation() {
    for (size_t row = 0; row < HEIGHT; ++row) {
        for (size_t col = 0; col < WIDTH; ++col) {
            int alive_neigbours = check_neighbour_state(row, col);
            live_or_die(alive_neigbours, row, col);
        }
    }
    return;
}

// copies next_grid into the current_grid
void apply_next_generation() {
    for (size_t row = 0; row < HEIGHT; ++row) {
        for (size_t col = 0; col < WIDTH; ++col) {
            current_grid[row][col] = next_grid[row][col];
        }
    }
    return;
}

void update_grid() {        // wrapper function
    compute_next_generation();
    apply_next_generation();
}


void store_bounded_nums(){
    int random_num;
    int bounded_num;
    for (int i = 0; i < ARRAY_SIZE; ++i){
        random_num = rand();
        bounded_num = random_num % 100;     // IMPORTANT TODO: the %num matters alot...
        all_bounded_nums[i] = bounded_num;
    }
    printf("\n\n");
    return;
}

void set_grid_initial_state(){

    int index = 0;       // See point1 in NOTES.md
    for (size_t row = 0; row < HEIGHT; ++row) {
        for (size_t col = 0; col < WIDTH; ++col){
            if (all_bounded_nums[index] < INITIAL_ALIVE_PERCENT) {     // >40 too dense, <10 too sparse, between 15-30 sweetspot
                current_grid[row][col] = 1;
            }
            ++index;
        }
    }
    return;
}

void print_bounded_nums(){
    for (int i = 0; i < ARRAY_SIZE; ++i){
        printf("%d, ", all_bounded_nums[i]);
    }
    return;
}

void print_entire_grid(){
    for (size_t row = 0; row < HEIGHT; ++row) {
        for (size_t col = 0; col < WIDTH; ++col){
            if (current_grid[row][col] == 1) {
                printf(" \033[7m  \033[0m "); // High-contrast inverted block
            } else {
                printf(" .  ");               // Clean dot for dead cells
            }
        }
        printf("\n\n");
    }
}

void clear_terminal_screen(){
    printf("\033[2J");      // clear screen once
    printf("\033[?25l");    // hide blinking cursor
}

int main () {

    srand(time(NULL));  // pass NULL or memory address

    // initial setup before loop starts
    store_bounded_nums();
    set_grid_initial_state();

    clear_terminal_screen();

    while (1) {
        printf("\033[H");
        print_entire_grid();
        fflush(stdout);
        update_grid();
        usleep(300000);
    }

    return 0;
}

// TODO: add q_pressed() function
// TODO: auto reseed if generation dies?
// TODO: add ask_height_width() func
// TODO: would be better if we check the terminal screen zooming
//       according to given height,width
// TODO: add Generation %d | Alive %d in print function? would be good i guess