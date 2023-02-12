#include <iostream>
#include <string>
#include <set>
#include <cctype>
#include <sstream>
#include <iterator>

using namespace std;

set<string> parseStringToWords(string rawWords)
{
	set<string> keywords;

	//replaces all punctuation wil a space
	for(unsigned int i=0; i<rawWords.size(); i++)
	{
		if(ispunct(rawWords[i]))
			rawWords.replace(i, 1, " ");
	}
	
	stringstream ss;
	ss << rawWords;
	string wrd;

	//adds each word to the set
	while (ss >> wrd)
	{ 
		if(wrd.size() > 1)
			keywords.insert(wrd);
	}	

	return keywords;
}

std::set<int> setIntersection(std::set<int>& s1, std::set<int>& s2)
{
	std::set<int> insec;
	for(set<int>::iterator it = s1.begin(); it != s1.end(); ++it)
	{
		if(s2.find(*it) != s2.end())
		{
			insec.insert(*it);
		}
	}

	return insec;
}

std::set<int> setUnion(std::set<int>& s1, std::set<int>& s2)
{
	std::set<int> un;
	for(set<int>::iterator it = s1.begin(); it != s1.end(); ++it)
		un.insert(*it);

	for(set<int>::iterator iter = s2.begin(); iter != s2.end(); ++iter)
		un.insert(*iter);

	return un;
}

int main(int argc, char* argv[])
{

	set<int> s1 = {1, 3, 5, 7, 9};
	set<int> s2 = {2, 4, 6, 8, 10, 3, 5, 9};

	set<int> is = setUnion(s1, s2);

	for(set<int>::iterator it = is.begin(); it != is.end(); ++it)
		cout << *it << endl;

	return 0;
}