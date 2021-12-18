#include "BlackScholesMCPricer.h"
#include "MT.h"
#include "AsianOption.h"
#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility) :
	option(option), S0(initial_price), r(interest_rate), sigma(volatility) {
	generated_paths = 0;

}

long BlackScholesMCPricer::getNbPaths() {
	return generated_paths;
}

double BlackScholesMCPricer::generate(int nb_paths) {
	generated_paths += nb_paths;
	std::vector<double> Zk(nb_paths);
	std::vector<double> Sk(nb_paths);
	std::vector<double> Times(nb_paths);
	if (nb_paths == 0) {
		throw std::invalid_argument("0 added paths");
	}
	if (option->isAsianOption()) {
		Times = ((AsianOption*)option)->getvec(); // Forcage de type
	}
	else {
		Times[0] = option->getExpiry();
	}
	double res = 0;
	for (int k = 0; k < nb_paths; k++) {
		// Generation of a new path
		for (int i = 0; i < Times.size(); i++) {
			Zk[i] = MT::rand_norm();
			if (i != 0) {
				Sk[i] = Sk[i - 1] * exp((r - (sigma * sigma) / 2) * ((Times[i] - Times[i - 1]) + sigma * sqrt(Times[i] - Times[i - 1]) * Zk[i]));

			}
			else {
				Sk[i] = S0 * exp((r - (sigma * sigma) / 2) * (Times[0] + sigma * sqrt(Times[0]) * Zk[0]));
			}
		}
		// Adding the path to the computation of the price
		res += option->payoffPath(Sk);
	}
	res = res * (exp(-r * option->getExpiry()));
	price = ((generated_paths - nb_paths) * price + res) / generated_paths;
	return price;
}

double BlackScholesMCPricer::operator()() {
	if (generated_paths == 0) {
		throw std::invalid_argument("Undefined estimate"); // Throws an exception if the pricer is not defined
	}
	else {
		return price;
	}
}

//CDF of N(0,1) (cf BlackScholesPricer.cpp)
double normalDistribution(double x) {
	double k = 1.0 / (1.0 + 0.2316419 * x);
	double k_sum = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));
	
	if (x >= 0.0) {
		return (1.0 - (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * x * x) * k_sum);
	}
	else {
		return 1.0 - normalDistribution(-x);
	}
}

//Confidence interval at 95%
std::vector<double> BlackScholesMCPricer::confidenceInterval() {
	std::vector<double> IC(2);
	double z = normalDistribution(0.975);
	double mu = price;
	double sigma_estim = sigma / sqrt(generated_paths);
	double lower_bound = mu - z * sigma_estim;
	double upper_bound = mu + z * sigma_estim;
	IC[0] = lower_bound;
	IC[1] = upper_bound;
	std::cout << "Confidence interval at 95% : [" << lower_bound << ";" << upper_bound << "]" << endl;
	return IC;
}

