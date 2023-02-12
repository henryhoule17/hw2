#include <sstream>
#include <iomanip>
#include <string>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const string category, const string name, 
	double price, int qty, const string brand, const string size) :
		Product(category, name, price, qty), 
		brand_(brand), 
		size_(size)
		{}

Clothing::~Clothing() {}

std::set<std::string> Clothing::keywords() const
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

	string brand = brand_;

	for(unsigned int i=0; i<brand.size(); i++)
		if(ispunct(brand[i]))
			brand.replace(i, 1, " ");
	stringstream ss2;
	ss2 << brand;

	while(ss2 >> kw)
		if(kw.size() > 1)
		{
			kw = convToLower(kw);
			keywords.insert(kw);
		}

	return keywords;
}

string Clothing::displayString() const
{
	ostringstream oss;
	oss << name_ << "\nSize: " << size_ << " " << "Brand: " << brand_
		<< "\n" << price_ << "  " << qty_ << " left";
	return oss.str();
}

void Clothing::dump(std::ostream& os) const
{
	os << category_ << endl;
	os << name_ << endl;
	os << price_ << endl;
	os << qty_ << endl;
	os << size_ << endl;
	os << brand_ << endl;
}
