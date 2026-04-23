// April16-MAPS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include<random>
#include<string> 

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


void demoSimpleCaesarEncryption()
{
	string message = "abcdefg";
	int key = 5;

	string encrypted = caesarEncrypt(message, key);

	cout << "Original:  " << message << endl;
	cout << "Encrypted: " << encrypted << endl;

}

int main()
{

	auto letterFrequencyMap = getLetterFrequencyMapFromDictionary(); 

	//printHistogramOfLetterFrequencies(letterFrequencyMap);

	demoSimpleCaesarEncryption(); 


	int maxKeyValue = 10; 
	mt19937 rng(random_device{}());
	uniform_int_distribution<int> distribution(0, maxKeyValue);

	int randomKey = distribution(rng); 


	std::string sampleText =
		"It is a truth universally acknowledged, that a single man in possession "
		"of a good fortune, must be in want of a wife. However little known the "
		"feelings or views of such a man may be on his first entering a neighbourhood, " //BRITISH
		"this truth is so well fixed in the minds of the surrounding families, that "
		"he is considered the rightful property of some one or other of their daughters. "
		"\"My dear Mr. Bennet,\" said his lady to him one day, \"have you heard that "
		"Netherfield Park is let at last?\" Mr. Bennet replied that he had not. "
		"\"But it is,\" returned she; \"for Mrs. Long has just been here, and she "
		"told me all about it.\" Mr. Bennet made no answer. \"Do you not want to know "
		"who has taken it?\" cried his wife impatiently. \"YOU want to tell me, and I "
		"have no objection to hearing it.\"";


	auto plainTextFrequencyMap = getLetterFrequencyMap_OfGivenString(sampleText);
	printHistogramOfLetterFrequencies(plainTextFrequencyMap);


	string cipherText = caesarEncrypt(sampleText, randomKey);

	cout << cipherText << "\n";

	auto cipherTextFrequencyMap = getLetterFrequencyMap_OfGivenString(cipherText);

	cout << "\n\n\n";
	printHistogramOfLetterFrequencies(cipherTextFrequencyMap);
	
	int a = 123; 
}
