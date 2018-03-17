/*
Author: Ilay Pilosof
ID: 304961519
Date: 12/11/2016
Purpose: The program converts Celsius to Fahrenheit
*/

#include <stdio.h>

void main() {
	float celsius;
	printf("Input Celsius : ");
	scanf("%f", &celsius);
	printf("Fahrenheit : %.2f\n", (celsius * 9/5 +32));

}