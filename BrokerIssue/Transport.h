#pragma once

#include <vector>
#include "Supplier.h"
#include "Customer.h"
#include"adjacencyMatrixObject.h"


class Transport {
public:
	std::vector<Supplier> suppliers;
	std::vector<Customer> customers;
	std::vector<std::vector<adjacencyMatrixObject>> adjacencyMatrix;
};