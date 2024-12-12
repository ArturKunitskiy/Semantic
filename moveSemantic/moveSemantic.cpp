#include <iostream>
using namespace std;

class Book
{
private:

	char* Author;
	char* Text;
	int year;
	int pages;

public:

	Book() = default;
	Book(const Book& obj) = delete;
	Book& operator = (const Book& obj) = delete;
	Book(const char* author, const char* text, int y, int p)
	{
		year = y;
		pages = p;

		Author = new char[strlen(author) + 1];
		strcpy_s(Author, strlen(author) + 1, author);

		Text = new char[strlen(text) + 1];
		strcpy_s(Text, strlen(text) + 1, text);
	}

	Book(Book&& obj)
	{
		Author = obj.Author;
		Text = obj.Text;
		pages = obj.pages;
		year = obj.year;
		obj.Author = nullptr;
		obj.Text = nullptr;
		obj.pages = 0;
		obj.year = 0;
	}

	Book& operator=(Book&& obj)
	{
		Author = obj.Author;
		Text = obj.Text;
		pages = obj.pages;
		year = obj.year;
		obj.Author = nullptr;
		obj.Text = nullptr;
		obj.pages = 0;
		obj.year = 0;
		return *this;
	}
	void Input()
	{
		char buff[1000];
		cout << "Input your author: ";
		cin.getline(buff, 1000);
		if (Author != nullptr)
		{
			delete[] Author;
		}
		Author = new char[strlen(buff) + 1];
		strcpy_s(Author, strlen(buff) + 1, buff);
		cout << "Input text: " << endl;
		cin >> buff;
		if (Text != nullptr)
		{
			delete[] Text;
		}
		Text = new char[strlen(buff) + 1];
		strcpy_s(Text, strlen(buff) + 1, buff);
		cout << "Input pages number of your book: ";
		cin >> pages;
		cout << "Input year of manufacture: ";
		cin >> year;
	}
	void Print()
	{
		cout << "Author: " << Author << endl;
		cout << "Text: " << Text << endl;
		cout << "Number of pages: " << pages << endl;
		cout << "Year of manufacture: " << year << endl;
	}

	~Book()
	{
		delete[] Author;
		delete[] Text;
	}
};

int main()
{
	Book a("John Ronald Reuel Tolkien", "Hobbit", 384, 1937);
	a.Print();
	cout << endl;
	Book b = move(a);
	b.Print();
	a.Print();
}