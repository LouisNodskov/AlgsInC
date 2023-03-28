#include <stdio.h>
#include <stdlib.h>

void drawLine(int x1, int y1, int x2, int y2) {
    if (abs(x2 - x1) >= abs(y2 - y1)) {
        if (x1 > x2)
            drawLine(x2, y2, x1, y1);
        else {
            int x = x1;
            int y = y1;
            int a = y2 - y1;
            int b = x1 - x2;
            int d = 2 * a + b;

            while (x <= x2) {
                printf("(%d, %d)\n", x, y);
                if (d > 0) {
                    y++;
                    d += 2 * b;
                }
                x++;
                d += 2 * a;
            }
        }
    } else {
        if (y1 > y2)
            drawLine(x2, y2, x1, y1);
        else {
            int x = x1;
            int y = y1;
            int a = y2 - y1;
            int b = x1 - x2;
            int d = a + 2 * b;

            while (y <= y2) {
                printf("(%d, %d)\n", x, y);
                if (d < 0) {
                    x++;
                    d += 2 * a;
                }
                y++;
                d += 2 * b;
            }
        }
    }
}

int main() {
    int x1, y1, x2, y2;
    printf("Enter the starting point (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the ending point (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    drawLine(x1, y1, x2, y2);

    return 0;
}

