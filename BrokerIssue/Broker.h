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
	int income;

	TransportOutput transport;
	//od uøytkownika weümie dane do zrobienia transportInput, z tego przejdzie do Transport Output i wtedy przypiszemy output do brokera

	Broker();
	Broker(TransportInput input);


	void iterate(std::vector<int> index);

	std::vector<int> calculateIndicatorsTable();  //if all negatives - returns empty vector, otherwise returns vector of indexes of the highest positive indicator 
									
	void calculateCoeficients();

	void cycle(std::vector<int> index);

	std::vector<int> findCycle(std::vector<int> index);
};