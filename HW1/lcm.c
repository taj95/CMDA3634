//Least Common Multiple function
#include <stdlib.h>
#include <stdio.h>

int lcm(int, int);
int gcd(int, int);

void main() {
	int x;
	int y;

	printf("Enter the first number: ");
	scanf("%d", &x);
	printf("Enter the second number: ");
	scanf("%d", &y);

	int out = lcm(x, y);
	printf("The least common multiple of %d and %d is %d.\n", x, y, out);

}

int lcm(int a, int b) {
	return (a*b)/(gcd(a,b));
}

int gcd(int a, int b) {
	if (a==0 || b==0) return 0;
	if (a==b) return a;
	
	if (a>b) return gcd(a-b, b);
	return gcd(a, b-a);
}
