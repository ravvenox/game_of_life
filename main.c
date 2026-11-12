#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 10
int grid[HEIGHT][WIDTH];

#define ARRAY_SIZE 100
int all_bounded_nums[ARRAY_SIZE];

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



void set_grid_initial_state(int row, int col){

    static int index = 0;
    if (all_bounded_nums[index] < 30){
        grid[row][col] = 1;
    }
    ++index;
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
            printf(" %d  ", grid[row][col]);
        }
        printf("\n\n");
    }
}

int main () {

    srand(time(NULL));  // pass NULL or memory address

    store_bounded_nums();
    
    for (size_t row = 0; row < HEIGHT; ++row) {
        for (size_t col = 0; col < WIDTH; ++col){
            set_grid_initial_state(row, col);
        }
    }

    print_entire_grid();
    print_bounded_nums();
    
    return 0;
}