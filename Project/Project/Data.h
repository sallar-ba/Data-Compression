#pragma once
class Data
{
public:
	int Freq; // For Storing Frequency
	char Symbol;	// For Storing Symbol or Character

	// ----- Constructors ----
	Data();
	Data(char);

	// Function
	void insert(char);
	void insert(char, int);
};
