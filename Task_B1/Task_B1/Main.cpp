#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "../../MyString.h"

//�������� ���� ���������
//		9 ������

// B1
//	 ����� ��������� ���� Input.txt, ���������  �� ����. 
//	 ������������� ����� ������� �������� ��������� ��������� ������ ����������. 
//	 �� ������ ������ ������� �����, ����� ������� ������ ����� ���������� ����� ���� ������ �
//	 �������� ��� ������  � ����� ���� Output.txt. ����������� �����  � ����������  ������� ��  ����������� ����, ��������� ���������� �������� � ���� Out_sort.txt. 

//�������� ���������
//

			/*���� No.1*/
//

			/*���� No.2*/
//

using namespace std;

int LastSepFrom(MyString& str, bool Sep, int B_Position) {
	for (int i = B_Position; i >= 0; i--)
		if (Sep == str.IsSeparator(i))
			return i;
	return -1;
}

int FirstSepFrom(MyString& str, bool Sep, int B_Position = 0) {
	for (int i = B_Position; i < str.getLength(); i++)
		if (Sep == str.IsSeparator(i))
			return i;
	return -1;
}

void RemoveBiggerWords(MyString& str) {
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

void StringSort(MyString& str) {
	int NumberOfWords = 0;
	for (int i = 0; i < str.getLength();) {
		int WordBeginning = FirstSepFrom(str, false, i);
		int WordEnding = FirstSepFrom(str, true, WordBeginning + 1) - 1;
		NumberOfWords++;
		i = WordEnding + 1;
	}
	MyString *WordMass = new MyString[NumberOfWords];
	for (int i = 0; i < str.getLength();) {
		int WordBeginning = FirstSepFrom(str, false, i);
		int WordEnding = FirstSepFrom(str, true, WordBeginning + 1) - 1;
		i = WordEnding + 1;
		WordMass[0] = str.Select(WordBeginning, WordEnding - WordBeginning + 1);
	}
	for (int i = 0; i < NumberOfWords - 1; i++) {
		for (int j = 0; j < NumberOfWords - i - 1; j++) {
			if (WordMass[j].getLength() > WordMass[j + 1].getLength()) {
				MyString temp = WordMass[j];
				WordMass[j] = WordMass[j + 1];
				WordMass[j + 1] = temp;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, ".1251");
	ifstream Input("Input.txt");
	ofstream Output;
	Output.open("Output.txt");
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
		}
	}
	Input.close();
	system("pause");
	return 0;
}