#include <iostream>
//#define MONTHS_IN_YEAR 12

using namespace std;

int main()
{
	const int monthsInYear = 12;
	double principal = 100000.0;
	double interest = 0.05;
	int yearsOfLoan = 30;

	double monthInterest = interest / monthsInYear;
	long monthsOfLoan = yearsOfLoan * monthsInYear;

	cout << principal << " " << interest << " " <<
		yearsOfLoan << " " << monthInterest << " " <<
		monthsOfLoan << endl;

	system("pause");
	return 0;
}
