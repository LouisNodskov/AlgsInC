#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    bool a[ROWS][COLS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (gcd(i, j) == 1) {
                a[i][j] = true;
            } else {
                a[i][j] = false;
            }
        }
    }

    // Print the array
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
