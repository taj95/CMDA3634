//Finds the first generator of the given prime number
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int findGen(int);

void main() {
	int x;

	printf("Enter a prime number: ");
	scanf("%d", &x);

	int out = findGen(x);
	printf("%d is a generator of Z_%d.\n", out, x);
}

int findGen(int x) {
	bool found;
	for (int g = 2; g<x; g++) {
		found = true;
		for (int r=1; r<x-1; r++) {
			int res = (long)pow((double) g, (double) r)%x;
			//printf("g: %d, r: %d, res: %d\n", g, r, res);
			if (res==1) {
				//printf("%d"pow(g,r));
				found = false;
				break; //g is not a generator so skip to the next
			}
		}
		if (found) {
			return g;
		}
	}
	return -1; //nothing was found
}
