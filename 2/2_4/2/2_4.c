/*
Author: Ilay Pilosof
ID: 304961519
Date: 21/11/2016
Purpose: The program asks for 2 numbers, and determine if they are build from the same digits
*/

#include <stdio.h>

void main() {
	int num1, num2;
	printf("Input numbers : ");
	scanf("%d,%d", &num1, &num2);
	// check if the numbers are the same or if the digits are the same
	if (num1 > 99 || num1 < 10 || num2 > 99 || num2 < 10) {
		printf("Invalid Input\n");
	} else if (num1 == num2 || (num1 % 10 == (num2 / 10 % 10) && num2 % 10 == (num1 / 10 % 10))) {
		printf("Same digits\n");
	}
	else {
		printf("Not the same digits\n");
	}

}