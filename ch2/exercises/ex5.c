#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Write a function binary(int x) that prints out the binary equivalent of a number.
 */
int binary(int n);

int binary(int n) {
	int rem, p = 0, ret = 0;
	while (n != 0) {
		rem = n % 2;
		n = n / 2;
		ret += rem * pow(10, p); 
		p++;
	}
	return ret;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF)
		printf("%d\n", binary(n));
	exit(0);
}
