#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "../../MyString.h"

//Ванцевич Олег Сергеевич
//		9 группа

// Задан текстовый файл Input.txt, состоящий  из слов.Разделителями 
// между словами является некоторое множество знаков препинания. Найти в каждой строке 
// слова– числа(это слова, состоящие только из цифр), заменить  их числом, равным сумме    
// цифр этого слова–числа.Результат записать  в новый файл Output.txt.Упорядочить слова  
// в полученных  строках по  возрастанию количества цифр в словах, результат сортировки записать в файл Out_sort.txt.
	
			/*ТЕСТ No.1*/
//

			/*ТЕСТ No.2*/
//

using namespace std;

bool isSeparator(char sym) {											//Функция проверяет является ли символ разделителем
	char* Separator = new char[7]{ '.', ',', '?', '!', ' ', ':', '\0' };
	for (int i = 0; i < 7; i++) {
		if (Separator[i++] == sym) return true;
	}
	return false;
}

bool isNotSeparator(char sym) {											//Функция проверяет не является ли символ разделителем
	char* Separator = new char[7]{ '.', ',', '?', '!', ' ', ':', '\0' };
	int i = 0;
	for (int i = 0; i < 7; i++) {
		if (Separator[i++] == sym) return false;
	}
	return true;
}


int LastTill(MyString& str, bool check(char), int B_Position)				//Ищет последний символ удовлетворяющий условию до B_Position
{
	for (int i = B_Position; i >= 0; i--)
		if (check(str[i]))
			return i;
	return -1;
}

int FirstFrom(MyString& str, bool check(char), int B_Position = 0)			//Ищет первый символ удовлетворяющий условию начиная с B_Position
{
	for (int i = B_Position; i < str.getLength(); i++)
		if (check(str[i]))
			return i;
	return -1;
}

bool isNumber(char a) {
	return a - 48 <= 9 && a - 48 >= 0;
}

void ChangeDigitWord(MyString& str)									//Заменяем С-Ч на суммус цифр С-Ч
{
	for (int i = 0; i < str.getLength();) {									//Внутри цилка идём по всем словам 	
		int WordBeginning = FirstFrom(str, isNotSeparator, i);
		if (WordBeginning == -1) break;
		int WordEnding = FirstFrom(str, isSeparator, WordBeginning + 1) - 1;
		if (WordEnding == -2) {
			WordEnding = str.getLength() - 1;
			int sum = 0;
			for (int j = WordBeginning; j <= WordEnding; j++) {					//Проверяем состоит ли чило только из цифр
				if (!isNumber(str[j])) {
					sum = -1;
					break;
				}
				sum += str[j] - 48;
			}
			if (sum != -1) {													//Если да, то заменяем его
				str.erase(WordBeginning, WordEnding - WordBeginning + 1);
				string a = to_string(sum);
				str.insert(WordBeginning, a.c_str());
				WordEnding = a.length() - 1 + WordBeginning;
			}
			break;
		}
		else {
			int sum = 0;
			for (int j = WordBeginning; j <= WordEnding; j++) {					//Проверяем состоит ли чило только из цифр
				if (!isNumber(str[j])) {
					sum = -1;
					break;
				}
				sum += str[j] - 48;
			}
			if (sum != -1) {													//Если да, то заменяем его
				str.erase(WordBeginning, WordEnding - WordBeginning + 1);
				string a = to_string(sum);
				str.insert(WordBeginning, a.c_str());
				WordEnding = a.length() - 1 + WordBeginning;
			}
		}
		i = WordEnding + 1;
	}
}

int NumberOfNumbs(MyString& str) {
	int n = 0;
	for (int i = 0; i < str.getLength(); i++)
		if (isNumber(str[i]))
			n++;
	return n;
}

void StringSort(MyString& str)
{
	int NumberOfWords = 0;
	for (int i = 0; i < str.getLength();) {								//Считаем кол-во слов в строке
		int WordBeginning = FirstFrom(str, isNotSeparator, i);
		if (WordBeginning == -1)
			break;
		int WordEnding = FirstFrom(str, isSeparator, WordBeginning + 1) - 1;
		NumberOfWords++;
		if (WordEnding == -2)
			break;
		i = WordEnding + 1;
	}

	MyString* WordMass = new MyString[NumberOfWords];					//Создаем массив слов-строк
	int* WordNumberOfDigit = new int[NumberOfWords];
	int j = 0;
	for (int i = 0; i < NumberOfWords; i++) {							//Заполняем его
		int WordBeginning = FirstFrom(str, isNotSeparator, j);
		int WordEnding = FirstFrom(str, isSeparator, WordBeginning + 1) - 1;
		if (WordEnding == -2) {
			WordMass[i] = str.Select(WordBeginning, str.getLength() - 1 - WordBeginning + 1);
		}
		else {
			WordMass[i] = str.Select(WordBeginning, WordEnding - WordBeginning + 1);
			j = WordEnding + 1;
		}
		WordNumberOfDigit[i] = NumberOfNumbs(WordMass[i]);
	}


	for (int i = 0; i < NumberOfWords - 1; i++) {						//Сортируем массив
		for (int j = 0; j < NumberOfWords - i - 1; j++) {
			if (WordNumberOfDigit[j] > WordNumberOfDigit[j + 1]) {
				MyString temp;
				int tempNumb;
				temp = WordMass[j];
				WordMass[j] = WordMass[j + 1];
				WordMass[j + 1] = temp;
				tempNumb = WordNumberOfDigit[j];
				WordNumberOfDigit[j] = WordNumberOfDigit[j + 1];
				WordNumberOfDigit[j + 1] = tempNumb;
			}
		}
	}


	str = WordMass[0].getStr();
	str += " ";
	for (int i = 1; i < NumberOfWords; i++) {							//Создаем нову строку из отсортированного массивац
		str += WordMass[i].getStr();
		if (i != NumberOfWords - 1)
			str += " ";
	}
}

int main() {

	setlocale(LC_ALL, ".1251");
	ifstream Input("Input.txt");	//Поток ввода из файла Inoput
	ofstream Output;				//Поток вывода в файл Output
	ofstream Out_sort;				//Поток вывода в файл Output_sort для отсортиравнного массива строк
	Output.open("Output.txt");
	Out_sort.open("Out_sort.txt");
	if (Input.is_open())
	{
		string line;
		while (getline(Input, line))	//Считываем строку
		{
			MyString str(line);			//Создаём объект, в который при создании передаём считанную строку
			ChangeDigitWord(str);		//Удаляем слова, длина которых больше длины последнего
			if (Output.is_open())
			{
				Output << str.getStr() << endl;
			}
			StringSort(str);			//Сортируем слова в строке по кол-ву цифр в слове
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