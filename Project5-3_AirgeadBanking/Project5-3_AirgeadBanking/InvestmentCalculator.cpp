#include <iostream>
#include <iomanip>
#include "InvestmentCalculator.h"
#include <conio.h> //to use _getch()

//Initialize variables
InvestmentCalculator::InvestmentCalculator() {
	initialInvestment = 0.0;
	monthlyDeposit = 0.0;
	annualInterestRate = 0.0;
	numYears = 0;

}
//initialize class variables with provided values
InvestmentCalculator::InvestmentCalculator(double initialInvestment, double monthlyDeposit, double annualInterestRate, int numYears) {
	this->initialInvestment = initialInvestment;
	this->monthlyDeposit = monthlyDeposit;
	this->annualInterestRate = annualInterestRate;
	this->numYears = numYears;
}
//Promps to get user inputs
void InvestmentCalculator::getUserInput() {
    //start a while loop to make sure only numbers are input
    while (true) {
        // Prompt for inputs
        std::cout << "************************************************************************************************" << std::endl;
        std::cout << "Enter Initial Investment Amount: $";
        //Checks if input is a valid number
        if (!(std::cin >> initialInvestment)) {
            std::cerr << "Invalid input. Please enter a valid number for Initial Investment." << std::endl;
            //clears invalid input and go back to beginning of loop
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Enter Monthly Deposit: $";
        if (!(std::cin >> monthlyDeposit)) {
            std::cerr << "Invalid input. Please enter a valid number for Monthly Deposit." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Enter Annual Interest Rate (compounded): %";
        if (!(std::cin >> annualInterestRate)) {
            std::cerr << "Invalid input. Please enter a valid number for Annual Interest Rate." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Enter Number of Years: ";
        if (!(std::cin >> numYears)) {
            std::cerr << "Invalid input. Please enter a valid number for Number of Years." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        // Checks to make sure all values are positive
        if (initialInvestment < 0 || monthlyDeposit < 0 || annualInterestRate < 0 || numYears <= 0) {
            std::cerr << "Invalid input. Only positive numbers are allowed." << std::endl;
            continue;
        }
        //Press any key to calculate and display table
        std::cout << "Press any key to continue..." << std::endl;
        //wait for any keypress and store it in 'int key' to safely acknowledge and ignore it
        int key = _getch();

        // If all inputs are valid, break out of the loop
        break;
    }
}

    //Table WITH monthly deposits***======================================================================================================
void InvestmentCalculator::calculateReportWithDeposits() {
    //Initialize variables for data
    double openingAmount = initialInvestment; //Starting amount for each month
    double closingBalance = initialInvestment;//Ending amount for each month
    double totalDeposited = 0.0;              //Amount deposited over time  
    double totalInterestEarned = 0.0;         //interest over time

    int columnWidth = 15; //Width to help format columns
    std::cout << "************************************************************************************************" << std::endl;

    std::cout << "________________________________________________________________________________________________" << std::endl;
    std::cout << "|--------------------------Table WITH Monthly Deposits-----------------------------------------|" << std::endl;
    //Seperator line
    std::cout << "|==============================================================================================|" << std::endl;
    // Print the header row with Headers and "|" separators
    std::cout << std::left << std::setw(columnWidth) << "| Month" << std::setw(columnWidth) << "| Opening Amount" << std::setw(columnWidth) << "| Total Deposited"
        << std::setw(columnWidth) << "| Total" << std::setw(columnWidth) << "| Interest" << std::setw(columnWidth) << "| Closing Balance" << "|" << std::endl;

    // Print a separator row with separators
    std::cout << std::left << std::setw(columnWidth) << "|--------------" << std::setw(columnWidth) << "|---------------" << std::setw(columnWidth) << "|----------------"
        << std::setw(columnWidth) << "|--------------" << std::setw(columnWidth) << "|--------------" << std::setw(columnWidth) << "|----------------" << "|" << std::endl;

    //keeps track of months
    int monthCounter = 0;
    //Loop over the input number of years
    for (int year = 1; year <= numYears; ++year) {
        //for each year loop 12 months
        for (int month = 1; month <= 12; month++) {
            //Increment month
            ++monthCounter;
            //Formula to calculate interest earned in current period
            double interest = (closingBalance + totalDeposited) * (annualInterestRate / 100.0 / 12.0);
            //Update closing balance by adding deposit and interest
            closingBalance += monthlyDeposit + interest;
            //Update totals for amount deposited and interest earned
            totalDeposited += monthlyDeposit;
            totalInterestEarned += interest;

            //Set the output format to only display 2 decimal places
            std::cout << std::fixed << std::setprecision(2);

            /*Output financial data for current period with spacers.
            This took me so long to get perfect I hope it works!*/
            std::cout << std::left << "|" << std::setw(columnWidth - 1) << monthCounter << "|" << std::setw(columnWidth) << openingAmount << "|"
                << std::setw(columnWidth + 1) << totalDeposited << "|" << std::setw(columnWidth - 1) << (totalDeposited + openingAmount) << "|" << std::setw(columnWidth - 1)
                << interest << "|" << std::setw(columnWidth + 1) << closingBalance << "|" << std::endl;
            //Update opening amount for next month
            openingAmount = closingBalance;

        }
    }
    //final separator
    std::cout << "|==============================================================================================|" << std::endl;
    std::cout << "************************************************************************************************" << std::endl;
}
//Table WITHOUT monthly deposits***======================================================================================================================================
//same as above method except less calculations
void InvestmentCalculator::calculateReportWithoutDeposits(){
    double openingAmount = initialInvestment; //Starting amount for each month
    double closingBalance = initialInvestment;//Ending amount for each month
    double totalDeposited = 0.0;              //Amount deposited over time  
    double totalInterestEarned = 0.0;         //interest over time
    int columnWidth = 15; //Width to help format columns


    std::cout << "________________________________________________________________" << std::endl;
    std::cout << "|----------------Table WITHOUT Monthly Deposits----------------|" << std::endl;
    //Seperator line
    std::cout << "|==============================================================|" << std::endl;
    //reinitialize variables for new table
    openingAmount = initialInvestment;
    closingBalance = initialInvestment;
    totalDeposited = 0.0;
    totalInterestEarned = 0.0;

  // Print the header row with Headers and "|" separators
    std::cout << std::left << std::setw(columnWidth) << "| Month" << std::setw(columnWidth) << "| Opening Amount"
         << std::setw(columnWidth) << "| Interest" << std::setw(columnWidth) << "| Closing Balance" << "|" << std::endl;

    // Print a separator row with separators
    std::cout << std::left << std::setw(columnWidth) << "|--------------" << std::setw(columnWidth) << "|---------------"
        << std::setw(columnWidth) << "|--------------" << std::setw(columnWidth) << "|----------------" << "|" << std::endl;

    //keeps track of months
    int monthCounter = 0;
    //Loop over the input number of years
    for (int year = 1; year <= numYears; ++year) {
        //for each year loop 12 months
        for (int month = 1; month <= 12; month++) {
            //Increment month
            ++monthCounter;
            //Formula to calculate interest earned in current period
            double interest = closingBalance * (annualInterestRate / 100.0 / 12.0);
            //Update closing balance by adding deposit and interest
            closingBalance += interest;
            totalInterestEarned += interest;

            //Set the output format to only display 2 decimal places
            std::cout << std::fixed << std::setprecision(2);

            /*Output financial data for current period with spacers.
            This took me so long to get perfect I hope it works!*/
            std::cout << std::left << "|" << std::setw(columnWidth - 1) << monthCounter << "|" << std::setw(columnWidth) << openingAmount <<  "|" << std::setw(columnWidth - 1)
                << interest << "|" << std::setw(columnWidth + 1) << closingBalance << "|" << std::endl;
            //Update opening amount for next month
            openingAmount = closingBalance;

        }
    }
    //final separator
    std::cout << "|==============================================================|" << std::endl;
    std::cout << "************************************************************************************************" << std::endl;
	
}