/*
Author: Ilay Pilosof
ID: 304961519
Date: 12/11/2016
Purpose: The program calculates the total number of minutes
*/

#include <stdio.h>

void main() {
	int hours;
	int minutes;
	printf("Input hours : ");
	scanf("%d", &hours);
	printf("Input minutes : ");
	scanf("%d", &minutes);
	// convert the hours to minutes, adding the minutes and print it
	printf("Total : %d\n", (hours * 60 + minutes));

}