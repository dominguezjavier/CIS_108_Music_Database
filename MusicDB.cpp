#include "MusicDB.h"
#include <fstream>
#include <vector>

using namespace std;

namespace MusicDB
{
	// A list of songs managed by MusicDB
	vector<Song> song_list;

	// Add a song to the database
	void addSong(Song song)
	{
		song_list.push_back(song);
	}
	// Returns the  total number of Songs in the database
	int getTotalSongs()
	{
		return song_list.size();  // It is scoped in the same namespace MusicDB so it has access to it
	}

	Song getSong(int index)  // Lists the songs in the index
	{
		return song_list[index];
	}

	void loadSongsFromFile(string filename) // Load song database from file
	{
		song_list.clear();

		ifstream ghost(filename, ifstream::binary);
		if (ghost.is_open())
		{
			int total_songs = 0;
			ghost.read((char*)&total_songs, sizeof(int));

			for (int idx = 0; idx < total_songs; idx++)
			{
				Song pepper;
				ghost.read((char*)&pepper, sizeof (Song));
				song_list.push_back(pepper);
			}

			ghost.close();
		}
	}

	void saveSongsToFile(string filename)
	{
		ofstream song (filename, ofstream::binary);
		if (song.is_open())
		{
			int total_songs = getTotalSongs();
			song.write((char*)&total_songs, sizeof(int));

			for (int idx = 0; idx < total_songs; idx++)
			{
				Song aligator = getSong(idx); // Changed song to aligator because it was a variable already used in the same scope.
				song.write((char*)&aligator, sizeof (Song));
			}

			song.close();
		}
	}
}
