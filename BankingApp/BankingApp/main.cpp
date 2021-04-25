#include <iostream>
#include <iomanip>
#include <conio.h>
#include "savingsaccount.h"
using namespace std;
//Flores, Edwin
//CS-210-T4252 21EW4



int main() {
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int numYears;
	char userInput;
	bool continueInput = true;
	do {
		
		//Header of program
		cout << setfill('*') << setw(52) << "" << endl;
		cout << setw(20) << "";
		cout << " Data Input ";
		cout << setw(20) << "" << endl;

		//User is prompted for inputs
		cout << "Initial Investment: $";
		cin >> initialInvestment;

		cout << "Monthly Deposit: $";
		cin >> monthlyDeposit;

		cout << "Annual Interest: %";
		cin >> annualInterest;

		cout << "Number of years: ";
		cin >> numYears;
		
		//A class of stype savings is created, using the users input to initialize
		savings currentSavings = savings(initialInvestment, monthlyDeposit, annualInterest, numYears);

		//Program continues when user presses the enter key
		cout << "Press ENTER to continue . . .";
		cin.ignore();
		cin.get();
		
		//Header of the first report 
		cout << "\n\n    Balance and Interest Without Additional Monthly Deposits    " << endl;
		cout << setfill('=') << setw(64) << "" << endl;
		cout << setfill(' ') << setw(6) << right << "Year";
		cout << setw(23) << right << "Year End Balance";
		cout << setw(31) << right << "Year End Earned Interest" << endl;
		cout << setfill('-') << setw(64) << "" << endl;

		//The print function of the class is used to print out report without monthly deposits
		currentSavings.printWithoutMonthlyDeposits();

		cout << "\n\n     Balance and Interest With Additional Monthly Deposits     " << endl;
		cout << setfill('=') << setw(64) << "" << endl;
		cout << setfill(' ') << setw(6) << right << "Year";
		cout << setw(23) << right << "Year End Balance";
		cout << setw(31) << right << "Year End Earned Interest" << endl;
		cout << setfill('-') << setw(64) << "" << endl;

		// The print function of the class is used to print out report with monthly deposits
		currentSavings.printWithMonthlyDeposits();

		//user is prompted for input
		cout << "If you would like to try another, please enter 'Y' " << endl;
		cin >> userInput;
		//If input is Y, boolean value stays as true, otherwise the value becomes false
		if (userInput != 'Y') {
			continueInput = false;
		}
		//The do while loop will only continue if boolean value stayed as true, otherwise it will terminate program
	} while (continueInput == true);

	return 0;
}