/*
Author: Ilay Pilosof
ID: 304961519
Date: 25/12/2016
Purpose: sort an array of odd and even numbers
*/
#include <stdio.h>
#define MAX_INT 500
int main(){
	int size, i, j, k=0, l=0, temp, min = MAX_INT;
	int arr[100];
	int odd[100];
	int even[100];
	printf("Please enter array size\n");
	scanf("%d",&size);

	if (size < 1 || size > 100){
		printf("Wrong input\n");
		return 1;
	}
	printf("Please enter all array variables\n");
	for (i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] < min) {
			min = arr[i];
		}
		// check if odd or even and insert it to the array
		if (arr[i] % 2 == 0) {
			even[k] = arr[i];
			k++;
		}
		else {
			odd[l] = arr[i];
			l++;
		}

	}
	// sort even
	for (i = 0; i < k-1; i++) {
		for (j = 0; j < k-1; j++) {
			if (even[j] > even[j+1]) {
				temp = even[j];
				even[j] = even[j+1];
				even[j+1] = temp;
			}
		}
	}
	// sort odd
	for (i = 0; i < l - 1; i++) {
		for (j = 0; j < l - 1; j++) {
			if (odd[j] > odd[j + 1]) {
				temp = odd[j];
				odd[j] = odd[j + 1];
				odd[j + 1] = temp;
			}
		}
	}

	if (min % 2 == 0) {
		for (i = 0; i < k; i++) {
			printf("%d ", even[i]);
		}
		for (i = 0; i < l; i++) {
			printf("%d ", odd[i]);
		}
	}
	else {
		for (i = 0; i < l; i++) {
			printf("%d ", odd[i]);
		}
		for (i = 0; i < k; i++) {
			printf("%d ", even[i]);
		}
	}
	printf("\n");
	return 0;

}
