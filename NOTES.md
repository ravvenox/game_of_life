Rules to know to impliment Conway's `game of life`:
- A live cell with 2 or 3 live neighbors stays alive. Otherwise it dies.
- A dead cell with exactly 3 live neighbors becomes alive.


## Tasks:
- print the grid that contains 0s
- now i want to do something so that it isnt always 0, lets see how many will be alive and dead initially, i chose 30% to be alive and 70% to be dead INITIALLY, but the grid dead/alive wont be exactly distrubuted as 30-70 bcz we are using probability approach
AI is fucking stupid bullshit, overcomplicating things is all it does...


## Questions:
- why do we have y in outer for loop but x in inner for loop (bcz we get into a row and print all cols for that row, doing the other way means: we get into a col and print all rows for that col, which is not ideal)
- why use ++y instead of y++, any difference (there is no difference if we normally use it inside for_loop_condition, but when we assign it to a an expression, must do it carefully)
