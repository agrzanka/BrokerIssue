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
