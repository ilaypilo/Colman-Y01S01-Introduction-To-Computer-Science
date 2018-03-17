#include <stdio.h>

long int dec2bin(long int dec);
int bin2dec(int bin);

int main() {
	printf("%ld\n", dec2bin(1024));
}


long int dec2bin(long int dec) {
	if (!dec) return 0;
	return (dec % 2) + 10 * dec2bin(dec / 2);
}

int bin2dec(int bin) {
	if (!bin) return 0;
	return (bin % 10) + 2 * bin2dec(bin / 10);
}