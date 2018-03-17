/*
Author: Ilay Pilosof
ID: 304961519
Date: 12/11/2016
Purpose: The program asks for 2 numbers and calculates thier sum, difference, product, quotient and remainder.
*/

#include <stdio.h>

void main() {
	int num1;
	int num2;
	printf("Input two numbers : ");
	scanf("%d,%d", &num1, &num2);
	// calculates and print sum
	printf("Sum : %d\n", (num1 + num2));
	// calculates and print difference
	printf("Difference : %d\n", abs(num1 - num2));
	// calculates and print product
	printf("Product : %d\n", num1 * num2);
	// calculates and print quotient
	printf("Quotient : %.2f\n", (float)num1 / num2);
	// calculates and print remainder
	printf("Remainder : %d\n", num1 % num2);
}