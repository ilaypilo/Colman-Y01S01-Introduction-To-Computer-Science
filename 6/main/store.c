/*
Store implementation
*/

#include "store.h"

store* insertProduct(store * s, product * prd) {
	int i, newItemFlag=1;
	if (s == NULL) {
		store* newStore = (store*)malloc(sizeof(store));
		if (newStore == NULL) return NULL;
		newStore->name = "Super";
		newStore->num_of_items = 1;
		newStore->items = (product**)malloc(sizeof(product**));
		if (newStore->items == NULL) return NULL;
		newStore->items[0] = (product*)malloc(sizeof(product*));
		if (newStore->items[0] == NULL) return NULL;
		newStore->items[0] = createItem(prd);
		return newStore;
	} 
	else {
		for (i = 0;i < s->num_of_items;i++) {
			if (s->items[i]->code == prd->code){
				s->items[i]->amount += prd->amount;
				newItemFlag = 0;
			}
		}
		if (newItemFlag == 1) {
			store* updateStore = (store*)malloc(sizeof(store));
			if (updateStore == NULL) return s;
			updateStore = s;
			updateStore->items = (product**)realloc(updateStore->items, sizeof(product**)*(updateStore->num_of_items + 1));
			if (updateStore == NULL) return s;
			updateStore->items[(updateStore->num_of_items)] = createItem(prd);
			updateStore->num_of_items++;
		}
	}
}

store* initStore(store* s) {
	int i;
	store* newStore = (store*)malloc(sizeof(store));
	if (newStore == NULL) return NULL;
	newStore->name = (char*)malloc(strlen(s->name)+1);
	strcpy(newStore->name, s->name);
	newStore->num_of_items = s->num_of_items;
	newStore->items = (product**)malloc(sizeof(product**)*(s->num_of_items));
	if (newStore->items == NULL) return NULL;
	for (i = 0;i < s->num_of_items;i++) {
		newStore->items[i] = (product*)malloc(sizeof(product*));
		if (newStore->items[i] == NULL) return NULL;
		newStore->items[i] = createItem1(s->items[i]->name, s->items[i]->code, s->items[i]->amount);
	}
	return newStore;

}

void sortByCode(store* s) {
	int i,j;
	for (i = 0;i < s->num_of_items;i++) {
		for (j = i+1;j < s->num_of_items;j++) {
			if (s->items[i]->code > s->items[j]->code) {
				swapProduct(s->items[i], s->items[j]);
			}
		}
	}
}

void sortByName(store* s) {
	int i, j;
	for (i = 0;i < s->num_of_items;i++) {
		for (j = i + 1;j < s->num_of_items;j++) {
			if (s->items[i]->name[0] > s->items[j]->name[0]) {
				swapProduct(s->items[i], s->items[j]);
			}
		}
	}
}


int sumstroe(store* s){
	int i, sum=0;
	for (i = 0;i < s->num_of_items;i++) {
		sum += s->items[i]->amount;
	}
	return sum;
}

int amountByCode(store* s, int code) {
	int i;
	for (i = 0;i < s->num_of_items;i++) {
		if (s->items[i]->code == code)
			return s->items[i]->amount;
	}
}

void freeStore(store* s){
	int i;
	for (i = 0;i < s->num_of_items;i++) {
		freeProduct(s->items[i]);
	}
	free(s->name);
	free(s->items);
	free(s);
}
