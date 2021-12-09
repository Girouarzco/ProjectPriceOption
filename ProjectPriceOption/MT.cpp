#include "MT.h"
#include "MT.h"
#include <random>
double MT::rand_unif()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> distribution(0, 1);
	double temp = distribution(gen);
	return temp;
}
double MT::rand_norm()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<double> distribution(0, 1);
	double temp = distribution(gen);
	return temp;
}

