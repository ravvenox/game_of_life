#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10       // If you change HEIGHT and WIDTH, MUST change ARRAY_SIZE accordingly
#define WIDTH 10        // TODO: need to find a dynamic solution, size will be equal to HEIGHT*WIDTH
int current_grid[HEIGHT][WIDTH];
int next_grid[HEIGHT][WIDTH];

#define ARRAY_SIZE 100
int all_bounded_nums[ARRAY_SIZE];

#define ALIVE 1
#define DEAD 0

int check_neighbour_state(int row, int col){

    int count_alive_neigbour = 0;
    
    // middle line
    if (current_grid[row][col-1] == 1){
        ++count_alive_neigbour;
    }
    if (current_grid[row][col+1] == 1){
        ++count_alive_neigbour;
    }

    // top line
    int cc_tc_row = row-1;          //CurrentCell's_TopCell_Row
    int cc_tc_col = col;

    if (current_grid[cc_tc_row][cc_tc_col] == 1){
        ++count_alive_neigbour;
    }
    if (current_grid[cc_tc_row][cc_tc_col-1] == 1){
        ++count_alive_neigbour;
    }
    if (current_grid[cc_tc_row][cc_tc_col+1] == 1){
        ++count_alive_neigbour;
    }

    // bottom line
    int cc_bc_row = row+1;          //CurrentCell's_BottomCell_Row
    int cc_bc_col = col;

    if (current_grid[cc_bc_row][cc_bc_col] == 1){
        ++count_alive_neigbour;
    }
    if (current_grid[cc_bc_row][cc_bc_col-1] == 1){
        ++count_alive_neigbour;
    }
    if (current_grid[cc_bc_row][cc_bc_col+1] == 1){
        ++count_alive_neigbour;
    }

    return count_alive_neigbour;
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


void wrap_borders(){
    
}


void store_bounded_nums(){
    int random_num;
    int bounded_num;
    for (int i = 0; i < ARRAY_SIZE; ++i){
        random_num = rand();
        bounded_num = random_num % 101;     // 101 cuz --- to get 100 included!
        all_bounded_nums[i] = bounded_num;
    }
    printf("\n\n");
    return;
}

void set_grid_initial_state(){

    int index = 0;       // See point1 in NOTES.md
    for (size_t row = 0; row < HEIGHT; ++row) {
        for (size_t col = 0; col < WIDTH; ++col){
            if (all_bounded_nums[index] < 30) {
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
            printf(" %d  ", current_grid[row][col]);
        }
        printf("\n\n");
    }
}

int main () {

    srand(time(NULL));  // pass NULL or memory address

    store_bounded_nums();
    
    set_grid_initial_state();

    print_entire_grid();
    print_bounded_nums();
    
    return 0;
}