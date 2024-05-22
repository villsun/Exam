#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book
{
private:
	string name_of_book;
	struct Genre
	{
		string genre;
		int age_audience;
	};
	struct Author
	{
		string name;
		string surname;
		int date_of_birth;
	};
	size_t total_circulation;
	int year_of_publication;
	int number_of_books_sold;

	Genre genre_book;
	Author autor_book;

public:
	friend ostream& operator<<(ostream& os, const Book& book);
	friend istream& operator>>(istream& is, Book& book);
};

ostream& operator<<(ostream& os, const Book& book)
{
	os << "Book name: " << book.name_of_book << endl;
	os << "Genre: " << book.genre_book.genre << endl;
	os << "Age audience: " << book.genre_book.age_audience << endl;
	os << "Autor name: " << book.autor_book.name << endl;
	os << "Autor surname: " << book.autor_book.surname << endl;
	os << "Autor date of birth: " << book.autor_book.date_of_birth << endl;
	os << "Total circulation: " << book.total_circulation << endl;
	os << "Year of publication: " << book.year_of_publication << endl;
	os << "Number of books sold: " << book.number_of_books_sold << endl;

	return os;
}

istream& operator>>(istream& is, Book& book)
{
	cout << "Enter book name:\n";
	getline(is, book.name_of_book);
	cout << "Enter genre:\n";
	getline(is, book.genre_book.genre);
	cout << "Enter age audience:\n";
	is >> book.genre_book.age_audience;
	is.ignore();
	cout << "Enter autor name:\n";
	getline(is, book.autor_book.name);
	cout << "Enter autor surname:\n";
	getline(is, book.autor_book.surname);
	cout << "Enter Autor date of birth:\n";
	is >> book.autor_book.date_of_birth;
	cout << "Enter total circulation:\n";
	is >> book.total_circulation;
	cout << "Enter year of publication:\n";
	is >> book.year_of_publication;
	cout << "Enter number of books sold:\n";
	is >> book.number_of_books_sold;

	return is;
}

int main()
{
	Book books;
	cin >> books;
	cout << books;

	return 0;
}