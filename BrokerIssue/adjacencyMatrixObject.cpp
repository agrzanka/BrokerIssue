#include "adjacencyMatrixObject.h"

adjacencyMatrixObject::adjacencyMatrixObject()
{
}

adjacencyMatrixObject::adjacencyMatrixObject(int cost, int units)
{
	this->cost = cost;
	this->units = units;
}

void adjacencyMatrixObject::setCost(int cost)
{
	this->cost = cost;
}

int adjacencyMatrixObject::getCost()
{
	return this->cost;
}

void adjacencyMatrixObject::setUnits(int units)
{
	this->units = units;
}

int adjacencyMatrixObject::getUnits()
{
	return this->units;
}
