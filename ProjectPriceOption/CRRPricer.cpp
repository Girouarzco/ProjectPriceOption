#include "CRRPricer.h"
#include  <math.h>
#include <iostream>
#include <vector>
#include "Option.h"
using namespace std;

CRRPricer::CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate)
{


		if (down < interest_rate && interest_rate < up)
		{
			this->S0 = asset_price;
			this->U = up;
			this->D = down;
			this->R = interest_rate;
			this->N = depth;
			this->option = option;
			BinaryTree<double> t;
			t.setDepth(N);
			this->payofftree = t;

		}
		else { std::cout << "Une de ces conditions n'est pas respéctée"; }

}
void CRRPricer::setS0(double S0)
{
	this->S0 = S0;
}
void CRRPricer::setU(double U)
{
	this->U = U;
}
void CRRPricer::setD(double D)
{
	this->D = D;
}
void CRRPricer::setR(double R)
{
	this->R = R;
}
double CRRPricer::getS0() const
{
	return this->S0;
}
double CRRPricer::getU() const
{
	return this->U;
}
double CRRPricer::getD() const
{
	return this->D;
}
double CRRPricer::getR() const
{
	return this->R;
}
void CRRPricer::compute()
{
	if (S0 > 0 && U > D && D > -1)
	{
		treestructure.setDepth(N);
		for (int k = 0; k <= N; k++)
		{
			for (int i = 0; i <= k; i++)
			{
				double S = S0 * pow(1 + U, i) * pow(1 + D, k - i);
				treestructure.SetNode(k, i, S);
			}
		}
	}
	else { std::cout << "Une de ces conditions n'est pas respéctée : S0 > 0, U > D , D > -1"; }
}
double CRRPricer::RNP() const
{
	return (R - D) / (U - D);
}
double CRRPricer::get(int n, int i)
{
	if (n == N) { return option->payoff(treestructure.GetNode(N, i)); }
	else { return (RNP() * payofftree.GetNode(n + 1, i + 1) + (1 - RNP()) * payofftree.GetNode(n + 1, i)) / (1 + R); }
}
double CRRPricer::operatorfunc()
{
	compute();
	for (int i = N; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			payofftree.SetNode(i, j, get(i, j));
		}
	}
	return payofftree.GetNode(0, 0);
}

long factorial(int n)
{
	long factorial = 1;
	for (int i = 1; i <= n; ++i)
	{
		factorial *= i;
	}
	return factorial;
}
double CRRPricer::closedformula()
{
	double sum = 0.;
	for (int i = 0; i <= N; i++)
	{
		sum = sum + (factorial(N) * pow(RNP(), i) * pow(1 - RNP(), N - i) * get(N, i) * (1 / (factorial(i) * factorial(N - i)))); //pow(x,y) for x^y
	}
	sum = sum / pow(1 + getR(), N);
	return sum;
}