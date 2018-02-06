//Checks if the given number is a prime number
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int);

void main() {
	int x;

	printf("Enter a number: ");
	scanf("%d", &x);

	if (isPrime(x)) {
		printf("%d is prime.\n", x);
	}
	else {
		printf("%d is not prime.\n", x);
	}
}

bool isPrime(int x) {
	for (int i = 2; i<=x/2; i++) {
		if (x%i == 0) {
			return false;
		}
	}
	return true;
}
