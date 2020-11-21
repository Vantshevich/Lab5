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
		MyString& operator += (const MyString& t);
		bool operator == (const MyString& t) const;
		bool operator != (const MyString& t) const;
		char operator [] (int Position) const;
		bool is_empty() const;
		bool IsSeparator(int Position);
		bool IsSeparator(char Checking);
		void ChangeSeparators(const char* nstr);
		void AddSeparators(const char* nstr);
		void erase(int begin, int size);
		void insert(int begin, const char* nstr);
		const char* getStr() const;
		int FindFirstIf(bool (*check)(char Checking));
		int FindFirstIf(int begin, bool (*check)(char Checking));
		int FindLastIf(bool (*check)(char Checking));
		int FindLastIF(int end, bool (*check)(char Checking));
		int getLength() const;
	private:
		void InitSeparators();
		int strlen(const char* str);
		void strcpy(char* Destination, const char* Source);

};

