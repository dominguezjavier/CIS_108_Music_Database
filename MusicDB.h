#pragma once
#pragma once
#include <string>
#include "Song.h"

using namespace std;
namespace MusicDB
{
	// Add a song to the database
	void addSong(Song song);

	// Returns the  total number of Songs in the database
	int getTotalSongs();
	Song getSong(int index); // Returns a song from the database from the index
	void loadSongsFromFile(string filename); // Load song database from file
	void saveSongsToFile(string filename);   //Saves the song database to the file
	

}