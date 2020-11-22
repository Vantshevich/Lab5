#include <string>

class MyString
{
	private:
		char* Str;
		int Length;
		char* Separator;
	public:
		MyString();
		MyString(const char* nstr);
		MyString(std::string nstr);
		MyString(const MyString& t);	
		MyString& operator = (MyString& t);
		MyString& operator = (const char* nstr);
		MyString& operator += (const MyString& t);
		bool operator == (const MyString& t) const;
		bool operator != (const MyString& t) const;
		char& operator [] (int Position);
		bool is_empty() const;
		bool IsSeparator(int Position);
		bool IsSeparator(char Checking);
		void ChangeSeparators(const char* nstr);
		//void AddSeparators(const char* nstr);
		void erase(int begin, int size);
		//void erase(const char* LineToDelete);
		void insert(int begin, const char* Addition);
		char* getStr() const;
		char* getSep() const;
		char* Select(int begin, int length);
		//int Find(const char* Sought);
		int FindFirstIf(bool (*check)(char));
		int FindFirstIf(int begin, bool (*check)(char));
		int FindLastIf(bool (*check)(char));
		int FindLastIF(int end, bool (*check)(char));
		int getLength() const;
	private:
		void InitSeparators();
		int strlen(const char* str);
		void strcpy(char* Destination, const char* Source);
		void strcat(char** Destination, const char* Source);

};

