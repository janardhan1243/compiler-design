#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 1000
void countStats(char text[]) {
    int charCount = 0, wordCount = 0, lineCount = 0;
    int isWord = 0; 

    for (int i = 0; text[i] != '\0'; i++) {
        charCount++;
        if (text[i] == '\n') {
            lineCount++;
        }
        if (isspace(text[i]) || text[i] == '\0') {
            isWord = 0; 
        } else if (isWord == 0) {
            isWord = 1; 
            wordCount++;
        }
    }

    printf("Character Count: %d\n", charCount);
    printf("Word Count: %d\n", wordCount);
    printf("Line Count: %d\n", lineCount);
}
int main() {
    char text[MAX_SIZE];
    printf("Enter text (Ctrl+D to end on Unix/Linux, Ctrl+Z on Windows):\n");
    while (fgets(text, MAX_SIZE, stdin) != NULL) {
        countStats(text); 
    }
        return 0;
}

