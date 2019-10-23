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
	//North-West
	int i;
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

		past = current;
	}
}
