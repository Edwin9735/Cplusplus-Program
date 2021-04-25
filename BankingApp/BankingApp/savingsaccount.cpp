#include <iostream>
#include <iomanip>
#include "savingsaccount.h"
using namespace std;

//Constructor to initialize varibles from user input
savings::savings(double initialDeposit, double monthlyDeposit, double interestRate, int numYears) {
	this->initialInvestment = initialDeposit;
	this->monthlyDeposit = monthlyDeposit;
	this->interestRate = interestRate;
	this->numYears = numYears;
}


//Function to print out report without monthly deposits
void savings::printWithoutMonthlyDeposits() {
	//Initialize currYear to 1 to be used in while loop
	int currYear = 1;
	
	//Start off balance with the intiial investment, and initial interest with 0
	yearEndBal = initialInvestment;
	yearEndInterest = 0.0;

	//While loop iterates throught the num of years
	while (currYear <= numYears) {
		
		//Calculation of yearly interest earned
			yearEndInterest = (yearEndBal) * (interestRate / 100);
			//End of year interest is added to end of year balance
			yearEndBal += yearEndInterest;

			//Prints out the numbers calculated to user
			cout << setfill(' ') << setw(6) << right << currYear << fixed << setprecision(2);
			cout << setw(17) << "$" << yearEndBal;
			cout << setw(26) << "$" << yearEndInterest << endl;

			//Adds 1 to currYear to eventually stop while loop when it reaches the number of years user input
			++currYear;
		}	 
}

//Function to print out report without monthly deposits
void savings::printWithMonthlyDeposits() {
	//Initialize the variables to be used in this function
	int currYear = 1;
	int currMonth;
	double monthEndBal = 0.0;
	double monthEndInterest = 0.0;


	//Start off balance with initial investment and interest with 0
	yearEndBal = initialInvestment;
	//First while loop iterates through the years user input
	while (currYear <= numYears) {
		//Month balance initialized with previous year balance, and currMonth with 0 to be used in second while loop
		monthEndBal = yearEndBal;
		currMonth = 0;
		//Since each year interest is earned, yearEndInterest is start at 0 at the beginning of the year
		yearEndInterest = 0.0;
		//this while loop goes through 12 loops, one for each month in a year
		while (currMonth < 12) {
			//Every month loop adds the monthly deposit from user input
			monthEndBal += monthlyDeposit;
			//The end of month interest is calculated
			monthEndInterest = monthEndBal * ((interestRate / 100) / 12);
			//The interest is added to the end of month balance
			monthEndBal += monthEndInterest;
			//Interest is then calculated into the year end interest
			yearEndInterest += monthEndInterest;
				++currMonth;
		}
		//The full total from the while loop is then added to the end of year balance
		yearEndBal = monthEndBal;
		//Prints out calculations to the user screen
		cout << setfill(' ') << setw(6) << right << currYear << fixed << setprecision(2);
		cout << setw(17) << "$" << yearEndBal;
		cout << setw(26) << "$" << yearEndInterest << endl;
		++currYear;
	}
}