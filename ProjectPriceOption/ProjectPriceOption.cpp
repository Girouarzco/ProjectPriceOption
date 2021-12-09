#include <iostream>
#include "CallOption.h"
#include "PutOption.h"
#include "DigitalCall.h"
#include "DigitalPut.h"
#include "BlackScholesPricer.h"
#include "CRRPricer.h"
#include "BinaryTree.h"
#include "AsianCallOption.h"
#include "AsianPutOption.h"
#include "BlackScholesMCPricer.h"
using namespace std;
int main()
{

    {
        /*
        double S0(82.), K(80.), T(2.), r(0.05), sigma(0.25);
        CallOption opt1(T, K);
        PutOption opt2(T, K);


        std::cout << "European options 1" << std::endl << std::endl;

        {
            BlackScholesPricer pricer1(&opt1, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer1.Operator() << ", delta=" << pricer1.delta() << std::endl;

            BlackScholesPricer pricer2(&opt2, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer2.Operator() << ", delta=" << pricer2.delta() << std::endl;
            std::cout << std::endl;

            int N(150);
            double U = exp(sigma * sqrt(T / N)) - 1.0;
            double D = exp(-sigma * sqrt(T / N)) - 1.0;
            double R = exp(r * T / N) - 1.0;

            CRRPricer crr_pricer1(&opt1, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer1.operatorfunc() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer1.closedformula() << std::endl;
            std::cout << endl;

            CRRPricer crr_pricer2(&opt2, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer2.operatorfunc() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer2.closedformula() << std::endl;
        }
        std::cout << std::endl << "*********************************************************" << std::endl;
    }

    {
        std::cout << "Binary Tree" << std::endl << std::endl;
        BinaryTree<bool> t1;
        t1.setDepth(3);
        t1.SetNode(1, 1, true);
        t1.Display();
        t1.setDepth(5);
        t1.Display();
        t1.setDepth(3);
        t1.Display();


        BinaryTree<double> t2;
        t2.setDepth(2);
        t2.SetNode(2, 1, 3.14);
        t2.Display();
        t2.setDepth(4);
        t2.Display();
        t2.setDepth(3);
        t2.Display();

        BinaryTree<int> t3;
        t3.setDepth(4);
        t3.SetNode(3, 0, 8);
        t3.Display();
        t3.setDepth(2);
        t3.Display();
        t3.setDepth(4);
        t3.Display();

        std::cout << std::endl << "*********************************************************" << std::endl;
    }

   {
   
        double S0(95.), K(100.), T(0.5), r(0.02), sigma(0.2);
        DigitalCall opt1(T, K);
        DigitalPut opt2(T, K);


        std::cout << "European options 2" << std::endl << std::endl;

        {
            BlackScholesPricer pricer1(&opt1, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer1.Operator() << ", delta=" << pricer1.delta() << std::endl;

            BlackScholesPricer pricer2(&opt2, S0, r, sigma);
            std::cout << "BlackScholesPricer price=" << pricer2.Operator() << ", delta=" << pricer2.delta() << std::endl;
            std::cout << std::endl;

            int N(150);
            double U = exp(sigma * sqrt(T / N)) - 1.0;
            double D = exp(-sigma * sqrt(T / N)) - 1.0;
            double R = exp(r * T / N) - 1.0;

            CRRPricer crr_pricer1(&opt1, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer1.operatorfunc() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer1.closedformula() << std::endl;
            std::cout << endl;

            CRRPricer crr_pricer2(&opt2, N, S0, U, D, R);
            std::cout << "Calling CRR pricer with depth=" << N << std::endl;
            std::cout << std::endl;
            std::cout << "CRR pricer computed price=" << crr_pricer2.operatorfunc() << std::endl;
            std::cout << "CRR pricer explicit formula price=" << crr_pricer2.closedformula() << std::endl;
        }
        std::cout << std::endl << "*********************************************************" << std::endl;
        */
        double S0(95.), K(100.), T(0.5), r(0.02), sigma(0.2);
        std::vector<Option*> opt_ptrs;
        opt_ptrs.push_back(new CallOption(T, K));
        opt_ptrs.push_back(new PutOption(T, K));
        opt_ptrs.push_back(new DigitalCall(T, K));
        opt_ptrs.push_back(new DigitalPut(T, K));

        std::vector<double> fixing_dates;
        for (int i = 1; i <= 5; i++) {
            fixing_dates.push_back(0.1 * i);
        }
        opt_ptrs.push_back(new AsianCallOption(fixing_dates, K));
        opt_ptrs.push_back(new AsianPutOption(fixing_dates, K));

        std::vector<double> ci;
        BlackScholesMCPricer* pricer;
        std::cout << "Hello";
        for (auto& opt_ptr : opt_ptrs) {
            pricer = new BlackScholesMCPricer(opt_ptr, S0, r, sigma);
            //do {
            std::cout << pricer->generate(10);
            std::cout << ":::";
                ///ci = pricer->confidenceInterval();
            //} while (ci[1] - ci[0] > 1e-2);
            //std::cout << "nb samples: " << pricer->getNbPaths() << std::endl;
            delete pricer;
            delete opt_ptr;
        }
        std::cout << "hi";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
