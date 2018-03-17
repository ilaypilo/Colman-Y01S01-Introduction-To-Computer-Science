/*
Author: Ilay Pilosof
ID: 304961519
Date: 25/12/2016
Purpose: sort an array of numbers
*/
#include <stdio.h>

int main(){
	int size,i,j,temp;
	int arr[100];
	printf("Please enter array size\n");
	scanf("%d",&size);

	if (size < 1 || size > 100){
		printf("Wrong input\n");
		return 1;
	}
	printf("Please enter all array variables\n");
	for (i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < size-1; i++) {
		for (j = 0; j < size-1; j++) {
			if (arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

}
