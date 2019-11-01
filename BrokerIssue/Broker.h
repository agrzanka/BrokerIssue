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
	std::vector<std::pair<int, bool>>alphaCoefs;
	std::vector<std::pair<int, bool>>betaCoefs;
	int income;

	TransportOutput transport;
	//od uøytkownika weümie dane do zrobienia transportInput, z tego przejdzie do Transport Output i wtedy przypiszemy output do brokera

	Broker();
	Broker(TransportInput input);


	void iterate();

	int calculateIndicatorsTable();  /*if all negatives - returns -1, otherwise returns index of the highest positive indicator 
									 index schema:			0 1 2 
															3 4 5  
															6 7 8			etc. */
	void calculateCoeficients();

	void cycle(int minus);
};