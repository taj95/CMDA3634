//Greatest Common Divisor function

#include <stdlib.h>
#include <stdio.h>

int gcd(int, int);

void main() {
	int x;
	int y;

	printf("Enter the first number: ");
	scanf("%d", &x);
	printf("Enter the second number: ");
	scanf("%d", &y);
	
	int out = gcd(x,y);
	printf("The greatest common divisor of %d and %d is %d.\n",x, y, out);
}

int gcd(int a, int b) {
	if (a==0 || b==0) return 0;
	if (a==b) return a;
	
	if (a>b) {
		return gcd(a-b, b);
	}
	return gcd(a, b-a);
}
