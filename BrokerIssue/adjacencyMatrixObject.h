#pragma once


class adjacencyMatrixObject {
private:

	int cost;
	int units;

public:

	adjacencyMatrixObject();
	adjacencyMatrixObject(int cost, int units);

	void setCost(int cost);
	int getCost();

	void setUnits(int units);
	int getUnits();
};