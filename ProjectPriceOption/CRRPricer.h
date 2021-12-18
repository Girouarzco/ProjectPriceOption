#pragma once
#include "Option.h"
#include "BinaryTree.h"

class CRRPricer
{
public:
	CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
	CRRPricer(Option* option, int depth, double asset_price, double r, double volatility);
	double getS0() const;
	double getU() const;
	double getD() const;
	double getR() const;
	void setS0(double S0);
	void setU(double U);
	void setD(double D);
	void setR(double R);
	void compute();
	double get(int, int);
	double operator()(bool booltest = false);
	double RNP() const;
	double closedformula();
	bool getExercise(int, int);

private:
	int N;
	double S0, U, D, R;
	BinaryTree<double>  treestructure;
	BinaryTree<double>  payofftree;
	BinaryTree<bool> Americanpayofftree;
	Option* option;
};
