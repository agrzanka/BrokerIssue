#include "Broker.h"

Broker::Broker()
{
}

Broker::Broker(TransportInput input)
{
	this->transport = TransportOutput(input);
	this->income = this->transport.calculateTotalIncome();
}

void Broker::iterate()
{
	int minus = calculateIndicatorsTable();
	if (minus == -1)
		return;
	this->cycle(minus);
	this->income=this->transport.calculateTotalIncome();
	this->iterate();
	return;
}
