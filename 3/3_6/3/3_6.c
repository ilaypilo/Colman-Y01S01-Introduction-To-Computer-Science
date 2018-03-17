
/*
Author: Ilay Pilosof
ID: 304961519
Date: 11/12/2016
Purpose: The program check some special behavior in numbers
*/
#include <stdio.h>

int numberOfDividers(int num);
int isPerfect(int num);
int areFriends(int num1, int num2);

void main(){
	int num1,num2;
	// create bool array 0=F 1=T
	char * bool[] = {"False","True"};
	printf("Please enter two numbers:\n");
	scanf("%d%d",&num1,&num2);
	printf("Sum of dividers for the first number: %d\n", numberOfDividers(num1));
	printf("Sum of dividers for the second number: %d\n", numberOfDividers(num2));
	printf("First number is perfect: %s\n", bool[isPerfect(num1)]);
	printf("Second number is perfect: %s\n", bool[isPerfect(num2)]);
	printf("Are friends: %s\n",bool[areFriends(num1,num2)]);
}
// return the sum of a number's dividers
int numberOfDividers(int num){
	int i,sum=0;
	for(i=1;i<num;i++){
		if(num%i==0){
			sum+=i;
		}
	}
	return sum;
}
// if a number equal to his dividers sum, its a perfect number
int isPerfect(int num){
	if(num==numberOfDividers(num)){
		return 1;
	} else {
		return 0;
	}
}
// if the first number is equal to the second number's dividers && the second number equal to the first number's dividers, they called friends
int areFriends(int num1, int num2){
	if(num1==numberOfDividers(num2) && num2==numberOfDividers(num1)){
		return 1;
	} else {
		return 0;
	}
}
