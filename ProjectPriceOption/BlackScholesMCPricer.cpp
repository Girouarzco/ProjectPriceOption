#include "BlackScholesMCPricer.h"
#include "Option.h"
#include "MT.h"
#include <iostream>
BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility)
{
	this->option = option;
	this->interest_rate = interest_rate;
	this->asset_price = initial_price;
	this->volatility = volatility;
}

int BlackScholesMCPricer::getNbPaths()
{
	return NbPaths;
}

double BlackScholesMCPricer::generate(int nb_paths)
{
	std::vector<double> S;
	if (option->isAsianOption() == false)
	{
		nb_paths = 1;//m
	}
	currentestimation = asset_price;
	for (int i = 1; i <= nb_paths; i++)
	{
		NbPaths++;
		currentestimation = currentestimation * exp((interest_rate - (pow(volatility, 2) / 2)) *
			(((i * option->getExpiry()/ nb_paths) - ((i - 1) * option->getExpiry() / nb_paths)))
			+ volatility * sqrt((i * option->getExpiry() / nb_paths) - ((i - 1) * option->getExpiry() / nb_paths)) * MT::rand_norm());
		S.push_back(currentestimation);
	}
	double sum = 0;
	for (int i = 0; i < nb_paths; i++)
	{
		sum += S[i];
	}
	return exp(interest_rate * option->getExpiry()) * (1 / nb_paths) * option->payoff(sum);
}
double BlackScholesMCPricer::operatorfunc()
{
	if (currentestimation == NULL)
	{
		throw std::invalid_argument("Une de ces conditions n'est pas respéctée");
	}
	return currentestimation;
}

