#include <stdio.h>
#include <stdlib.h>

int main() {
    // Draw 3 numbers between 0 and 99
    printf("%d\n", rand() % 100);
    printf("%d\n", rand());
    printf("%d\n", rand());
    return 0;
}
