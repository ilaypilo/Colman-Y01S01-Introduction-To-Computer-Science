#include <stdio.h>
#include <stdlib.h>
typedef struct Book
{
	char* bookName;
	int bookCode;
	int units;
} book;

typedef struct Store
{
	char* storeName;
	int NumOfbooks;
	book ** books;
} store;

int insertbookToStore(store* bookstore);
int maxNumOfBooks(store* bookstore);
int deleteAll(store* bookstore);


int main() {
	int i;
	store* myStore = malloc(sizeof(store));
	myStore->storeName = "bla";
	myStore->NumOfbooks = 2;
	myStore->books = malloc(sizeof(book*)*2);
	myStore->books[0] = malloc(sizeof(book));
	myStore->books[0]->bookCode = 111;
	myStore->books[0]->bookName = malloc(30);
	strcpy(myStore->books[0]->bookName, "first book");
	myStore->books[0]->units = 5;
	myStore->books[1] = malloc(sizeof(book));
	myStore->books[1]->bookCode = 112;
	myStore->books[1]->bookName = malloc(30);
	strcpy(myStore->books[1]->bookName, "second book");

	//insertbookToStore(myStore);
	
	for (i = 0; i < myStore->NumOfbooks; i++) {
		printf("%s: %d\n", myStore->books[i]->bookName, myStore->books[i]->units);
	}

	printf("Max Number Of Books: %s\n", myStore->books[maxNumOfBooks(myStore)]->bookName);
	deleteAll(myStore);

}
int bookExsit(store* bookstore, int bookCode) {
	int i;
	for (i = 0; i < bookstore->NumOfbooks; i++) {
		if (bookstore->books[i]->bookCode == bookCode) return i;
	}
	return 0;
}

int insertbookToStore(store* bookstore) {
	int bookCode, units, index;
	book* tempBook = malloc(sizeof(book));
	book** tempBookPtr;
	printf("Please enter book code: ");
	scanf("%d", &bookCode);
	index = bookExsit(bookstore, bookCode);
	if (index) {
		printf("The book exist in the store\n");
		printf("Please enter number of units: ");
		scanf("%d", &units);
		bookstore->books[index]->units += units;
		return 1;
	}
	getchar();
	printf("Please enter book name: ");
	tempBook->bookName = malloc(30);
	gets(tempBook->bookName);
	printf("Please enter number of units: ");
	scanf("%d", &units);
	tempBook->units = units;
	tempBookPtr = bookstore->books;
	bookstore->books = realloc(bookstore->books, sizeof(book*)*bookstore->NumOfbooks + 1);
	if (bookstore->books == NULL) {
		bookstore->books = tempBookPtr;
		return 0;
	}
	bookstore->books[bookstore->NumOfbooks] = tempBook;
	bookstore->NumOfbooks += 1;
	return 1;

}

int maxNumOfBooks(store* bookstore) {
	int i,max=0;
	for (i = 0; i < bookstore->NumOfbooks; i++) {
		if (bookstore->books[i]->units > max) max = i;
	}
	return max;
}

int deleteAll(store* bookstore) {
	int i;
	for (i = 0; i < bookstore->NumOfbooks; i++) {
		free(bookstore->books[i]->bookName);
		free(bookstore->books[i]);
	}
	free(bookstore->books);
	free(bookstore);
	return 1;
}