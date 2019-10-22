#pragma once
#include "Transport.h"
#include "TransportInput.h"

class TransportOutput {

public:
	
	std::vector<Supplier> suppliers;
	std::vector<Customer> customers;
	std::vector<std::vector<adjacencyMatrixObject>> adjacencyMatrix; 
	
	TransportOutput();
	TransportOutput(TransportInput input);

	int calculateTotalCost();

};