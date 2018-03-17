#include "rec.h"
/*
Ex2 - ex6
*/

int sumDigits(int number) {
	if (number / 10 == 0)
		return number;
	return number % 10 + sumDigits(number / 10);
}

int charNExist(char* str, char c) {
	if (strlen(str) == 1)
		return (str[0] == c);
	return (str[0] == c) + charNExist(str+1, c);
}

int	existsInStrings(char* strings[], int size, char ch) {
	if (size <= 1)
		return charNExist(strings[0], ch) != 0;
	return (charNExist(strings[0], ch) != 0) + existsInStrings(strings+1, size-1, ch);
}

int isPalyndrom(char* str, int length) {
	if (length == 2)
		return (str[0] == str[length - 1]);
	if (length <= 1)
		return 1;
	return ((str[0] == str[length - 1]) == isPalyndrom(str + 1, length - 2));
}

int swapIfCapital(char* A, char* B) {
	if (A[0] >= 'A' && A[0] <= 'Z') {
		B[0] = A[0];
		return 1;
	}
	return 0;
}
int copyUpperCase(const char* A, char* B) {
	if (strlen(A) == 1)
		return swapIfCapital(A,B);
	return (swapIfCapital(A, B) + copyUpperCase(A+1,B+1));
}