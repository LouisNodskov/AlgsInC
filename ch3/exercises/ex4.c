#include <stdio.h>

int josephus(int n, int k) {
    int i, j = 0, survivors = n;
    int circle[n];
    
    // initialize the circle with indices 0 to n-1
    for (i = 0; i < n; i++) {
        circle[i] = i;
    }
    
    // eliminate every kth person until only one survivor remains
    while (survivors > 1) {
        // find the next person to be eliminated
        j = (j + k - 1) % survivors;
        // move the remaining people one position to the left
        for (i = j; i < survivors - 1; i++) {
            circle[i] = circle[i + 1];
        }
        // decrement the number of survivors
        survivors--;
    }
    
    // the last survivor is in position 0
    return circle[0];
}

int main() {
    int n = 7, k = 3;
    int last_survivor = josephus(n, k);
    printf("The last survivor in a circle of %d people with k = %d is at position %d.\n", n, k, last_survivor);
    return 0;
}
