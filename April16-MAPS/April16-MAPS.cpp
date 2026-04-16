// April16-MAPS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string> 
#include <map>


class CustomMap //NO!
{

};

int main()
{
	std::map<std::string, std::string> englishToSpanish; 

	englishToSpanish.insert({ "I", "Yo" });

	englishToSpanish.insert({ "goodbye", "adios" });


	std::cout << "Enter a word that you want to translate from English to Spanish: \n";

	std::string theEnglishWord; 
	getline(std::cin, theEnglishWord);

	std::string theSpanishTranslation = englishToSpanish.at(theEnglishWord);

	std::cout << "The Spanish equivalent is: " << theSpanishTranslation << "\n";


}
