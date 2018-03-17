/*
Author: Ilay Pilosof
ID: 304961519
Date: 11/12/2016
Purpose: The program checks if it is a prime number
*/
#include <stdio.h>

void main(){
	int i,num,dividers=0;
	printf("Please enter a number:\n");
	scanf("%d",&num);
	if(num<0){
	 printf("Invalid input.\n");
	} else {
		// count number dividers exclude itself
		for(i=1;i<num;i++){
			if(num % i == 0){
				dividers += 1;
			}
		}
		// if only 1 dividers its prime number
		if(dividers==1){
			printf("True\n");
		} else {
			printf("False\n");
		}
	}
}
