#include <sstream>
#include <iomanip>
#include <string>
#include "movie.h"
#include "util.h"
using namespace std;

Movie::Movie(const string category, const string name, 
	double price, int qty, const string genre, const string rating) :
		Product(category, name, price, qty), 
		genre_(genre), 
		rating_(rating)
		{}

Movie::~Movie() {}

std::set<std::string> Movie::keywords() const
{
	set<string> keywords;

	string name = name_;

	for(unsigned int i=0; i<name.size(); i++)
		if(ispunct(name[i]))
			name.replace(i, 1, " ");


	stringstream ss;
	ss << name;
	string kw;

	while(ss >> kw)
		if(kw.size() > 1)
		{
			kw = convToLower(kw);
			keywords.insert(kw);
		}

	string genre = genre_;

	for(unsigned int i=0; i<genre.size(); i++)
		if(ispunct(genre[i]))
			genre.replace(i, 1, " ");
	
	stringstream ss2;
	ss2 << genre;

	while(ss2 >> kw)
		if(kw.size() > 1)
		{
			kw = convToLower(kw);
			keywords.insert(kw);
		}

	return keywords;
}

string Movie::displayString() const
{
	ostringstream oss;
	oss << name_ << "\nGenre: " << genre_ << " " << "Rating: " << rating_
		<< "\n" << price_ << "  " << qty_ << " left";
	return oss.str();
}

void Movie::dump(std::ostream& os) const
{
	os << category_ << endl;
	os << name_ << endl;
	os << price_ << endl;
	os << qty_ << endl;
	os << genre_ << endl;
	os << rating_ << endl;
}