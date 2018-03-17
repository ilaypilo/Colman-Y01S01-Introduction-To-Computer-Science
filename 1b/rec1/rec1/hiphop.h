#ifndef __HIPHOP_H
#define __HIPHOP_H


typedef struct Song {
	int code;
	char *songName;
	char *artist;
	int year;
	char *genre;
	int length;
}song;

typedef struct Playlist {
	char* playlistName;
	int numOfSongs;
	int listLength;
	song** songList;
}playlist;


void swapSongs(playlist* list, int firstSong, int secondSong);
void addNewSong(playlist* list);
#endif