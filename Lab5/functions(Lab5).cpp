#include <iostream>
#include <iomanip>
#include <string>
#include "functions(Lab5).h"

using namespace std;

bool Delimiter(char Symbol) {
	string SeparatorsArray = ".,:;?!\/";
	for (char i : SeparatorsArray) 
		if (Symbol == i)
			return true;
	return false;
}

bool Delimiter(char Symbol, string SeparatorsArray) {
	for (char i : SeparatorsArray)
		if (Symbol == i)
			return true;
	return false;
}
 
int FindLastInString() {
	return 0;
}

int FindFirstInString(string CurrentString, bool ) {
	return 0;
}


string DeleteIfMoreThanLastWord(string CurrentString) {
	string LastWord = "";

	int iterator = 1;
	do {
		if (!Delimiter(CurrentString[CurrentString.size() - iterator])) {
			int newIterator = 0;
		}
	} while (Delimiter(CurrentString[CurrentString.size() - iterator++]) && iterator != CurrentString.size() - 2);
	return "fss";
}