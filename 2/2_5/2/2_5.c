/*
Author: Ilay Pilosof
ID: 304961519
Date: 21/11/2016
Purpose: The program calculates the answer for 2 vars equation
*/

#include <stdio.h>
#include <math.h>

void main() {
	double a, b, c, res, root1, root2;
	printf("Input a : ");
	scanf("%lf", &a);
	printf("Input b : ");
	scanf("%lf", &b);
	printf("Input c : ");
	scanf("%lf", &c);
	res = b*b-(4*a*c);
	if (res > 0) {
		root1 = (0 - b + sqrt(res)) / (2 * a);
		root2 = (0 - b - sqrt(res)) / (2 * a);
		if (root1 >= root2) {
			printf("root1: %.2lf\n", root1);
			printf("root2: %.2lf\n", root2);
		}
		else {
			printf("root1: %.2lf\n", root2);
			printf("root2: %.2lf\n", root1);
		}
		
	} 
	else if (res == 0) {
		root1 = (0 - b) / 2 * a;
		printf("Only one root : %.2lf\n", root1);
	}
	else if (res < 0) {
		printf("Equation doesn't have a real root\n");
	}
}