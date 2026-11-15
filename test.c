#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main() {
    // Enables UTF-8 on Linux, macOS, and online terminals
    setlocale(LC_ALL, "");

    // Example 1: Loop through Bengali characters (2437 to 2450)
    printf("--- Bengali Script ---\n");
    for (int i = 2437; i <= 2450; i++) {
        printf("%d: %lc  ", i, (wchar_t)i);
    }

    // Example 2: Loop through Weather & Symbols (9728 to 9740)
    printf("\n\n--- Symbols ---\n");
    for (int i = 9728; i <= 9740; i++) {
        printf("%d: %lc  ", i, (wchar_t)i);
    }

    // Example 3: Loop through Animals & Nature Emojis (128000 to 128015)
    printf("\n\n--- Emojis ---\n");
    for (int i = 128000; i <= 128015; i++) {
        printf("%d: %lc  ", i, (wchar_t)i);
    }
    
    printf("\n");
    return 0;
}
