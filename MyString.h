#include <string>

class MyString
{
	private:
		char* Str;
		int Length;
		char* Separator;								//*for removing*
	public:
		MyString();										//Конструкторы для пустого объекта/"fsf"/string/MyString
		MyString(const char* nstr);
		MyString(std::string nstr);
		MyString(const MyString& t);	

		MyString& operator = (MyString& t);		
		MyString& operator = (const char* nstr);		//Переопределение операторов
		MyString& operator += (const MyString& t);
		bool operator == (const MyString& t) const;
		bool operator != (const MyString& t) const;
		char& operator [] (int Position);

		bool is_empty() const;							//Является ли строка пустой
		bool IsSeparator(char Checking);				//*for removing*
		bool IsSeparator(int Position);					//*for removing*
		void ChangeSeparators(const char* nstr);		//*for removing*
		//void AddSeparators(const char* nstr);			//*for removing*
		void erase(int begin, int size);				//Удаляет из строки size символов начиная с begin
		//void erase(const char* LineToDelete);			//*for removing*
		void insert(int begin, const char* Addition);	//Добавляет в строку, подстроку, начиная с позиции begin
		char* getStr() const;							//Получение строки в виде массива чаров
		char* getSep() const;							//*for removing*
		char* Select(int begin, int length);			//Получение подстроки(длинны length, начиная с позициии begin) в виде массива чаров
		//int Find(const char* Sought);					//*for removing*
		int FindFirstIf(bool (*check)(char));			//Ищет первый элемент удовлетворяющий условию
		int FindFirstIf(int begin, bool (*check)(char));//Ищет первый элемент удовлетворяющий условию начиная с begin
		int FindLastIf(bool (*check)(char));			//Ищет последний элемент удовлетворяющий условию
		int FindLastIF(int end, bool (*check)(char));	//Ищет последний элемент удовлетворяющий условию до end
		int getLength() const;							//длина строки
	private:
		void InitSeparators();							//*for removing*
		int strlen(const char* str);					//Получение длинны строки
		void strcpy(char* Destination, const char* Source);//Копирование одной строки в другую
		void strcat(char** Destination, const char* Source);//Присоеденение строки Source к  Destination

};

