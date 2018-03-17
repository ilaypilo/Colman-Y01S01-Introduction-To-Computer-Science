/*
Author: Ilay Pilosof
ID: 304961519
Date: 12/11/2016
Purpose: The program converts kilometers to miles
*/

#include <stdio.h>

void main() {
	float kilometers;
	printf("Input kilometers : ");
	scanf("%f", &kilometers);
	// convert to miles and print it
	printf("Miles : %.2f\n", (kilometers * 0.62137119));

}