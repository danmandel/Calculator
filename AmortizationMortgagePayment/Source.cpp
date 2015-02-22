#include <iostream>
#include <cmath>
#include <iomanip>
#include "divisor.h"
#include "multiplier.h"

using namespace std;

int main()
{
	const int monthsInYear = 12;
	const int percentDenominator = 100;

	double principal = 0.0;
	cout << "Enter the principal amount: ";
	cin >> principal;

	double humanInterest = 0.0;
	cout << "Enter the interest rate: ";
	cin >> humanInterest;
	double interest = divisor(humanInterest, percentDenominator);

	int yearsOfLoan = 0.0;
	cout << "Enter the years of loan: ";
	cin >> yearsOfLoan;

	double monthInterest = divisor(interest, monthsInYear);
	long monthsOfLoan = multiplier(yearsOfLoan,monthsInYear);

	double payment = 0.0;
	payment = principal *(monthInterest /
		(1 - (pow((double)1 + monthInterest, (double)-monthsOfLoan))));

	cout << "Monthly Payment: " << setiosflags(ios::fixed) //keep decimal point in particuar precision
		<< setprecision(2) << payment << endl;

	double currInterestPayment = 0.0;
	double currPrincipalPayment = 0.0;
	double currBalance = 0.0;
	long currLoanMonth = 1;
	currBalance = principal;

	while (currLoanMonth <= monthsOfLoan){
		cout << "Current Month: " << currLoanMonth << endl;
		currLoanMonth++;
	}

	cout << "Loan complete"<< endl;
	system("pause");
	return 0;
}
