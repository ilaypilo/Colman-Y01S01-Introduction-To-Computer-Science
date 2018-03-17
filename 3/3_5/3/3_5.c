/*
Author: Ilay Pilosof
ID: 304961519
Date: 11/12/2016
Purpose: The program check if a number contains a second number and print the index it's appear.
*/
#include <stdio.h>

int contains(int num1, int num2);
void main(){
	int num1,num2;
	printf("Please enter number 1:\n");
	scanf("%d",&num1);
	printf("Please enter number 2:\n");
	scanf("%d",&num2);
	// print the index if contains, if not print -1 
	printf("%d", contains(num1,num2));
}

int contains(int num1, int num2){
	int temp1,temp2,index=-1,tempI;
	do {
		// save the numbers in diff vars so we could iteraite on them
		temp1 = num1;
		temp2 = num2;
		tempI = index;
		do {
			// check if the right digit is equal
			if(temp1%10 != temp2%10){
				tempI=-1;
				break;
			}
			// if equal, remove right digit
			temp1 /=10;
			temp2 /=10;
			// inc the index
			tempI+=1;
		// repate until num2 is fully compared
		} while(temp2>0);
		// if the num2 is in num1, break and return index
		if(tempI!=-1){
			break;
		}
		// remove the right digit of num1
		num1 /= 10;
		index += 1;
		// if there are more digits in num1 repeat
	} while(num1>0);
	return tempI;
}
