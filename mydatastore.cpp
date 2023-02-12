#include <string>
#include <set>
#include <vector>
#include <map>
#include <iostream>
#include "util.h"
#include "mydatastore.h"
#include "product_parser.h"

using namespace std;

MyDataStore::MyDataStore()
{

}

MyDataStore::~MyDataStore()
{
	for(Product* p : dump_set)
		delete p;

	for(pair<string, User*> u : users_)
		delete u.second;
}

void MyDataStore::addProduct(Product* p)
{
	dump_set.insert(p);
	for(const std::string& kw : p->keywords())
		products_[kw].insert(p);
}

void MyDataStore::addUser(User* u)
{
	users_.insert(make_pair(u->getName(), u));
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
	std::vector<Product*> hits;
	std::set<Product*> prods;
	if(type == 0)
	{
		prods = products_[terms[0]];
		for(unsigned int i=1; i<terms.size(); i++)
			prods = setIntersection(prods, products_.find(terms[i])->second);
	}
	else //if(type == 1)
	{
		prods = products_[terms[0]];
		for(unsigned int i=1; i<terms.size(); i++)
			prods = setUnion(prods, products_.find(terms[i])->second);
	}

	for(Product* prp : prods)
		hits.push_back(prp);

	return hits;
}

void MyDataStore::dump(std::ostream& ofile)
{
	ofile << "<products>" << endl;
	for(Product* p : dump_set)
		p->dump(ofile);
	ofile << "</products>" << endl;

	ofile << "<users>" << endl;
	map<std::string, User*>::iterator mit;
	for(mit = users_.begin(); mit != users_.end(); ++mit)
		mit->second->dump(ofile);
	ofile << "</users>" << endl;
}

bool MyDataStore::checkUser(std::string uname) const
{
	if(users_.find(uname) != users_.end())
		return true;
	else
		return false;
}

User* MyDataStore::getUser(std::string uname) const
{
	return users_.find(uname)->second;
}

bool MyDataStore::validKeyword(std::string word) const
{
	if(products_.find(word) == products_.end())
		return false;
	else
		return true;
}