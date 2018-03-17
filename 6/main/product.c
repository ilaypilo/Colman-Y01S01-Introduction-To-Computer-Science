/*
product implementation
*/

#include "product.h"


product* createItem(product* p) {
	product* newProduct = malloc(sizeof(product));
	if (newProduct == NULL) return NULL;
	newProduct->name = malloc(strlen(p->name));
	if (newProduct->name == NULL) return NULL;
	// copy the product
	newProduct->name = p->name;
	newProduct->code = p->code;
	newProduct->amount = p->amount;
	return newProduct;
}

product* createItem1(char* name, int code, int amount) {
	product* newProduct = malloc(sizeof(product));
	if (newProduct == NULL) return NULL;
	newProduct->name = malloc(strlen(name)+1);
	if (newProduct->name == NULL) return NULL;
	// building the product
	strcpy(newProduct->name, name);
	newProduct->code = code;
	newProduct->amount = amount;
	return newProduct;
}

void swapProduct(product* p1, product* p2) {
	product* tempProduct = malloc(sizeof(product));
	if (tempProduct == NULL) return NULL;
	// building the product
	*tempProduct = *p1;
	*p1 = *p2;
	*p2 = *tempProduct;
}

void freeProduct(product* p) {
	//free(p->name); // TODO why its not freeing?
	free(p);
}