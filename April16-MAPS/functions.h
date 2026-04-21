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