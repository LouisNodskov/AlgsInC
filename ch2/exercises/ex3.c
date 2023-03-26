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
		}
		u = u - v;
	}
	return v;
}

int main() {
	struct fraction f;
	while (scanf("%d %d", &f.numerator, &f.denominator) != EOF)
		if (f.numerator > 0 && f.denominator > 0)
			printf("%d %d %d\n", f.numerator, f.denominator, gcd(f));
}
