#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const string category, const string name, 
	double price, int qty, const string author, const string ISBN) :
		Product(category, name, price, qty), 
		author_(author), 
		ISBN_(ISBN)
		{}

Book::~Book()
{

}

set<std::string> Book::keywords() const
{
	set<std::string> keywords;

	std::string name = name_;
	for(unsigned int i=0; i<name.size(); i++)
	{
		if(ispunct(name[i]))
			name.replace(i, 1, " ");
	}

	stringstream ss;
	ss << name;
	std::string kw;

	while(ss >> kw)
		if(kw.size() > 1)
		{
			kw = convToLower(kw);
			keywords.insert(kw);
		}


	std::string aut = author_;

	for(unsigned int i=0; i<aut.size(); i++)
	{
		if(ispunct(aut[i]))
			aut.replace(i, 1, " ");
	}
	stringstream ss2;
	ss2 << aut;

	while(ss2 >> kw)
		if(kw.size() > 1)
		{
			kw = convToLower(kw);
			keywords.insert(kw);
		}

	keywords.insert(ISBN_);

	return keywords;
}

std::string Book::displayString() const
{
	ostringstream oss;
	oss << name_ << "\nAuthor: " << author_ << " " << "ISBN: " << ISBN_
		<< "\n" << price_ << "  " << qty_ << " left";

	return oss.str();
}

void Book::dump(std::ostream& os) const
{
	os << category_ << endl;
	os << name_ << endl;
	os << price_ << endl;
	os << qty_ << endl;
	os << ISBN_ << endl;
	os << author_ << endl;
}

