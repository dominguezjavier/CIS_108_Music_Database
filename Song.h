#pragma once

enum Genre
{
	Blues = 0,
	Country,
	Electronic,
	Folk,
	HipHop,
	Jazz,
	Latin,
	Pop,
	Rock,
};

const int MAX_CHARS_PER_TITLE = 64;
const int MAX_CHARS_PER_ARTIST = 32;
const int MAX_CHARS_PER_ALBUM = 64;

struct Song
{
	char title[MAX_CHARS_PER_TITLE];
	char artist[MAX_CHARS_PER_ARTIST];
	char album[MAX_CHARS_PER_ALBUM];
	unsigned int track;
	unsigned int year;
	Genre genre;
};

