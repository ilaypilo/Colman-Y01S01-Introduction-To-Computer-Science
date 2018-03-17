/*
Author: Ilay Pilosof
ID: 304961519
Date: 11/12/2016
Purpose: The program sum a number digits until one digit left
*/
#include <stdio.h>

void main(){
	int i,num,sum;
	printf("Please enter a number:\n");
	scanf("%d",&num);
	if(num<0){
	 printf("Invalid input.");
	} else {
		do {
			sum = 0;
			do
			{
				// sum the number digits
				sum += num % 10;
				num /= 10;
			} while(num>0);
			num = sum;
			//if the sum has more then 1 digit, sum again
		} while(num>9);
		printf("%d", sum);
	}
}
