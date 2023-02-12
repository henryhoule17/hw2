#include <string>
#include <set>
#include <vector>
#include "datastore.h"

/**
 * DataStore Interface needed for parsing and instantiating products and users
 *
 * A derived version of the DataStore can provide other services as well but
 * must support those below
 *
 * DO NOT EDIT
 */

class MyDataStore : public DataStore {
public:

		MyDataStore();
    
		~MyDataStore();

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);

		bool checkUser(std::string uname) const;

		User* getUser(std::string uname) const;

		bool validKeyword(std::string word) const;

	private:

		std::set<Product*> dump_set;
		std::map<std::string, std::set<Product*>> products_;
		std::map<std::string, User*> users_;
};