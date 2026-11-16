Rules to know to impliment Conway's `game of life`:
- A live cell with 2 or 3 live neighbors stays alive. Otherwise it dies.
- A dead cell with exactly 3 live neighbors becomes alive.


## Tasks:
- print the grid that contains 0s
- now i want to do something so that it isnt always 0, lets see how many will be alive and dead initially, i chose 30% to be alive and 70% to be dead INITIALLY, but the grid dead/alive wont be exactly distrubuted as 30-70 bcz we are using probability approach
AI is fucking stupid bullshit, overcomplicating things is all it does...
- now we will write logic for checking neigbours, checking the initial state is important bcz `let it be its state or change its state` is two different way to go which we need to decide
at this point things are really difficult, because it feels like multiple tasks are demanding to be solved simultaneously and its hard to decide which one to start with at first

## Questions:
- why do we have y in outer for loop but x in inner for loop (bcz we get into a row and print all cols for that row, doing the other way means: we get into a col and print all rows for that col, which is not ideal)
- why use ++y instead of y++, any difference (there is no difference if we normally use it inside for_loop_condition, but when we assign it to a an expression, must do it carefully)


## Points
point1: This code is the alternative i got from ai exactly before coming up with my own one which i already wrote
```
void set_grid_initial_state(int row, int col) {     // Google aimode
    int index = row * WIDTH + col; // Maps (row, col) to 0..99

    if (all_bounded_nums[index] < 30) {
        grid[row][col] = 1;
    } else {
        grid[row][col] = 0;
    }
}
```
this one seems to be really complicated, such a junk.

---
Awareness: Quite often, when we write a program for a long time, we get eager to see the result.