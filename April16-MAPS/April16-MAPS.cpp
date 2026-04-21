// April16-MAPS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string> 
#include <map>

#include"functions.h"


class CustomMap //NO!
{

};

void demoSimpleMapExample()
{
	std::map<std::string, std::string> englishToSpanish;

	englishToSpanish.insert({ "I", "Yo" });

	englishToSpanish.insert({ "goodbye", "adios" });


	std::cout << "Enter a word that you want to translate from English to Spanish: \n";

	std::string theEnglishWord;
	getline(std::cin, theEnglishWord);

	std::string theSpanishTranslation = englishToSpanish[theEnglishWord];

	std::cout << "The Spanish equivalent is: " << theSpanishTranslation << "\n";

}

void demoCUTEMapExample()
{
	std::string text = "aabccde";

	std::map<char, int> letterFrequencyMap;

	for (char letter : text)
	{
		letterFrequencyMap[letter]++; //what do it do? 
	}

	for (std::pair<char, int> currentPair : letterFrequencyMap)
	{
		std::cout << currentPair.first << " occurs this many times: "
			<< currentPair.second << "\n";
	}

}

int main()
{

	auto letterFrequencyMap = getLetterFrequencyMapFromDictionary(); 

	for (pair<char, int> currentPair : letterFrequencyMap)
	{
		cout << currentPair.first << " occurs this many times: "
			<< currentPair.second << "\n";
	}




}
