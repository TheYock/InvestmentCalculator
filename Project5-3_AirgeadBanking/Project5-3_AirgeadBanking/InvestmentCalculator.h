#ifndef INVESTMENTCALCULATOR_H
#define INVESTMENTCALCULATOR_H

class InvestmentCalculator {
private:
	//variables
	double initialInvestment;
	double monthlyDeposit;
	double annualInterestRate;
	int numYears;

public:
	//constructors
	InvestmentCalculator();
	InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterestRate, int numYears);

	//Methods
	void getUserInput();
	void calculateReportWithDeposits();
	void calculateReportWithoutDeposits();
	void compareReports();
};



#endif
