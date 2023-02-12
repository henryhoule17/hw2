#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "book.h"
#include "db_parser.h"
#include "util.h"
#include "mydatastore.h"

using namespace std;

int main(int argc, char* argv[])
{
	Product* book = new Book("book", "1984", 10.00, 3, "Orwell", "18838473");
	MyDataStore ds;
	ds.addProduct(book);
	return 1;
}