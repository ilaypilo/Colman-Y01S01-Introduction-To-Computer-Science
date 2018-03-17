/*
Author: Ilay Pilosof
ID: 304961519
Date: 21/11/2016
Purpose: The program asks for 3 grades, and determine student status for next year
*/

#include <stdio.h>

void main() {
	int grade1, grade2, grade3;
	printf("Students' grades : ");
	scanf("%d,%d,%d", &grade1, &grade2, &grade3);
	// Input validation
	if (grade1 < 0 || grade1 > 100 || grade2 < 0 || grade2 > 100 || grade3 < 0 || grade3 > 100) {
		printf("Invalid Input\n");
	} 
	// check if Move To Third Year
	else if (grade1 == 100 && grade2 >= 95 && grade3 >= 95 || grade1 >= 95 && grade2 == 100 && grade3 >= 95 || grade1 >= 95 && grade2 >= 95 && grade3 == 100) {
		printf("Move To Third Year\n");
	}
	// check if Move To Second Year
	else if (grade1 >= 60 && grade2 >= 60 || grade1 >= 60 && grade3 >= 60 || grade2 >= 60 && grade3 >= 60) {
		printf("Move To Second Year\n");
	}
	// check if Stay in First Year
	else if (grade1 > 60 || grade2 > 60 || grade3 > 60) {
		printf("Stay in First Year\n");
	}
	// else Go Home
	else {
		printf("Go Home\n");
	}

}