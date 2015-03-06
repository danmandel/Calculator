#include <iostream>
#include <cmath>
#include <iomanip>
#include "divisor.h"
#include "multiplier.h"
#include "globals.h"

using namespace std;

enum AmortizeProgram
{
	LOAN_PRINCIPAL = 1,
	INTEREST_RATE = 2,
	YEARS_OF_LOAN = 3
};

enum AmortEnum
{
	YR_OUT = 2,
	MN_OUT = 2,
	CUM_MN_OUT = 5,
	PAYMENT_OUT = 12,
	INTEREST_OUT = 12,
	PRINCIPAL_OUT = 12,
	BALANCE_OUT = 16
};

int main(int argc, char* argv[])
{
	double principal = 0.0;
	double humanInterest = 0.0;
	int yearsOfLoan = 0.0;

	
	if (argc == 1)
	{
		/*cout << "argc: " << argc << endl;
		cout << "argv[0]: " << argv[0] << endl;

		for (int i = 0; i < argc; i++)
		{
			cout << "argv[" << i << "]: " << argv[i] << endl;
		}*/

		cout << "Enter the principal amount: ";
		cin >> principal;

		cout << "Enter the interest rate: ";
		cin >> humanInterest;

		cout << "Enter the years of loan: ";
		cin >> yearsOfLoan;
	} else {
		principal = atof(argv[LOAN_PRINCIPAL]);;
		humanInterest = atof(argv[INTEREST_RATE]);
		yearsOfLoan = atoi(argv[YEARS_OF_LOAN]);
	}

	cout << "Loan Principal: " << principal << endl;
	cout << "Interest Rate: " << humanInterest << "%" << endl;
	cout << "Time Period: " << yearsOfLoan << " years" << endl;

	double interest = divisor(humanInterest, gPercentDenominator);

	double monthInterest = divisor(interest, gMonthsInYear);
	long monthsOfLoan = multiplier(yearsOfLoan,gMonthsInYear);

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

	int year = 1;
	int switchYear = 0;
	int yearMonth = 1;


	while (currLoanMonth <= monthsOfLoan){


		gAmortizeMonth amortMonth;
		currInterestPayment = currBalance * monthInterest;

		currPrincipalPayment = payment - currInterestPayment;
		currBalance = currBalance - currPrincipalPayment;

		amortMonth.year = year;
		amortMonth.yearMonth = yearMonth;
		amortMonth.loanMonth = currLoanMonth;
		amortMonth.payment = payment;
		amortMonth.pureInterest = currInterestPayment;
		amortMonth.paidDownPrincipal = currPrincipalPayment;
		amortMonth.principalBalance = currBalance;
		
		cout <<
			setw(YR_OUT) << amortMonth.year << " " <<
			setw(MN_OUT) << amortMonth.yearMonth << " " <<
			setw(CUM_MN_OUT) << amortMonth.loanMonth << " " <<
			setw(PAYMENT_OUT) << amortMonth.payment << " " <<
			setw(INTEREST_OUT) << amortMonth.pureInterest << " " <<
			setw(PRINCIPAL_OUT) << amortMonth.paidDownPrincipal << " " <<
			setw(BALANCE_OUT) << amortMonth.principalBalance << " " <<
			endl;

		yearMonth++;
		if (yearMonth > gMonthsInYear)
		{
			yearMonth = 1;
			year++;
		}
		currLoanMonth++;
	}

	cout << "Loan complete"<< endl;
	system("pause");
	return 0;
}
