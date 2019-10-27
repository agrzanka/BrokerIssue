#include "TransportInput.h"

TransportInput::TransportInput()
{
}

TransportInput::TransportInput(std::vector<Supplier> sups, std::vector<Customer> custs, std::vector<int> dem, 
	std::vector<int> supply, std::vector<int> costOP, std::vector<int> costOV, std::vector<std::vector<int>> costOfTransport)
{
	this->suppliers = sups;
	this->customers = custs;
	this->demand = dem;
	this->supply = supply;
	this->costOfPurchase = costOP;
	this->costOfVending = costOV;
	
	int totalDemand=0;
	for (auto&d : this->demand)
		totalDemand += d;

	int totalSupply = 0;
	for (auto&s : this->supply)
		totalSupply += s;

	this->demand.push_back(totalSupply);
	this->supply.push_back(totalDemand);

	this->adjacencyMatrix.resize(this->suppliers.size() + 1);
	for (int j = 0; j < this->adjacencyMatrix.size() - 1; j++)
	{
		for (int i = 0; i < this->suppliers.size(); i++)
		{
			this->adjacencyMatrix[j].push_back(adjacencyMatrixObject(costOfTransport[j][i], 0));
		}
		this->adjacencyMatrix[j].push_back(adjacencyMatrixObject(0, 0));
	}
	for (int i = 0; i < this->suppliers.size()+1; i++)
	{
		this->adjacencyMatrix[suppliers.size()].push_back(adjacencyMatrixObject(0, 0));
	}

		

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

	//North-West

	while (visited < (this->suppliers.size()*this->customers.size()))
	{
		
		iter > (this->suppliers.size()-1) ? max = (this->suppliers.size()-1) : max = iter;
		int i = l;

		for (int j = k; j < max+1 ; j++)
		{
			unitCalc(j, i);
			i--;
			visited++;
		}

		if (l < this->suppliers.size())
			l++;
		else
			k++;

		iter++;
	}

	for (int i = 0; i < this->customers.size(); i++)
	{
		unitCalc(this->suppliers.size(), i);
		visited++;
	}
	for (int j = 0; j < this->suppliers.size() + 1; j++)
	{
		unitCalc(j, this->customers.size());
		visited++;
	}
}

void TransportInput::unitCalc(int s, int c)
{
	int unit;
	this->demand[c] < this->supply[s] ? unit=this->demand[c] : unit=this->supply[s];
	this->demand[c] -= unit;
	this->supply[s] -= unit;
	this->adjacencyMatrix[s][c].setUnits(unit);
}
