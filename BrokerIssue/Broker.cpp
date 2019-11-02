#include "Broker.h"

Broker::Broker()
{
}

Broker::Broker(TransportInput input)
{
	this->transport = TransportOutput(input);
	this->income = this->transport.calculateTotalIncome();

	this->alphaCoefs.resize(this->transport.adjacencyMatrix.size());
	this->betaCoefs.resize(this->transport.adjacencyMatrix[0].size());

	this->indicatorsTable.resize(this->transport.adjacencyMatrix.size());
	for (int i = 0; i<int(indicatorsTable.size()); i++)
		this->indicatorsTable[i].resize(this->transport.adjacencyMatrix[0].size());
}

void Broker::iterate()
{
	//std::vector<int> minus = calculateIndicatorsTable();
	//if (minus.size()==0)
	//	return;
	//this->cycle(minus);
	//this->income=this->transport.calculateTotalIncome();
	//this->iterate();
	//return;
}

std::vector<int> Broker::calculateIndicatorsTable()
{
	for (int i =0; i<int(indicatorsTable.size()); i++)
		for (int j = 0; j < int(indicatorsTable[0].size()); j++)
			indicatorsTable[i][j] = 0;

	for (int i = 0; i<int(this->transport.adjacencyMatrix.size()); i++)
		for (int j = 0; j<int(this->transport.adjacencyMatrix[0].size()); j++)
			if (this->transport.adjacencyMatrix[i][j].getUnits() == 0)
				indicatorsTable[i][j] = this->transport.adjacencyMatrix[i][j].getCost() - alphaCoefs[i] - betaCoefs[j];
	std::vector<int> index={};
	int max = 0;

	for(int i=0;i<int(indicatorsTable.size());i++)
		for (int j = 0; j<int(indicatorsTable[0].size()); j++)
			if (indicatorsTable[i][j] > max)
			{
				max = indicatorsTable[i][j];
				index = { i,j };
			}

	return index;
}

void Broker::calculateCoeficients()
{
	for (auto&a : this->alphaCoefs)
		a = -9999;
	this->alphaCoefs[0] = 0;
	for (auto&b : this->betaCoefs)
		b =-9999;

	int non = int(this->alphaCoefs.size())*int(this->alphaCoefs.size()) - 1;

	while (non!=0)
	{
		for (int i = 0; i < int(this->alphaCoefs.size()); i++)
			if (this->alphaCoefs[i]!= -9999)
				for (int j = 0; j < int(this->betaCoefs.size()); j++)
					if (this->transport.adjacencyMatrix[i][j].getUnits() != 0)
						this->betaCoefs[j] = this->transport.adjacencyMatrix[i][j].getCost() - this->alphaCoefs[i];

		for (int j = 0; j < int(this->betaCoefs.size()); j++)
			if (this->betaCoefs[j] != -9999)
				for (int i = 1; i < int(this->alphaCoefs.size()); i++)
					if (this->transport.adjacencyMatrix[i][j].getUnits() != 0)
						this->alphaCoefs[i] = this->transport.adjacencyMatrix[i][j].getCost() - this->betaCoefs[j];

		int n = 0;
		for (auto&a : this->alphaCoefs)
			if (a == -9999)
				n++;
		for (auto&b : this->betaCoefs)
			if (b == -9999)
				n++;
		non = n;
	}
}

void Broker::cycle(std::vector<int> index)
{
}

std::vector<int> Broker::findCycle(std::vector<int> index)
{
	std::vector<int> vertical = {};
	std::vector<int> horizontal = {};

	for (int i = 0; i<int(this->indicatorsTable.size()); i++)
		if (this->indicatorsTable[i][index[1]] == 0)
			vertical.push_back(i);
	for (int j = 0; j<int(this->indicatorsTable[0].size()); j++)
		if (this->indicatorsTable[index[0]][j] == 0)
			horizontal.push_back(j);

	for (auto&i : vertical)
		for (auto&j : horizontal)
			if (this->indicatorsTable[i][j] == 0)
				return { i,j };
	return std::vector<int>();
}
