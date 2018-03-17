/*
Author: Ilay Pilosof
ID: 304961519
Date: 11/12/2016
Purpose: The program prints a chars pyramide in a jump of 2 letters
*/
#include <stdio.h>

void main(){
	int i,j;
	char letter;
	printf("Please enter a letter:\n");
	scanf("%c",&letter);
	// check if input is "a"+2^n (not a pair)
	if(letter % 2 == 0 || letter<'a' || letter >'z'){
		printf("Invalid Input");
	} else {
		// loop on letters, jump 2 letters (97 is "a")
		for(i=1;i+96<=letter;i+=2){
			// print the indention
			for(j=letter-i;j>96;j-=2){
				printf(" ");
			}
			// print the letter*index
			for(j=0;j<i;j++){
				printf("%c", i+96);
			}
			// new row for each letter
			printf("\n");
		}
	}
}
