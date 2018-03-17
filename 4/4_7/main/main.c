/*
Author: Ilay Pilosof
ID: 304961519
Date: 25/12/2016
Purpose: remove a letter from string
*/
#include <stdio.h>

int main(){
	char letter,str[100];
	int i=0;
	printf("Please enter string\n");
	gets(str);
	printf("Please enter letter\n");
	scanf("%c", &letter);
	while (str[i] != '\0') {
		if (str[i] != letter)
			printf("%c", str[i]);
		i++;
	}
	printf("\n");
	return 0;
}
