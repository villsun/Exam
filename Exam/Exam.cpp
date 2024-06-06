#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> 

using namespace std;


struct Genre
{
	string genre;
	int age_audience;
};
struct Author
{
	string name;
	string surname;
	int age_author;
};

class Book
{
private:
	string name_of_book;
	size_t total_circulation;
	int year_of_publication;
	int number_of_books_sold;
	Genre genre_book;
	Author autor_book;

public:
	Book();
	Book(const string& name_of_book, const string& genre, const int age_audience, const string& name, const string& surname, const int age_author, const size_t total_circulation, const int year_of_publication, const int number_of_books_sold);
	Book(const Book& copy);
	string Get_Name_of_Book() const;
	Genre Get_Genre() const;
	int Get_Year_of_Publication() const;
	int Get_Age_Author() const;
	friend void Add_Author(vector<Book>& books, int index, const string& _name, const string& _surname, const int _age_author);
	friend void Delete_Author(vector<Book>& books, int index);
	friend Author Oldest_Author(vector<Book>& books);
	friend double Percentage_sold_books_circulation(vector<Book>& books, int index);

	friend ostream& operator<<(ostream& os, const vector<Book>& books);
	friend istream& operator>>(istream& is, vector<Book>& books);
	Book& operator =(const Book& other);
	bool operator >(const Book& other);
	Book& operator++();
	Book operator++(int);
	~Book();
};

Book::Book()
{
	name_of_book = "Null";
	genre_book.genre = "Null";
	genre_book.age_audience = -1;
	autor_book.name = "Null";
	autor_book.surname = "Null";
	autor_book.age_author = -1;
	total_circulation = -1;
	year_of_publication = -1;
	number_of_books_sold = -1;
}

Book::Book(const string& name_of_book, const string& genre, const int age_audience, const string& name, const string& surname, const int age_author, const size_t total_circulation, const int year_of_publication, const int number_of_books_sold)
{
	if (age_audience < 0 || age_author < 0 || total_circulation < 0 || number_of_books_sold < 0)
	{
		throw runtime_error("Error!\nInvalid input!\n");
	}
	this->name_of_book = name_of_book;
	this->genre_book.genre = genre;
	this->genre_book.age_audience = age_audience;
	this->autor_book.name = name;
	this->autor_book.surname = surname;
	this->autor_book.age_author = age_author;
	this->total_circulation = total_circulation;
	this->year_of_publication = year_of_publication;
	this->number_of_books_sold = number_of_books_sold;
}

Book::Book(const Book& copy)
{
	name_of_book = copy.name_of_book;
	genre_book.genre = copy.genre_book.genre;
	genre_book.age_audience = copy.genre_book.age_audience;
	autor_book.name = copy.autor_book.name;
	autor_book.surname = copy.autor_book.surname;
	autor_book.age_author = copy.autor_book.age_author;
	total_circulation = copy.total_circulation;
	year_of_publication = copy.year_of_publication;
	number_of_books_sold = copy.number_of_books_sold;
}

string Book::Get_Name_of_Book()const
{
	return name_of_book;
}

Genre Book::Get_Genre()const
{
	return genre_book;
}

int Book::Get_Year_of_Publication() const
{
	return year_of_publication;
}

int Book::Get_Age_Author() const
{
	return autor_book.age_author;
}


double Average_age_authors(const vector<Book>& books)
{
	double sum_age = 0;
	for (int i = 0; i < books.size(); i++)
	{
		sum_age += books[i].Get_Age_Author();
	}

	return sum_age / books.size();
}

void Add_Author(vector<Book>& books, int index, const string& _name, const string& _surname, const int _age_author)
{
	if (_age_author < 0 || books.empty() || index < 0)
	{
		throw runtime_error("Error!\nInvalid input!\n");
	}

	books[index].autor_book.name = _name;
	books[index].autor_book.surname = _surname;
	books[index].autor_book.age_author = _age_author;
}

void Delete_Author(vector<Book>& books, int index)
{
	if (books.empty() || index < 0)
	{
		throw runtime_error("Error!\nInvalid input!\n");
	}

	books[index].autor_book.name = "None";
	books[index].autor_book.surname = "None";
	books[index].autor_book.age_author = 0;
}

Author Oldest_Author(vector<Book>& books)
{
	if (books.empty())
	{
		throw runtime_error("Error!\nInvalid input!\n");
	}
	int age_author = books[0].autor_book.age_author;
	int index = 0;
	for (int i = 1; i < books.size(); i++)
	{
		if (age_author < books[i].autor_book.age_author)
		{
			age_author = books[i].autor_book.age_author;
			index = i;
		}
	}

	return books[index].autor_book;
}

double Percentage_sold_books_circulation(vector<Book>& books, int index)
{
	if (books.empty() || index < 0)
	{
		throw runtime_error("Error!\nInvalid input!\n");
	}

	return books[index].number_of_books_sold * 100 / books[index].total_circulation;
}

ostream& operator<<(ostream& os, const vector<Book>& books)
{
	for (int i = 0; i < books.size(); i++)
	{
		os << "Book name: " << books[i].name_of_book << endl;
		os << "Genre: " << books[i].genre_book.genre << endl;
		os << "Age audience: " << books[i].genre_book.age_audience << endl;
		os << "Autor name: " << books[i].autor_book.name << endl;
		os << "Autor surname: " << books[i].autor_book.surname << endl;
		os << "Autor date of birth: " << books[i].autor_book.age_author << endl;
		os << "Total circulation: " << books[i].total_circulation << endl;
		os << "Year of publication: " << books[i].year_of_publication << endl;
		os << "Number of books sold: " << books[i].number_of_books_sold << endl;
	}

	return os;
}

istream& operator>>(istream& is, vector<Book>& books)
{
	for (int i = 0; i < books.size(); i++)
	{
		cout << "Enter book name:\n";
		is.ignore();
		getline(is, books[i].name_of_book);
		cout << "Enter genre:\n";
		getline(is, books[i].genre_book.genre);
		cout << "Enter age audience:\n";
		is >> books[i].genre_book.age_audience;
		if (books[i].genre_book.age_audience < 0)
		{
			throw runtime_error("Error!\nInvalid input!\n");
		}
		cout << "Enter autor name:\n";
		is.ignore();
		getline(is, books[i].autor_book.name);
		cout << "Enter autor surname:\n";
		is.ignore();
		getline(is, books[i].autor_book.surname);
		cout << "Enter Autor date of birth:\n";
		is >> books[i].autor_book.age_author;
		if (books[i].autor_book.age_author < 0)
		{
			throw runtime_error("Error!\nInvalid input!\n");
		}
		cout << "Enter total circulation:\n";
		is >> books[i].total_circulation;
		if (books[i].total_circulation < 0)
		{
			throw runtime_error("Error!\nInvalid input!\n");
		}
		cout << "Enter year of publication:\n";
		is >> books[i].year_of_publication;
		cout << "Enter number of books sold:\n";
		is >> books[i].number_of_books_sold;
		if (books[i].number_of_books_sold < 0)
		{
			throw runtime_error("Error!\nInvalid input!\n");
		}
	}

	return is;
}

Book& Book::operator =(const Book& other)
{
	if (this == &other)
	{
		throw runtime_error("Error!\nInvalid input!\n");
	}

	this->name_of_book = other.name_of_book;
	this->genre_book.genre = other.genre_book.genre;
	this->genre_book.age_audience = other.genre_book.age_audience;
	this->autor_book.name = other.autor_book.name;
	this->autor_book.surname = other.autor_book.surname;
	this->autor_book.age_author = other.autor_book.age_author;
	this->total_circulation = other.total_circulation;
	this->year_of_publication = other.year_of_publication;
	this->number_of_books_sold = other.number_of_books_sold;

	return *this;
}

bool Book::operator>(const Book& other)
{
	return this->autor_book.age_author > other.autor_book.age_author;
}

Book& Book::operator++() 
{
	++this->year_of_publication;
	return *this;
}

Book Book::operator++(int)
{
	Book temp = *this;
	++(*this);
	return temp;
}

Book::~Book()
{
	cout << "Finish!\n";
}

int main()
{
	vector<Book> books(2);
	cin >> books;
	cout << books;
	cout << Average_age_authors(books) << endl;


	return 0;
}