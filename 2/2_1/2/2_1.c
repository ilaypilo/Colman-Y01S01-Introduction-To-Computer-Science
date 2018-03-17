/*
Author: Ilay Pilosof
ID: 304961519
Date: 21/11/2016
Purpose: The program determine if an input char is an Upper letter or Low case letter.
*/

#include <stdio.h>

void main() {
	char letter;
	printf("Input character : ");
	scanf("%c", &letter);
	// check if the letter is low case
	if (letter >= 'a' && letter <= 'z')
		printf("Low case letter\n");
	// check if the letter is Upper case
	else if (letter >= 'A' && letter <= 'Z')
		printf("Upper letter\n");
	else {
		printf("Not a letter\n");
	}
}