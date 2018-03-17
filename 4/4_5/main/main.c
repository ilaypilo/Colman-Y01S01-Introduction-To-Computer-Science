/*
Author: Ilay Pilosof
ID: 304961519
Date: 25/12/2016
Purpose: replace the crosses in a matrix
*/
#include <stdio.h>

int main(){
	int rows,columns,i,j,k=0,l=0,temp;
	int arr[100][100];
	printf("Please enter matrix rows\n");
	scanf("%d",&rows);
	if (rows < 1 || rows > 100) {
		printf("Wrong input\n");
		return 1;
	}
	printf("Please enter matrix columns\n");
	scanf("%d", &columns);
	if (columns < 1 || columns > 100) {
		printf("Wrong input\n");
		return 1;
	}
	if (rows != columns) {
		printf("Wrong input\n");
		return 1;
	}
	printf("Please enter all matrix variables\n");
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 0; i < rows; i++) {
		temp = arr[i][i];
		arr[i][i] = arr[i][(columns - i - 1)];
		arr[i][(columns - i - 1)] = temp;
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;

}
