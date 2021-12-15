#pragma once
#include "Option.h"
#include "BinaryTree.h"
class CRRPricer
{
public:
	CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
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
	double operator()(bool closed_form =false);
	double RNP() const;
	double closedformula();
private:
	int N;
	double S0, U, D, R;
	BinaryTree<double>  treestructure;
	BinaryTree<double>  payofftree;
	Option* option;
};
