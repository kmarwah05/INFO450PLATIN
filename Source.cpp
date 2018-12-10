
#include<iostream>
#include <iomanip>
#include<string>
#define _CRT_SECURE_NO_WARNINGS  
using namespace std;


bool checkError(string inputValue);
void vowelPigLatin(string inputValue);
void translateToPigLatin(string inputValue);

int main()
{
	string wordInput = ""; 
	bool inputError = false;
	char boolAnswer = 'y';
	
	cout << "Welcome to the Pig Latin Translator. " << endl;
	do
	{
		cout << "Would you like to translate a word? (y/n) \n";
		cin >> boolAnswer;
		if (boolAnswer == 'y' || boolAnswer == 'Y')
		{
			cout << "Please enter the word you would like to be translated..." << endl;
			cin >> wordInput;
			inputError = checkError(wordInput);
		}

		if (inputError == false)
		{
			vowelPigLatin(wordInput);
		}
		cin.ignore();
		cin.clear();
		cout << "Would you like to translate a word again? (y/n)";
		cin >> boolAnswer;


	} while (boolAnswer != 'n' || boolAnswer != 'N');
	return 0;



	system("pause");
	return 0;
}

bool checkError(string inputValue)
{
	bool errorVerif = false;
	int Length = inputValue.length();
	int Counter = 0;
	char *specificLetter = &inputValue.at(0);

	while (Counter < Length - 1 && errorVerif == false)
	{
		if (!isalpha(*specificLetter) || isspace(*specificLetter))
		{
			cout << *specificLetter << "is not an acceptable entry. Please re-enter your word.";
			errorVerif = true;
		}

		*specificLetter++;
		Counter++;

	}
	return errorVerif;
}

void vowelPigLatin(string inputValue)
{
	char firstLetter;
	firstLetter = inputValue.at(0);

	if (firstLetter == 'a' || 'e' || 'i' || 'o' || 'u')
	{
		cout << "In Pig Latin, that would be " << inputValue << "ay " << endl;
	}
	else
	{
		translateToPigLatin(inputValue);
	}
}

void translateToPigLatin(string inputValue)
{
	char firstLetter;
	char lastLetter = inputValue.length();
	firstLetter = inputValue.at(0);
	string otherLetters = inputValue.substr((firstLetter + 1), (lastLetter - 1));
	cout << "In Pig Latin, that would be " << otherLetters << firstLetter << "ay." << endl;
}





