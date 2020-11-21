#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <string>

void MyString::InitSeparators() {
	Separator = new char[7]{ '.', ',', '?', '!', ' ', ':', '\0' };
}

int MyString::strlen(const char* str)
{
	int length = 0;
	while(str[length++]){}
	return --length;
}

void MyString::strcpy(char* to_str, const char* from_str)
{
	int i = 0;
	do {
		to_str[i] = from_str[i];
	} while (from_str[i++]);
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
	char* newStr = new char[Length - size];
	for (int i = 0; i < begin; i++)
		newStr[i] = Str[i];
	for(int i = begin + size; i < Length; i++)
		newStr[i - size] = Str[i];
	delete[] Str;
	Str = newStr;
	Length -= size;
}

void insert(int begin, const char* nstr)
{
	char* newStr = new char[Length + strlen(nstr)];
	for (int i = 0; i < begin; i++)
		newStr[i] = Str[i];
	for (int i = begin + size; i < Length; i++)
		newStr[i - size] = Str[i];
	delete[] Str;
	Str = newStr;
	Length -= size;
}

void MyString::AddSeparators(const char* nstr) 
{
	//-----------------------------------------------------------------------------------------------------------
}

MyString& MyString::operator += (const MyString& t)
{
	Length += t.Length;
	char* newStr = new char[Length + 1];
	strcpy(newStr, Str);
	strcat(newStr, t.Str);
	delete[] Str;
	Str = newStr;
	return *this;
}

MyString& MyString::operator = (MyString& t) 
{
	Length = t.Length;
	delete[] Str;
	Str = t.Str;
	return *this;
}

char MyString::operator [] (int Position) const
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

const char* MyString::getStr() const
{
	return Str;	
}

int MyString::getLength() const
{
	return Length;
}

int MyString::FindFirstIf(bool (*check)(char Checking))
{
	int i = 0;
	while (Str[i] != '\0')
		if (check(Str[i++]))
			return --i;
	return '\0';
}

int MyString::FindFirstIf(int begin, bool (*check)(char Checking))
{
	int i = begin;
	while (Str[i] != '\0')
		if (check(Str[i++]))
			return --i;
	return '\0';
}

int MyString::FindLastIf(bool (*check)(char Checking))
{
	int i = Length - 1;
	while (i >= 0)
		if (check(Str[i--]))
			return ++i;
	return '\0';
}

int MyString::FindLastIF(int end, bool (*check)(char Checking))
{
	int i = end;
	while (i >= 0)
		if (check(Str[i--]))
			return ++i;
	return '\0';
}