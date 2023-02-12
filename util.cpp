#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <string>
#include <set>
#include "util.h"

using namespace std;
/*std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}*/

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(std::string rawWords)
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
/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

std::string convToLower(std::string src)
{
	for(unsigned int i=0; i<src.length(); i++)
		src[i] = tolower(src[i]);
	
	return src;
}