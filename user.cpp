#include "user.h"
using namespace std;

User::User() : name_("unknown"), balance_(0.0), type_(1)
{

}
User::User(std::string name, double balance, int type) :
    name_(name), balance_(balance), type_(type)
{

}

User::~User()
{

}


std::string User::getName() const
{
    return name_;
}

double User::getBalance() const
{
    return balance_;
}

void User::deductAmount(double amt)
{
    balance_ -= amt;
}

void User::dump(std::ostream& os)
{
    os << name_ << " "  << balance_ << " " << type_ << endl;
}

std::deque<Product*> User::getCart() const
{
	return cart;
}
void User::addToCart(Product* p)
{
	cart.push_back(p);
}

void User::buyCart()
{
	deque<Product*>::iterator it;
	deque<Product*> newCart;
	for(it = cart.begin(); it != cart.end(); ++it)
	{
		if((*it)->getPrice() <= balance_ && (*it)->getQty() != 0)
		{
			balance_ -= (*it)->getPrice();
			(*it)->subtractQty(1);
		}
		else	
			newCart.push_back((*it));
	}
	cart = newCart;
}

void User::printCart(std::ostream& os)
{
	int i = 1;
	std::deque<Product*>::iterator it;
	for(it = cart.begin(); it != cart.end(); ++it)
	{
		string item = (*it)->displayString();
		os << "Item " << i << "\n" << item << endl << endl;
		i++;
	}
		
}