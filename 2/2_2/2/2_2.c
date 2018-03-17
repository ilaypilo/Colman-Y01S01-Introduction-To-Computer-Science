/*
Author: Ilay Pilosof
ID: 304961519
Date: 21/11/2016
Purpose: The program determine if input sides can build trinagle, and what does it type.
*/

#include <stdio.h>

void main() {
	int side1, side2, side3;
	printf("Input sides : ");
	scanf("%d,%d,%d", &side1, &side2, &side3);
	// check if it possible to build a triangle
	if (side1 + side2 < side3 || side2 + side3 < side1 || side1 + side3 < side2)
		printf("Not a triangle\n");
	// check if the triangle is equilateral triangle
	else if (side1 == side2 && side2 == side3)
		printf("equilateral triangle\n");
	// check if the triangle is An isosceles triangle
	else if (side1 == side2 && side1 != side3 || side1 == side3 && side1 != side2 || side2 == side3 && side2 != side1)
		printf("An isosceles triangle\n");
	// check if the triangle has different sides
	else if (side1 != side2 && side1 != side3)
		printf("Different sides of a triangle\n");
}