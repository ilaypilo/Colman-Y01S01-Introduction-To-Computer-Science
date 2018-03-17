#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int speicalMatrix(int i,int j);

int main() {
	printf("%d\n", speicalMatrix(5,4));
}

int speicalMatrix(int i, int j) {
	if (i == 1) return 1;
	if (j == 1) return 1;
	return speicalMatrix(i - 1, j) + speicalMatrix(i, j - 1)+ speicalMatrix(i-1,j-1);
}