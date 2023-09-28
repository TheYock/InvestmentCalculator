/*
			9/27/23
			CS210
			Project 5-3_Investment_Calculator
			By George Yockachonis*/

#include <iostream>
#include "InvestmentCalculator.h"
#include <limits>

int main() {
	//Create an instance of the 'InvestmentCalculator' class
	InvestmentCalculator calculator;
	//Welcome Message
	std::cout << "************************************************************************************************" << std::endl;
	std::cout << "Welcome to the Investment Calculator!" << std::endl;

	//Enter an infinite loop to continue to allow calculations until stopped
	while (true) {
		//Get user input for variables
		calculator.getUserInput();
		//Calculate and output report
		calculator.calculateReportWithDeposits();
		calculator.calculateReportWithoutDeposits();

		//variables for next loop
		char choice;
		bool validChoice = false;
		//loop to make sure a valid choice is made to continue or end
		while (!validChoice) {
			//prompt and user input
			std::cout << "Do you want to try a new input?(Y/N)";
			std::cin >> choice;
			//check for valid inputs
			if (std::cin.fail() || (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')) {
				std::cerr << "Invalid input. Please enter 'Y' or 'N'." << std::endl;
				//clears invalid inputs
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else {
				//if Y/y/N/n is chosen then it is a valid choice
					validChoice = true;
			}
		}
		//if choice is not Y/y(in other words if N/n is input) then break loop
		if (choice != 'Y' && choice != 'y') {
			break;
		}
	}
	//Goodbye message
	std::cout << "************************************************************************************************" << std::endl;
	std::cout << "Thank you for using the Investment Calculator!" << std::endl;
	std::cout << "************************************************************************************************" << std::endl;
	return 0;

}

//Fly High Cale\\