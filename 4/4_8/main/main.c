/*
Author: Ilay Pilosof
ID: 304961519
Date: 25/12/2016
Purpose: switch every two chars
*/
#include <stdio.h>

int main(){
	char letter,str[100];
	int i=0;
	printf("Please enter string\n");
	gets(str);
	while (str[i] != '\0' && str[i+1] != '\0') {
		printf("%c%c", str[i+1], str[i]);
		i+=2;
	}
	if (str[i] != '\0' && str[i + 1] == '\0')
		printf("%c", str[i]);
	printf("\n");
	return 0;
}
