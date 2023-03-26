/*
 * Give all the values that u and v take on when gcd is invoked with the initial
 * call gcd(12345, 56789).
 */
#include <stdio.h>
#include <stdlib.h>
 
struct fraction {
        int numerator;
        int denominator;
};
 
int gcd(struct fraction f);
 
int gcd(struct fraction f) {
        int t, u, v;
        u = f.numerator;
        v = f.denominator;
        while (u > 0) {
                if (u < v) {
                        t = u;
                        u = v;
                        v = t;
			printf("v: %d\n", v);
                }
                u = u - v;
		printf("u: %d\n", u);
        }
        return v;
}
 
int main() {
        struct fraction f;
        while (scanf("%d %d", &f.numerator, &f.denominator) != EOF)
                if (f.numerator > 0 && f.denominator > 0)
                        printf("%d %d %d\n", f.numerator, f.denominator, gcd(f));
}
