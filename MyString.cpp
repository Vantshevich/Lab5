#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>
#include <string>

using namespace std;

void MyString::InitSeparators() {
	Separator = new char[7]{ '.', ',', '?', '!', ' ', ':', '\0' };
}

int MyString::strlen(const char* str)
{
	int length = 0;
	while(str[length++]){}
	return --length;
}

void MyString::strcpy(char* Destination, const char* Source)
{
	int i = 0;
	do {
		Destination[i] = Source[i];
	} while (Source[i++]);
}

void MyString::strcat(char** Destination, const char* Source)
{
	int lengthD = strlen(*Destination);
	int lengthS = strlen(Source);
	char* newStr = new char[lengthD + lengthS + 1];
	for (int i = 0; i < lengthD; i++)
		newStr[i] = (*Destination)[i];
	for (int i = lengthD; i < lengthD + lengthS; i++)
		newStr[i] = Source[i - lengthD];
	newStr[lengthD + lengthS] = '\0';
	delete[] *Destination;
	*Destination = newStr;
}

MyString::MyString()
{
	Str = 0;
	Length = 0;
	InitSeparators();
}

MyString::MyString(const char* nstr)
{
	Length = strlen(nstr);
	Str = new char[Length + 1];
	strcpy(Str, nstr);
	InitSeparators();
}

MyString::MyString(std::string nstr)
{
	Length = nstr.length();
	Str = new char[Length + 1];
	strcpy(Str, nstr.c_str());
	InitSeparators();
}

MyString::MyString(const MyString& t)
{
	Length = strlen(t.Str);
	Str = new char[Length + 1];
	strcpy(Str, t.Str);
	InitSeparators();
}

void MyString::ChangeSeparators(const char* nstr)
{
	int NewLength = strlen(nstr);
	delete[] Separator;
 	Separator = new char[NewLength];
	strcpy(Separator, nstr);
}

void MyString::erase(int begin, int size)
{
	char* newStr = new char[Length - size + 1];
	for (int i = 0; i < begin; i++)
		newStr[i] = Str[i];
	for(int i = begin + size; i < Length; i++)
		newStr[i - size] = Str[i];
	newStr[Length - size] = '\0';
	delete[] Str;
	Str = newStr;
	Length -= size;
}

//void MyString::erase(char* LineToDelete)
//{
//	int length = strlen(LineToDelete);
//
//}

void MyString::insert(int begin, const char* Addition)
{
	char* newStr = new char[Length + strlen(Addition)];
	strcpy(newStr, Select(0, begin));
	strcat(&newStr, Addition);
	strcat(&newStr, Select(begin, Length - begin));
	delete[] Str;
	Str = newStr;
}

MyString& MyString::operator += (const MyString& t)
{
	Length += t.Length;
	char* newStr = new char[Length];
	strcpy(newStr, Str);
	strcat(&newStr, t.Str);
	delete[] Str;
	Str = newStr;
	return *this;
}

MyString& MyString::operator = (MyString& t) 
{
	Length = t.Length;
	delete[] Str;
	Str = new char[Length + 1];
	strcpy(Str, t.Str);
	return *this;
}

MyString& MyString::operator = (const char* nstr)
{
	Length = strlen(nstr);
	delete[] Str;
	Str = new char[Length + 1];
	strcpy(Str, nstr);
	return *this;
}

char& MyString::operator [] (int Position)
{
	return Str[Position];
}

bool MyString::operator == (const MyString& t) const
{
	return Length == t.Length && strcmp(Str, t.Str) == 0;
}

bool MyString::operator != (const MyString& t) const
{
	return !(operator == (t));	
}

bool MyString::IsSeparator(int Position)
{
	char current = Str[Position];
	int i = 0;
	while (Separator[i] != '\0')
		if (Separator[i++] == current)
			return true;
	return false;
}

bool MyString::IsSeparator(char Cheking)
{
	int i = 0;
	while (Separator[i] != '\0')
		if (Separator[i++] == Cheking)
			return true;
	return false;
}


bool MyString::is_empty() const
{
	return Str == 0 || Str[0] == '\0';
}

char* MyString::getStr() const
{
	return Str;	
}

char* MyString::getSep() const
{
	return Separator;
}

char* MyString::Select(int begin, int length)
{
	char* newStr = new char[length];
	for (int i = 0; i < length; i++)
		newStr[i] = Str[i + begin];
	newStr[length] = '\0';
	return newStr;
}

int MyString::getLength() const
{
	return Length;
}

//int MyString::Find(const char* Sought)
//{
//	for (int i = 0; i < Length; i++) {
//		if (Str[i] == Sought[0]) {
//			int j = 1;
//			while(Sought())
//		}
//	}
//}

int MyString::FindFirstIf(bool (*check)(char))
{
	int i = 0;
	while (Str[i] != '\0')
		if (check(Str[i++]))
			return --i;
	return '\0';
}

int MyString::FindFirstIf(int begin, bool (*check)(char))
{
	int i = begin;
	while (Str[i] != '\0')
		if (check(Str[i++]))
			return --i;
	return '\0';
}

int MyString::FindLastIf(bool (*check)(char))
{
	int i = Length - 1;
	while (i >= 0)
		if (check(Str[i--]))
			return ++i;
	return '\0';
}

int MyString::FindLastIF(int end, bool (*check)(char))
{
	int i = end;
	while (i >= 0)
		if (check(Str[i--]))
			return ++i;
	return '\0';
}