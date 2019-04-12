#include <iostream>
#include <string>

#include "MusicDB.h"

using namespace std;

void displayHelpMenu();    // output the help menu to the user

Song getSongFromUser();   // get a new song from the user

void listSongs(); // we use only one time in order to retreive something and not have to put something out Void

string convertGenreToString(Genre genre); // converts a Genre enum to a string

Genre convertStringToGenre(string genre);

const string DATABASE_FILE = "music.db";

int main()
{
	// output the menu
	displayHelpMenu();

	// load the songs from the database
	MusicDB::loadSongsFromFile(DATABASE_FILE);

	bool should_exit = false;
	while (should_exit != true)
	{
		// display the prompt
		cout << ">";

		// get command from user
		string command;
		getline(cin, command);

		if (command == "add")
		{
			Song new_song = getSongFromUser();
			MusicDB::addSong(new_song);
		}
		else if (command == "list")
		{
			listSongs(); // we use this to list the songs in the database 
		}
		else if (command == "save")
		{
			MusicDB::saveSongsToFile(DATABASE_FILE); // Save the song to the Database file

		}
		else if (command == "help")
		{
			// output the menu
			displayHelpMenu();
		}
		else if (command == "exit")
		{
			// exit the loop
			should_exit = true;
		}
		else
		{
			cout << "Hey dummy, read the help menu!" << endl;
		}
	}

	return 0;
}

// output the help menu to the user
void displayHelpMenu()
{
	cout << "add : Add a new song to the database" << endl;
	cout << "list : List the songs in the database" << endl;
	cout << "save : Save the database of songs to file" << endl;
	cout << "help : Display the menu" << endl;
	cout << "exit : Exit the program" << endl;
	//cout << " Genre: " << convertGenreToString(genre) << endl;
}

// converts a Genre enum to a string
string convertGenreToString (Genre genre)
{
	string genre_string = "Unknown";

	switch (genre)
	{
	case Blues: genre_string =       "Blues";      break;
	case Country: genre_string =     "Country";    break;
	case Electronic: genre_string =  "Electronic"; break;
	case Folk: genre_string =        "Folk";       break;
	case HipHop: genre_string =      "HipHop";     break;
	case Jazz: genre_string =        "Jazz";       break;
	case Latin: genre_string =       "Latin";      break;
	case Pop: genre_string =         "Pop";        break;
	case Rock: genre_string =        "Rock";       break;        
	}


	return genre_string;

}

// converts a string to a Genre enum
Genre convertStringToGenre (string genre)
{
	Genre genre_enum;

	if (genre == "blues")       genre_enum = Blues;
	if (genre == "country")     genre_enum = Country;
	if (genre == "electronic")  genre_enum = Electronic;
	if (genre == "folk")        genre_enum = Folk;
	if (genre == "hiphop")      genre_enum = HipHop;
	if (genre == "jazz")        genre_enum = Jazz;
	if (genre == "latin")       genre_enum = Latin;
	if (genre == "pop")         genre_enum = Pop;
	if (genre == "rock")        genre_enum = Rock;

	return genre_enum;
}

// get a new song from the user
Song getSongFromUser()
{
	Song song;

	string title;
	cout << "Enter song title: ";
	getline(cin, title);

	string artist;
	cout << "Enter artist: ";
	getline(cin, artist);

	string album;
	cout << "Enter album name: ";
	getline(cin, album);

	unsigned int track;
	cout << "Enter track #: ";
	cin >> track;

	unsigned int year;
	cout << "Enter year: ";
	cin >> year;

	string genre;
	cout << "Enter genre: ";
	cin.ignore();
	getline(cin, genre);

	strncpy_s(song.title, title.c_str(), MAX_CHARS_PER_TITLE);
	strncpy_s(song.artist, artist.c_str(), MAX_CHARS_PER_ARTIST);
	strncpy_s(song.title, title.c_str(), MAX_CHARS_PER_ALBUM);
	song.track = track;
	song.year = year;
	// TODO: convert genre string to enum and set in song structure

	return song;
}

void listSongs() // we use 
{
	for (int idx = 0; idx < MusicDB::getTotalSongs(); idx++)
	{
		Song song = MusicDB::getSong(idx);

		cout << "Song #" << idx + 1 << endl;
		cout << " Title: " << song.title << endl;
		cout << " Artist: " << song.artist << endl;
		cout << " Album: " << song.album << endl;
		cout << "Track: " << song.track << endl;
		cout << " Year: " << song.year << endl;
		// TODO convert genre enum to string and output console
	}
}