#include "BlackScholesMCPricer.h"
#include "Option.h"
#include "MT.h"
#include "AsianOption.h"
#include <numeric>
#include <iostream>
#include <vector>
#include <algorithm>

BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility)
{
	this->option = option;
	this->interest_rate = interest_rate;
	this->assetprice = initial_price;
	this->volatility = volatility;
	this->sum = 0;
	this->sum_sqrt = 0;
	this->NbPaths = 0;
}

int BlackScholesMCPricer::getNbPaths()
{
	return NbPaths;
}
void BlackScholesMCPricer::setnbpaths(int x )
{
	this->NbPaths = x;
}
void BlackScholesMCPricer::generate(int nb_paths)
{
	std::vector<double> t;
	NbPaths += nb_paths ;
	if (option->isAsianOption() == false)
	{
		
		t.push_back(0.0);
		t.push_back(option->getExpiry());
	}
	else
	{
		t.push_back(0.0);
		t = ((AsianOption*)option)->getvec();
	}
	std::vector<double> payoffspaths ;
	for (int n = 0; n < getNbPaths(); n++)
	{
		std::vector<double> S;
		for (int i = 1; i < t.size(); i++)
		{
			currentestimation = assetprice * exp((interest_rate - (volatility*volatility/ 2)) *
			(t[i]-t[i-1]) + volatility*pow(t[i] - t[i - 1],0.5) * MT::rand_norm());
			S.push_back(currentestimation);
		}
		payoffspaths.push_back(option->payoffPath(S));
	}
	double sum_of_paths = 0;
	for (int k = 0; k < payoffspaths.size(); k++)
	{
		sum_of_paths += payoffspaths[k];
	}
	sum = sum_of_paths;
	sum_sqrt = sum_of_paths * sum_of_paths;
	currentestimation = exp(- interest_rate * option->getExpiry()) / nb_paths *sum_of_paths ;
}
double BlackScholesMCPricer::operator()()
{
	if (currentestimation<0)
	{
		throw std::invalid_argument("Une de ces conditions n'est pas respéctée");
	}
	return currentestimation;
}

std::vector<double> BlackScholesMCPricer::confidenceInterval()
{
	double sd = sqrt(1 / double(NbPaths) * sum_sqrt - pow(1 / double(NbPaths) * sum, 2));
	std::vector<double> bounds;
	bounds.push_back(currentestimation - 1.96 * sd / NbPaths);
	bounds.push_back(currentestimation + 1.96 * sd / NbPaths);

	return bounds;
}

