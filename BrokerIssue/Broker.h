#pragma once
#include "Transport.h"
#include "TransportInput.h"
#include "TransportOutput.h"
#include "Supplier.h"
#include "Customer.h"
#include "adjacencyMatrixObject.h"

#include <vector>
#include <iostream>

class Broker {

public:
	std::vector<std::vector<int>>indicatorsTable;
	std::vector<int>alphaCoefs;
	std::vector<int>betaCoefs;

	TransportInput tIN;

	Broker();
	Broker(TransportInput);


	void iterate();

	int calculateIndicatorsTable();  /*if all negatives - returns -1, otherwise returns index of the highest positive indicator 
									 index schema:			0 1 2 
															3 4 5  
															6 7 8			etc. */
	void calculateCoeficients();
};