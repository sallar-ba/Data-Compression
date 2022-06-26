#pragma once
// -+-+-+-+-+--+-+-+-+-+--+-+-+-+-+--+-+-+-+-+-
class Data
{
public:
	int Freq; // For Storing Frequency
	char Symbol;	// For Storing Symbol or Character

	// ----- Constructors ----
	Data();
	Data(char);

	// Functions
	void insert(char);
	void insert(char, int);
};
// -+-+-+-+-+--+-+-+-+-+--+-+-+-+-+--+-+-+-+-+-