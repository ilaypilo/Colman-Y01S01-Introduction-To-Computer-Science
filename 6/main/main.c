//
//  Created by Inbal Avraham
//  Copyright © 2017 Inbal Avraham. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
#include "store.h"
#include "product.h"
#include "rec.h"

int compareP(product* p1, product* p2)
{
	return (p1->code == p2->code && p1->amount == p2->amount && (strcmp(p1->name, p2->name) == 0));
}
int compareS(store* s1, store* s2)
{
	//check by code
	int i;
	if (s1->num_of_items != s2->num_of_items)
		return 0;
	for (i = 0; i < s1->num_of_items; i++)
	{
		if (s1->items[i]->code != s2->items[i]->code)
			return 0;
	}
	return 1;
}

int compareA(store * s, int * arr)
{
	//check by code
	int * codes = (int*)malloc(sizeof(int)*(s->num_of_items));
	for (int i = 0; i < s->num_of_items; i++)
		codes[i] = s->items[i]->code;
	for (int i = 0; i < s->num_of_items; i++)
	{
		if (codes[i] != arr[i])
			return 0;
	}
	return 1;
}
int checkInsert(store* tmpStore, int code)
{
	return (tmpStore->items[0]->code == code);
}

int main()
{
	         
	//===============variables definitionsr EX 2 ===============//
	int sum = 0, code = 425, cnt;
	int code1 = 425, code2 = 1764, code3 = 3654, code4 = 897, code5 = 425;
	int arr1[] = { code1, code4, code2, code3 };
	int arr2[] = { code3, code1, code4, code2 };
	int arr3[] = { 3654, 425, 897, 1764 };

	product pr1 = { "milk", code1, 30 };
	product pr2 = { "salt", code2, 25 };
	product pr3 = { "cheese", code3, 32 };
	product pr4 = { "pepper", code4, 20 };
	product pr5 = { "milk", code5, 15 };
	product * pItem[3] = { &pr1, &pr2, &pr3 };
	product * pItem2[4] = { &pr1, &pr2, &pr3,&pr4 };
	store s = { pItem, 3, "Supergal" };
	store s2 = { pItem2, 4, "Super4All"};
	store *tmpStore = NULL, *myStore;
	product* p1, *p2;


	//===============variables definitionsr EX 2 ===============//
	int number ;
	int sumD ;

	//=============== variables definitions for EX 3 ===============//
	char str3[SIZE] = "this is a test";
	char ch3 = 't';
	int num;
	//=============== dvariables definitions for EX 4 ===============//
	char* strings[] = { "summer", "winter", "spring" };
	char ch4 = 'a';
	int size = 3;
	int exists;
	//=============== variables definitions for EX 5 ===============//
	char str[SIZE] = "abcdcba";
	int res;
	//=============== variables definitions for EX 6 ===============//
	const char A[SIZE] = "StUdEnT";
	char B[SIZE];
	int num6;

	//------------------------------------------------------------------------------------------------------------
	//=============== EX 1 ================//    
	//p1 = createItem(&pr1);
	//if (compareP(&pr1, p1) == 0)
	//	printf("Failed Ex1A - createItem function\n");
	//else
	//	printf("createItem done\n");

	////---------------------------------------------------------

	//p2 = createItem1("salt", 1764, 25);
	//if (compareP(&pr2, p2) == 0)
	//	printf("Failed Ex2A - createItem1 function\n");
	//else
	//	printf("createItem1 done\n");

	////---------------------------------------------------------

	//tmpStore = insertProduct(tmpStore, &pr1);
	//if (checkInsert(tmpStore, pr1.code) == 0)
	//	printf("Failed Ex1C - insertProduct function\n");
	//else
	//	printf("insertProduct done\n");

	////---------------------------------------------------------

	//myStore = initStore(&s);
	//if (compareS(&s, myStore) == 0)
	//	printf("Failed Ex1D - initStore function\n");
	//else
	//	printf("initStore done\n");


	//////---------------------------------------------------------

	//sortByCode(&s2);
	//if (compareA(&s2, arr1) == 0)
	//	printf("Failed Ex1E - sortByCode function\n");
	//else
	//	printf("sortByCode done\n");

	//////---------------------------------------------------------

	////printStore(&s2);
	//sortByName(&s2);
	//if (compareA(&s2, arr2) == 0)
	//	printf("Failed Ex1F - sortByName function\n");
	//else
	//	printf("sortByName done\n");
	////printStore(&s2);

	//////---------------------------------------------------------

	//sum = sumstroe(&s2);
	//if (sum!=107)
	//	printf("Failed Ex1G - sumstroe function\n");
	//else
	//	printf("sumstroe done\n");
	////printf("\nThe sum of products in the store is %d\n", sum);

	//////---------------------------------------------------------

	//cnt = amountByCode(&s2, code);
	//if (cnt != 30)
	//	printf("Failed Ex1H - amountByCode function\n");
	//else
	//	printf("amountByCode done\n");

	//freeStore(myStore);
	//printf("FreeStore done\n");

	//
	////=============== EX 2 ===============//
	number = 9845;
	sumD = sumDigits(number);
	if (sumD != 26)
		printf("Failed Ex2 - sumDigits function\n");
	else
		printf("sumDigits done\n");
	
	//=============== EX 3 ===============//    

	num = charNExist(str3, ch3);
	if (num != 3)
		printf("Failed Ex3 - charNExist function\n");
	else
		printf("charNExist done\n");
	
	//=============== EX 4 ===============//
	exists = existsInStrings(strings, size, ch4);
	if (exists != 0)
		printf("Failed Ex4 - existsInStrings function\n");
	else
		printf("existsInStrings done\n");
	
	//=============== EX 5  ===============//
	res = isPalyndrom(str, strlen(str));
	if (res == 0)
		printf("Failed Ex5 - isPalyndrom function\n");
	else
		printf("isPalyndrom done\n");

	//=============== EX 6 ===============//
	 num6 = copyUpperCase(A, B);
	if (num6 != 4)
		printf("Failed Ex6 - copyUpperCase function\n");
	else
		printf("copyUpperCase done\n");
	printf("Done.\n");
	return 0;
}