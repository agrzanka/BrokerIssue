#pragma once
#include <vector>
#include "adjacencyMatrixObject.h"
#include "Customer.h"
#include"Supplier.h"
//#include"TransportOutput.h"
#include "Transport.h"
#include "adjacencyMatrixObject.h"

class TransportInput {
public:
	std::vector<Supplier> suppliers;
	std::vector<Customer> customers;
	std::vector<std::vector<adjacencyMatrixObject>> adjacencyMatrix;		//it also has a FictionSupplier and FictionCustomer

	TransportInput();
	TransportInput(std::vector<Supplier>sups, std::vector<Customer>custs, std::vector<int>dem, std::vector<int>supply,
		std::vector<int>costOP, std::vector<int>costOV, std::vector<std::vector<int>>costOfTransport);
	void calculateFinalCosts();
	void calculateTransportUnits();

	//TransportOutput calculateTransport();

	std::vector<int> demand;
	std::vector<int> supply;
	std::vector<int> costOfPurchase;
	std::vector<int> costOfVending;
};