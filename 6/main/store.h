#pragma once
#include "product.h"

typedef struct Store
{
	product ** items;
	int num_of_items;    	 
	char* name;              	
}store;


store* insertProduct(store * s, product * prd);
store* initStore(store* s);
void sortByCode(store* s);
void sortByName(store* s);
int sumstroe(store* s);
int amountByCode(store* s, int code);
void freeStore(store* s);