#include "Customer.h"

Customer::Customer()
{
}

Customer::Customer(int d, int cost)
{
	this->costOfVending = cost;
	this->demand = d;
}
