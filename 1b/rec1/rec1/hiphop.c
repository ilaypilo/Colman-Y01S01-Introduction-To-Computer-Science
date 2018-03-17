#include "stdio.h" 
#include "stdlib.h"
#include "hiphop.h"


void swapSongs(playlist* list, int firstSong, int secondSong) {
	song* temp = list->songList[firstSong];
	list->songList[firstSong] = list->songList[secondSong];
	list->songList[secondSong] = temp;
}


void addNewSong(playlist* list) {
	song* tempSong = (song*)malloc(sizeof(song));
	int year,length,i;
	printf("Song Code: ");
	scanf("%d", &tempSong->code);
	for (i = 0; i < list->numOfSongs; i++) {
		if (list->songList[i]->code == tempSong->code) {
			printf("Song Exsit\n");
			return;
		}
	}
	tempSong->songName = (char*)malloc(100);
	gets();
	printf("Song Name: ");
	gets(tempSong->songName);
	tempSong->artist = (char*)malloc(100);
	printf("Song Artist: ");
	gets(tempSong->artist);
	printf("Song Year: ");
	scanf("%d", &year);
	if (year < 1900) year == 1900;
	tempSong->year = year;
	do {
		printf("Song Length: ");
		scanf("%d", &length);
		if (length < 0) printf("Wrong Length\n");
	} while (length < 0);
	tempSong->length = length;
	list->songList = realloc(list->songList, ((list->numOfSongs) + 1) * sizeof(song*));
	list->songList[list->numOfSongs] = tempSong;
	list->listLength += tempSong->length;
	list->numOfSongs += 1;
}