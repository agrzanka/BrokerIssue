#include "TransportOutput.h"

TransportOutput::TransportOutput()
{
}

TransportOutput::TransportOutput(TransportInput input)
{
	this->adjacencyMatrix = input.adjacencyMatrix;
	this->customers = input.customers;
	this->suppliers = input.suppliers;
}

int TransportOutput::calculateTotalIncome()
{
	int income = 0;
	for (int i = 0; i < this->adjacencyMatrix.size(); i++)
		for (int j = 0; j < this->adjacencyMatrix[i].size(); j++)
			income += this->adjacencyMatrix[i][j].getCost()*this->adjacencyMatrix[i][j].getUnits();

	return income;
}
