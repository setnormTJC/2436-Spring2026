#pragma once


#include<fstream> 
#include<iostream>
#include<map> 
#include <string>

using namespace std; 

map<char, int> getLetterFrequencyMapFromDictionary()
{
	map<char, int> letterFrequencyMap; 

	std::string filename = "words.txt";

	ifstream fin(filename);

	if (!fin)
	{
		cout << "File not found\n";
		return {}; 
	}

	string currentWord; 
	while (getline(fin, currentWord))
	{
		for (char currentLetter : currentWord)
		{
			//fill in the goodies!
			letterFrequencyMap[currentLetter]++; 
		}
	}

	return letterFrequencyMap; 
}

map<char, int> getLetterFrequencyMap_OfGivenString(const string& theString)
{
	map<char, int> letterFrequencyMap; 

	for (char currentLetter : theString)
	{
		//fill in the goodies!
		letterFrequencyMap[currentLetter]++;
	}
	
	return letterFrequencyMap;
}

void printHistogramOfLetterFrequencies(const map<char, int>& letterFrequencyMap)
{
	//const int SCALING_FACTOR = 200; // Danger, Will Robinson!!!!!!!!!!!!!!!!!!!!!!!!

	for (pair<char, int> currentPair : letterFrequencyMap)
	{
		//cout << currentPair.first << "-" << currentPair.second << "\n";
		cout << currentPair.first << "-";

		//int scaledNumberOfOccurrences = currentPair.second / SCALING_FACTOR; 
		int scaledNumberOfOccurrences = currentPair.second;
		for (int i = 0; i < scaledNumberOfOccurrences; ++i)
		{
			cout << "*";
		}
		cout << "\n";

	}
}

string caesarEncrypt(string text, int shift) 
{
	string result = "";

	// Normalize the shift to be within 0-25
	shift = shift % 26;

	for (char& c : text) {
		if (isupper(c)) {
			// Shift within 'A'-'Z' (65-90)
			result += char(int(c + shift - 'A') % 26 + 'A');
		}
		else if (islower(c)) {
			// Shift within 'a'-'z' (97-122)
			result += char(int(c + shift - 'a') % 26 + 'a');
		}
		else {
			// Keep spaces and punctuation as they are
			result += c;
		}
	}
	return result;
}
