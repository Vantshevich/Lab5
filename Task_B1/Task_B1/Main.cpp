#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "../../MyString.h"

//Ванцевич Олег Сергеевич
//		9 группа

// B1
//	 Задан текстовый файл Input.txt, состоящий  из слов. 
//	 Разделителями между словами являются некоторое множество знаков препинания. 
//	 Из каждой строки удалить слова, длина которых больше длины последнего слова этой строки и
//	 записать эти строки  в новый файл Output.txt. Упорядочить слова  в полученных  строках по  возрастанию длин, результат сортировки записать в файл Out_sort.txt. 

//Описание алгоритма
//

			/*ТЕСТ No.1*/
//

			/*ТЕСТ No.2*/
//

using namespace std;

int LastSepFrom(MyString& str, bool Sep, int B_Position) 
{
	for (int i = B_Position; i >= 0; i--)
		if (Sep == str.IsSeparator(i))
			return i;
	return -1;
}

int FirstSepFrom(MyString& str, bool Sep, int B_Position = 0) 
{
	for (int i = B_Position; i < str.getLength(); i++)
		if (Sep == str.IsSeparator(i))
			return i;
	return -1;
}

void RemoveBiggerWords(MyString& str) 
{
	int LastLetter = LastSepFrom(str, false, str.getLength() - 1);
	int FirstLetter = LastSepFrom(str, true, LastLetter) + 1;
	int LengthOfLastWord = LastLetter - FirstLetter + 1;

	for (int i = 0; i < FirstLetter - 1;) {
		int WordBeginning = FirstSepFrom(str, false, i);
		int WordEnding = FirstSepFrom(str, true, WordBeginning + 1) - 1;
		if (WordEnding - WordBeginning + 1 > LengthOfLastWord) {
			str.erase(WordBeginning, WordEnding - WordBeginning + 1);
			i = WordBeginning;
			FirstLetter -= WordEnding - WordBeginning + 1;
		}
		else
			i = WordEnding + 1;
	}
}

void StringSort(MyString& str) 
{
	int NumberOfWords = 0;
	for (int i = 0; i < str.getLength();) {
		int WordBeginning = FirstSepFrom(str, false, i);
		if (WordBeginning == -1)
			break;
		int WordEnding = FirstSepFrom(str, true, WordBeginning + 1) - 1;
		NumberOfWords++;
		if (WordEnding == -2)
			break;
		i = WordEnding + 1;
	}

	MyString *WordMass = new MyString[NumberOfWords];
	int j = 0;
	for (int i = 0; i < NumberOfWords; i++) {
		int WordBeginning = FirstSepFrom(str, false, j);
		int WordEnding = FirstSepFrom(str, true, WordBeginning + 1) - 1;
		if (WordEnding == -2) {
			WordMass[i] = str.Select(WordBeginning, str.getLength() - 1 - WordBeginning + 1);
		}
		else {
			WordMass[i] = str.Select(WordBeginning, WordEnding - WordBeginning + 1);
			j = WordEnding + 1;
		}
	}

	for (int i = 0; i < NumberOfWords - 1; i++) {
		for (int j = 0; j < NumberOfWords - i - 1; j++) {
			if (WordMass[j].getLength() > WordMass[j + 1].getLength()) {
				MyString temp;
				temp = WordMass[j];
				WordMass[j] = WordMass[j + 1];
				WordMass[j + 1] = temp;
			}
		}
	}

	str = WordMass[0].getStr();
	str += " ";
	for (int i = 1; i < NumberOfWords; i++) {
		str += WordMass[i].getStr();
		if(i != NumberOfWords - 1)
			str += " ";
	}
}

int main() {
	setlocale(LC_ALL, ".1251");
	ifstream Input("Input.txt");
	ofstream Output;
	ofstream Out_sort; 
	Output.open("Output.txt");
	Out_sort.open("Out_sort.txt");
	if (Input.is_open())
	{
		string line;
		while (getline(Input, line))
		{
			MyString str(line);
			RemoveBiggerWords(str);
			if (Output.is_open())
			{
				Output << str.getStr() << endl;
			}
			StringSort(str);
			if (Out_sort.is_open())
			{
				Out_sort << str.getStr() << endl;
			}
		}
	}
	Input.close();
	system("pause");
	return 0;
}