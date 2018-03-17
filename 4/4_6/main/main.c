/*
Author: Ilay Pilosof
ID: 304961519
Date: 25/12/2016
Purpose: check for triangle in a matrix
*/
#include <stdio.h>

int main(){
	int rows,columns,i,j,flag=0;
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
	printf("Please enter all matrix variables\n");
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (i = 0; i < rows; i++) {
		for (j = 1; j < columns -1; j++) {
			if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i + 1][j-1] && arr[i][j] == arr[i + 1][j+1]) {
				flag = 1;
				break;
			}
		}
	}
	printf("%d\n", flag);
	return 0;

}
