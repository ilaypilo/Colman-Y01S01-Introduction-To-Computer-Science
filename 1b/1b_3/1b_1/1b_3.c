/*
Author: Ilay Pilosof
ID: 304961519
Date: 12/11/2016
Purpose: The program calculates the perimeter of a rectangle from height and width
*/

#include <stdio.h>

void main() {
	float height;
	float width;
	printf("Input height : ");
	scanf("%f", &height);
	printf("Input width : ");
	scanf("%f", &width);
	// calculate the perimeter and print it
	printf("Perimeter : %.2f\n", (height * 2 + width * 2));

}