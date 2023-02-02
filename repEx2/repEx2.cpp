// repEx2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

static int GetLength(const char* aWord);
static unsigned int FindLetter(const char* aWord, unsigned int aLen, char* aCurrent, char aLetter);

int main(int aCount, char** aVector)
{
	if (aCount != 2)
	{
		printf("\u001b[31m il nous faut un argument contenant le mot courant");
		return 1;
	}
	//tableau de 20 charactère statique
	//char word[20];

	const int wordLength = GetLength(aVector[1]);

	char* word = new char[wordLength + 1];
	//copier la reponse dans word
	strcpy_s(word, wordLength + 1, aVector[1]);

	printf("Longueur:%d\n", wordLength);

	bool play = true;
	int nbError = 0;
	int nbFound = 0;
	char separation[32] = "-";
	char* currentTry = new char[wordLength + 1];
	char* currentWord = new char[wordLength + 1];
	unsigned int nbNewlyFound = 0;
	//separation tableau
	strcpy_s(separation, "-");
	memset(separation, '-', sizeof(separation) - 1);
	separation[31] = '-\0\n';

	//place la mémoire pour la rendre vide
	//currentWord[wordLength] = 0;
	memset(currentWord, 0, wordLength + 1);
	memset(currentWord, '-', wordLength);
	//5printf("%s\n", currentWord);
	while (play)
	{
		printf("%d erreurs, %d lettre trouvees sur %d\n", nbError, nbFound, wordLength);
		printf("%s\n", currentWord);
		printf("%s\n", separation);
		printf("veuillez entrer une lettre ou essayer le mot:");
		gets_s(currentTry, wordLength + 1);
		//juste une lettre
		if (GetLength(currentTry) == 1)
		{
			nbNewlyFound = FindLetter(word, wordLength, currentWord, currentTry[0]);
			if (nbNewlyFound == 0) {
				printf("le mot ne contient pas cette lettre\n");
			}
			else
			{
				printf("le mot contient  cette lettre\n");
				nbFound += nbNewlyFound;
			}
		}
		else
		{
			if (_strnicmp(word, currentTry, wordLength + 1) == 0)
			{
				printf("\u001b[32mBravo vous avez gagner!!!\u001b\033[0m\n");
				play = false;
			}
			else
			{
				printf("\u001b[31mERREUR!!!\u001b\033[0m\n");
				nbError++;
			}
		}
	}
	//clean
	delete[] word;
	delete[] currentTry;
	delete[] currentWord;
	//delete[] separation;

	return 0;
}

int GetLength(const char* aWord)
{
	int i = 0;

	while (aWord[i] != 0)
	{
		i++;
	}

	return i;
}
//va check les lettre du mot courrant pour remplacer les tiret a la bonne position
unsigned int FindLetter(const char* aWord,
	unsigned int aLen,
	char* aCurrent,
	char aLetter)
{
	unsigned int count = 0;

	for (int i = 0; i < aLen; i++)
	{
		if (aCurrent[i] == '-' && aWord[i] == aLetter)
		{
			count++;
			aCurrent[i] = aLetter;
		}
	}

	return count;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file