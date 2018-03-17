/*
Author: Ilay Pilosof
ID: 304961519
Date: 25/12/2016
Purpose: check duplicate numbers
*/
#include <stdio.h>

int main(){
	int size,i,j,duplicates = 0;
	int arr[100];
	int temp[100];
	printf("Please enter array size\n");
	scanf("%d",&size);

	if (size < 1 || size > 100){
		printf("Wrong input\n");
		return 1;
	}
	printf("Please enter all array variables\n");
	for (i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
		temp[arr[i]] = 0;
	}

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (i != j && arr[i] == arr[j] && temp[arr[i]] != 1) {
				temp[arr[i]] = 1;
				duplicates++;
			}
		}
	}
	printf("%d\n", duplicates);

}
