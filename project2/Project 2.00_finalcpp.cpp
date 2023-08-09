#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	//Declare variables for the user input
	float initialInvestment, monthlyDeposit, annualInterest, months, years;


	float totalAmount, interestAmount, annualTotalInterest;

	//This Section shows the user a menu
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;


	//In this section the user enters input
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: $" << endl;
	cin >> initialInvestment;
	cout << "Monthly Deposit: $" << endl;
	cin >> monthlyDeposit;
	cout << "Annual Interest: %" << endl;
	cin >> annualInterest;
	cout << "Number of years: " << endl;
	cin >> years;
	months = years * 12;



	//Update total amount to initial investment
	totalAmount = initialInvestment;



	cout << endl << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	//This loop calculates the balance and earned annual interest
	for (int i = 0; i < years; i++) {
		interestAmount = ((totalAmount) * (annualInterest / 100));

		totalAmount = totalAmount + interestAmount;

		//This line puts the dollar and cent amount set to 2  decimal places for cents
		cout << (i + 1) << "\t\t\t\t\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << interestAmount << endl;
	}


	totalAmount = initialInvestment;

	//This Displays the year end of the year balance with monthly deposits
	cout << endl << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;




	for (int i = 0; i < 12; i++) {
		interestAmount = (((totalAmount + monthlyDeposit) * (annualInterest / 100)) / 12);

		annualTotalInterest = annualTotalInterest + interestAmount;

		totalAmount = totalAmount + monthlyDeposit + interestAmount;

		//This line puts the dollar and cent amount set to 2  decimal places for cents
		cout << (i + 1) << "\t\t\t\t\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << annualTotalInterest << endl;

	}
	return 0;
}