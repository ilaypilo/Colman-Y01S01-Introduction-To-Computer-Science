#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Product
{
	char* name;
	int  code; 
	int amount;
}product;



product* createItem(product* p);
product* createItem1(char* name, int code, int amount);
void swapProduct(product* p1, product* p2);
void freeProduct(product* p);