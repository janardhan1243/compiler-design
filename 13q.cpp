#include <stdio.h>

int main() {
    int a = 5;
    int b = 3;
    int commonSubexpression = a * b;
    int result1 = commonSubexpression + 10;
    int result2 = commonSubexpression - 5;

    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);

    return 0;
}

