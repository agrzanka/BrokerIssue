#include "TransportInput.h"

TransportInput::TransportInput()
{
}

TransportInput::TransportInput(std::vector<Supplier> sups, std::vector<Customer> custs, std::vector<int> dem, std::vector<int> supply, std::vector<int> costOP, std::vector<int> costOV, std::vector<std::vector<int>> costOfTransport)
{
}

void TransportInput::calculateFinalCosts()
{
	for (int s = 0; s < int(this->suppliers.size()); s++)
	{
		this->adjacencyMatrix[s][this->customers.size()].setCost(0);
		for (int c = 0; c < int(this->customers.size()); c++)
			this->adjacencyMatrix[s][c].setCost(this->costOfVending[c] - this->adjacencyMatrix[s][c].getCost() - this->costOfPurchase[s]);
	}
	for (int c = 0; c < int(this->customers.size()); c++)
		this->adjacencyMatrix[this->suppliers.size()][c].setCost(0);
}

void TransportInput::calculateTransportUnits()
{

	int k = 0; //suppliers' iterator
	int l = 0; //customers' iterator
	int iter = 0; //iterators' iterator XDDDDDD
	int visited = 0; //visited data in matrix
	int max; //maximal iteraor

	while (visited < (this->suppliers.size()*this->customers.size()))
	{
		
		iter > (this->customers.size()) ? max = (this->customers.size()) : max = iter;
		int i = l;

		for (int j = k; j < max ; j++)
		{
			//calculate();
			i--;
			visited++;
		}

		if (l < this->customers.size()-1)
			l++;
		else
			k++;

		iter++;
	}
	int erg2r = visited;
	int c = this->customers.size();
	int s = this->suppliers.size();
	for (int i = 0; i < this->customers.size(); i++)
	{
		//calculate();
		visited++;
	}
	for (int j = 0; j < this->suppliers.size() + 1; j++)
	{
		//calculate();
		visited++;
	}

	int dddjfkgkhjvjgxd = visited;
	//North-West

	/*int sup = 0, cust = 0;
	int maxTimes = 0;
	int remain = int(suppliers.size()*customers.size());

	while (remain>0)
	{
		for (int i = sup; i > -1; i--)
		{
			if (cust + maxTimes<int(customers.size()))
			{
				unitCalc(i, cust+maxTimes);
				cust++;
				remain--;
			}

			if (sup < suppliers.size())
				sup++;
			else
				maxTimes++;

			cust = 0;
		}

		for (int i = 0; i<int(customers.size()); i++)
			unitCalc(int(suppliers.size()), i);
		for (int j = 0; j<int(suppliers.size()); j++)
			unitCalc(j, int(customers.size()));*/


	/*int i;
	this->suppliers.size() < this->customers.size() ? i = this->suppliers.size() : i = this->customers.size();
	int past = 0;
	int current = 0;
	int u;
	this->demand[0] < this->supply[0] ? u = this->demand[0] : u = this->supply[0];
	u>=0?this->adjacencyMatrix[0][0].setUnits(u): this->adjacencyMatrix[0][0].setUnits(0);
	if (u > 0)
	{
		this->demand[0] -= u;
		this->supply[0] -= u;
	}
	current++;
	for (current; current < i; current++)
	{
		this->demand[past] < this->supply[current] ? u = this->demand[past] : u = this->supply[current];
		u >= 0 ? this->adjacencyMatrix[current][past].setUnits(u) : this->adjacencyMatrix[current][past].setUnits(0);
		if (u > 0)
		{
			this->demand[past] -= u;
			this->supply[current] -= u;
		}

		this->demand[current] < this->supply[past] ? u = this->demand[current] : u = this->supply[past];
		u >= 0 ? this->adjacencyMatrix[past][current].setUnits(u) : this->adjacencyMatrix[past][current].setUnits(0);
		if (u > 0)
		{
			this->demand[current] -= u;
			this->supply[past] -= u;
		}

		this->demand[current] < this->supply[current] ? u = this->demand[current] : u = this->supply[current];
		u >= 0 ? this->adjacencyMatrix[current][current].setUnits(u) : this->adjacencyMatrix[current][current].setUnits(0);
		if (u > 0)
		{
			this->demand[current] -= u;
			this->supply[current] -= u;
		}

		past = current;*/
	
}

void TransportInput::unitCalc(int s, int c)
{


}
