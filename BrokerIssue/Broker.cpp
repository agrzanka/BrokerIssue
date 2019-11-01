#include "Broker.h"

Broker::Broker()
{
}

Broker::Broker(TransportInput input)
{
	this->transport = TransportOutput(input);
	this->income = this->transport.calculateTotalIncome();
}

void Broker::iterate()
{
	int minus = calculateIndicatorsTable();
	if (minus == -1)
		return;
	this->cycle(minus);
	this->income=this->transport.calculateTotalIncome();
	this->iterate();
	return;
}

int Broker::calculateIndicatorsTable()
{
	return 0;
}

void Broker::calculateCoeficients()
{
	this->alphaCoefs.resize(this->transport.adjacencyMatrix.size());
	this->betaCoefs.resize(this->transport.adjacencyMatrix[0].size());
	for (auto&a : this->alphaCoefs)
		a = { -9999, 0 };
	this->alphaCoefs[0] = { 0,0 };
	for (auto&b : this->betaCoefs)
		b = { -9999, 0 };

	int aplphaCalculated = 1;
	int betaCalculated = 0;

	int non = int(this->alphaCoefs.size())*int(this->alphaCoefs.size()) - 1;

	//while (aplphaCalculated != int(this->alphaCoefs.size()) || betaCalculated != int(this->betaCoefs.size()))
	while (non!=0)
	{
		for (int i = 0; i < int(this->alphaCoefs.size()); i++)
		{
			if (this->alphaCoefs[i].first != -9999)// && this->alphaCoefs[i].second == 0)
			{
				for (int j = 0; j < int(this->betaCoefs.size()); j++)
				{
					if (this->transport.adjacencyMatrix[i][j].getUnits() != 0)
					{
						this->betaCoefs[j].first = this->transport.adjacencyMatrix[i][j].getCost() - this->alphaCoefs[i].first;
						betaCalculated++;
					}
				}
				this->alphaCoefs[i].second = 1;
			}
		}

		for (int j = 0; j < int(this->betaCoefs.size()); j++)
		{
			if (this->betaCoefs[j].first != -9999)// && this->betaCoefs[j].second == 0)
			{
				for (int i = 1; i < int(this->alphaCoefs.size()); i++)
				{
					if (this->transport.adjacencyMatrix[i][j].getUnits() != 0)
					{
						this->alphaCoefs[i].first = this->transport.adjacencyMatrix[i][j].getCost() - this->betaCoefs[j].first;
						aplphaCalculated++;
					}
				}
			}
			this->betaCoefs[j].second = 1;
		}

		int n = 0;
		for (auto&a : this->alphaCoefs)
			if (a.first == -9999)
				n++;
		for (auto&b : this->betaCoefs)
			if (b.first == -9999)
				n++;
		non = n;

	}

	int k = betaCalculated + aplphaCalculated;
}

void Broker::cycle(int minus)
{
}
