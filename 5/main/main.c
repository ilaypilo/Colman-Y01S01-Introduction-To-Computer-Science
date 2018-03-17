//
//  Created by Yossi Adi on 04/01/2017.
//  Copyright © 2017 Yossi Adi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define SIZE_A 5
#define SIZE_B 5
#define SIZE_INTER 3
#define SIZE_UNITE 7
#define SIZE_MINUS 2
#define SIZE_XOR 4

int validate_sets(int* A, int* B, int size_a, int size_b);
void print_error(int e, char* s);



/*
Ilay Pilosof
304961519
09.01.17
The program prints....
*/


// help functions
int myStrLen(char *s);
char *myStrCpy(char *t, const char* s);
int myStrCmp(char* s, char* t);

// ex funcitons
//1
int SumStr(char* str);
// 2a
void Strcat(char* t, char* s);
// 2b
int Strend(char* t, char* s);
// 3
int* intersect(int* A, int sizeA, int* B, int sizeB, int* sizeAintB);
int* unite(int* A, int sizeA, int* B, int sizeB, int* sizeAuniteB);
int* minus(int* A, int sizeA, int* B, int sizeB, int* sizeAminB);
int* xor(int* A, int sizeA, int* B, int sizeB, int* sizeAxorB);

//
//int main() {
//	char str1[100], str2[100];
//	int *arr;
//	int i;
//	int A[] = { 1,2,3,4,5,1,2 };
//	int B[] = { 2,5,8,9,0,1,1,1,1,1,1,3,2 };
//	int arrSize = 0;
//	printf("1,2,3,4,5,1,2\n");
//	printf("2,5,8,9,0,1,1,1,1,1,1,3,2\n");
//	arr = intersect(A, 7, B, 13, &arrSize);
//	for (i = 0; i < arrSize; i++)
//		printf("%d ", arr[i]);
//	printf("\nSize: %d\n", arrSize);
//
//	arr = unite(A, 7, B, 13, &arrSize);
//	for (i = 0; i < arrSize; i++)
//		printf("%d ", arr[i]);
//	printf("\nSize: %d\n", arrSize);
//
//	arr = minus(A, 7, B, 13, &arrSize);
//	for (i = 0; i < arrSize; i++)
//		printf("%d ", arr[i]);
//	printf("\nSize: %d\n", arrSize);
//
//	arr = xor (A, 7, B, 13, &arrSize);
//	for (i = 0; i < arrSize; i++)
//		printf("%d ", arr[i]);
//	printf("\nSize: %d\n", arrSize);
//
//	//scanf("%s",str1);
//	//scanf("%s", str2);
//	//printf("%d", SumStr(str1));
//	//Strcat(str1, str2);
//	//printf("%s", str1);
//	//printf("%d", Strend(str1, str2));
//	return 0;
//}
int main() {

	int res;
	char str_1[SIZE] = "Yossi";
	char str_2[SIZE] = " Adi";

	//=============== EX 1 ================//
	res = SumStr("f11mt5b3ax");
	if (res != 19)
		printf("Failed Ex1 - SumStr function\n");

	//=============== EX 2a ===============//
	Strcat(str_1, str_2);
	if (strcmp("Yossi Adi", str_1))
		printf("Failed Ex2A - Strcat function\n");

	//=============== EX 2b ===============//
	res = Strend("Winston", "on");
	if (res != 1)
		printf("Failed Ex2B - Strend function\n");


	//=============== EX 3 ===============//
	int A[SIZE_A] = { 1, 2, 3, 4, 5 };
	int B[SIZE_B] = { 1, 0, -1, 2, 4 };

	int res_intersect[SIZE_INTER] = { 1, 2, 4 };
	int res_unite[SIZE_UNITE] = { 1, 2, 3, 4, 5, 0, -1 };
	int res_minus[SIZE_MINUS] = { 3, 5 };
	int res_xor[SIZE_XOR] = { 3, 5, 0, -1 };

	int res_size;
	int* res_set = NULL;

	//=============== EX 3a ===============//
	res_set = intersect(A, SIZE_A, B, SIZE_B, &res_size);
	int e = validate_sets(res_intersect, res_set, res_size, SIZE_INTER);
	print_error(e, "EX3A");
	free(res_set);

	//=============== EX 3b ===============//
	res_set = unite(A, SIZE_A, B, SIZE_B, &res_size);
	e = validate_sets(res_unite, res_set, res_size, SIZE_UNITE);
	print_error(e, "EX3B");
	free(res_set);

	//=============== EX 3c ===============//
	res_set = minus(A, SIZE_A, B, SIZE_B, &res_size);
	e = validate_sets(res_minus, res_set, res_size, SIZE_MINUS);
	print_error(e, "EX3C");
	free(res_set);

	//=============== EX 3d ===============//
	res_set = xor (A, SIZE_A, B, SIZE_B, &res_size);
	e = validate_sets(res_xor, res_set, res_size, SIZE_XOR);
	print_error(e, "EX3D");
	free(res_set);

	printf("Done.\n");
	return 0;
}

void print_error(int e, char* s)
{
	if (e == -1)
		printf("Failed %s - wrong set size\n", s);
	else if (e == -2)
		printf("Failed %s - sets does not match\n", s);
}

int validate_sets(int* A, int* B, int size_a, int size_b)
{
	int i, j;
	if (size_a != size_b)
		return -1;

	for (i = 0; i<size_a; i++) {
		int flag = 0;
		for (j = 0; j<size_b; j++) {
			if (A[i] == B[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			return -2;
		}
	}

	return 1;
}
// help functions

//strlen
int myStrLen(char *s) {
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}
//strcpy
char *myStrCpy(char *t, const char* s) {
	char *ret = t;
	while (*t++ = *s++);
	return ret;
}
//strcmp
int myStrCmp(char* s, char* t)
{
	int length;
	length = myStrLen(s);
	while (length--)
		if (*s++ != *t++)
			return 0;
	return 1;
}

// ex functions
// 1
int SumStr(char* str) {
	int i, sum = 0;
	for (i = 0; i < myStrLen(str); i++) {
		if (str[i] > '0' && str[i] <= '9') {
			if (i + 1 < myStrLen(str) && i + 2 < myStrLen(str) && str[i + 1] > '0' && str[i + 1] <= '9' && str[i + 2] > '0' && str[i + 2] <= '9') {
				sum += (str[i] - 48) * 100;
			} else if (i+1 < myStrLen(str) && str[i+1] > '0' && str[i + 1] <= '9') {
				sum += (str[i] - 48)*10;
			}
			else {
				sum += str[i] - 48;
			}

		}
	}
	return sum;
}
// 2a
void Strcat(char* t, char* s) {
	// copy s to the end of t
	myStrCpy(t + (myStrLen(t)), s);
}
// 2b
int Strend(char* t, char* s) {
	int i, result;
	// check if the end of t is equal to s
	return myStrCmp(t + (myStrLen(t) - myStrLen(s)), s);
}

// 3

/*
dtepwvid intersect ngyaz `z dgizej yl yzi dwaevez A,B .dgizej yl A e-B
nebcx kwaevz kl d`iaxim dnyeztim l-A el-B ,klenx pnv`im bm a-A ebm a-B - ll` gfxez yl
nqtxim.
*/
int* intersect(int* A, int sizeA, int* B, int sizeB, int* sizeAintB) {
	int *newArr;
	int i, j, k, flag, count = 0;
	newArr = malloc((sizeA) * sizeof(int));
	if (newArr == NULL) {
		printf("Allocation error\n");
		exit(0);
	}
	for (i = 0; i < sizeA; i++) {
		//iterate first arr
		for (j = 0; j < sizeB; j++) {
			//iterate second arr
			if (A[i] == B[j]) {
				// check if the number was already added to the array
				flag = 1;
				for (k = 0; k < count; k++) {
					if (newArr[k] == A[i]) {
						flag = 0;
					}
				}
				// if it's a new number add it to the array
				if (flag != 0) {
					newArr[count] = A[i];
					count++;
				}
			}
		}
	}
	// update the arr size
	*sizeAintB = count;
	return newArr;
}

/*
dtepwvid unite ngyaz `z d`igec yl yzi dwaevez A,B .d`igec yl A e-B nebcx
kwaevz kl d`iaxim a-A ea-B - ll` gfxez yl nqtxim.
*/
int* unite(int* A, int sizeA, int* B, int sizeB, int* sizeAuniteB) {
	int *newArr;
	int i, j, k, flag, count = 0;
	newArr = malloc((sizeA + sizeB) * sizeof(int));
	if (newArr == NULL) {
		printf("Allocation error\n");
		exit(0);
	}
	//iterate first arr
	for (i = 0; i < sizeA; i++) {
		// check if the number was already added to the array
		flag = 1;
		for (k = 0; k < count; k++) {
			if (newArr[k] == A[i]) {
				flag = 0;
			}
		}
		// if it's a new number add it to the array
		if (flag != 0) {
			newArr[count] = A[i];
			count++;
		}
	}
	//iterate second arr
	for (i = 0; i < sizeB; i++) {
		// check if the number was already added to the array
		flag = 1;
		for (k = 0; k < count; k++) {
			if (newArr[k] == B[i]) {
				flag = 0;
			}
		}
		// if it's a new number add it to the array
		if (flag != 0) {
			newArr[count] = B[i];
			count++;
		}
	}

	// update the arr size
	*sizeAuniteB = count;
	return newArr;
}

/*
dtepwvid minus ngyaz `z ddtxy B-A .ddtxy B-A nebcx kwaevz kl d`iaxim
dpnv`im awaevd A `al l` pnv`im awaevd B  ll` gfxez yl nqtxim.
*/
int* minus(int* A, int sizeA, int* B, int sizeB, int* sizeAminB) {
	int *newArr;
	int i, j, k, flag, twiceFlag, count = 0;
	newArr = malloc((sizeA) * sizeof(int));
	if (newArr == NULL) {
		printf("Allocation error\n");
		exit(0);
	}
	//iterate on A
	for (i = 0; i < sizeA; i++) {
		// assume number is unique
		flag = 0;
		//iterate on B
		for (j = 0; j < sizeB; j++) {
			if (A[i] == B[j]) {
				// check if the number from A exsit in B
				flag = 1;
				break;
			}
		}
		// number is unique
		if (flag == 0) {
			twiceFlag = 0;
			for (k = 0; k < count; k++) {
				// check if not exsit on our arr
				if (newArr[k] == A[i]) {
					twiceFlag = 1;
				}
			}
			if (twiceFlag == 0) {
				newArr[count] = A[i];
				count++;
			}

		}
	}
	// update the arr size
	*sizeAminB = count;
	return newArr;
}

/*
dtepwvid xor ngyaz `z ddtxy dqinhxi yl A e-B .ddtxy dqinhxi yl A e-B
nebcx kwaevz kl d`iaxim dpnv`im aciew a`gz no dwaevez, A `e B .kci
lnny tepwvid nenlu ldyzny atepwviez nqritim wecnim.
*/
int* xor(int* A, int sizeA, int* B, int sizeB, int* sizeAxorB) {
	int *newArr;
	int i, j, k, flag, twiceFlag, count = 0;
	newArr = malloc((sizeA + sizeB) * sizeof(int));
	if (newArr == NULL) {
		printf("Allocation error\n");
		exit(0);
	}
	//iterate on A
	for (i = 0; i < sizeA; i++) {
		// assume number is unique
		flag = 0;
		//iterate on B
		for (j = 0; j < sizeB; j++) {
			if (A[i] == B[j]) {
				// check if the number from A exsit in B
				flag = 1;
				break;
			}
		}
		// number is unique
		if (flag == 0) {
			twiceFlag = 0;
			for (k = 0; k < count; k++) {
				// check if not exsit on our arr
				if (newArr[k] == A[i]) {
					twiceFlag = 1;
				}
			}
			if (twiceFlag == 0) {
				newArr[count] = A[i];
				count++;
			}

		}
	}
	for (i = 0; i < sizeB; i++) {
		// assume number is unique
		flag = 0;
		//iterate on B
		for (j = 0; j < sizeA; j++) {
			if (B[i] == A[j]) {
				// check if the number from A exsit in B
				flag = 1;
				break;
			}
		}
		// number is unique
		if (flag == 0) {
			twiceFlag = 0;
			for (k = 0; k < count; k++) {
				// check if not exsit on our arr
				if (newArr[k] == B[i]) {
					twiceFlag = 1;
				}
			}
			if (twiceFlag == 0) {
				newArr[count] = B[i];
				count++;
			}

		}
	}
	// update the arr size
	*sizeAxorB = count;
	return newArr;
}