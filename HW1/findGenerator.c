//Finds a random generator of the given prime number
#include <stdlib.h>
#include <stdio.h>

int findGen(int);

void main() {
	int x;

	printf("Enter a prime number: ");
	scanf("%d", &x);

	int out = findGen(int x);
	printf("%d is a generator of Z_%d.\n", out, x);
}

int findGen(int x) {

}
