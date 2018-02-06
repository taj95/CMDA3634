//Checks if two numbers are Co-Prime
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int gcd(int, int);
bool isCoprime(int, int);

void main() {
	int x;
	int y;

	printf("Enter the first number: ");
	scanf("%d", &x);
	printf("Enter the second number: ");
	scanf("%d", &y);

	if (isCoprime(x, y)) {
		printf("%d and %d are coprime.\n", x, y);
	}
	else {
		printf("%d and %d are not coprime.\n", x, y);
	}
}

int gcd(int a, int b) {
	if (a==0 || b==0) return 0;
	if (a==b) return a;
	if (a>b) return gcd(a-b, b);
	return gcd(a, b-a);
}

bool isCoprime(int a, int b) {
	if (gcd(a, b)==1) {
		return true;
	}
	return false;
}
