#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <string>
using namespace std;

class savings {
	public:
		//Declaration of functions to be used
		savings(double initialDeposit, double monthlyDeposit, double interestRate, int numYears);
		void printWithoutMonthlyDeposits();
		void printWithMonthlyDeposits();

	private:
		//Declaration of variables to be used
		double initialInvestment;
		double monthlyDeposit;
		double interestRate;
		double yearEndBal;
		double yearEndInterest;
		double monthEndInterest;
		int numYears;
	
};


#endif