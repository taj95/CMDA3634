//Homework 1 Question 1: Generator

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void generator(int, int);

void main() {
	generator(2, 13);
	generator(6, 13);
	generator(7, 13);
	generator(11, 13);
}

void generator(int g, int p) {
	printf("Generator is: %d\n", g);
	int x = 1;
	while(x<=p-1) {
		int out = (long)pow((double) g,(double) x)%p;
		printf("(%d^%d)mod %d is: %d\n", g, x, p, out);
		x++;
	}

}
