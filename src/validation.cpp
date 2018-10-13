#include "validation.h"
#include <iostream>

/* Get input from std::cin and check if the input is a valid number or not */
int getValidNumber()
{
	int result = 0;
	std::string input;
	int i = 0;
	size_t sz = 0;
	bool valid = true;

	do {
		std::getline(std::cin, input, '\n');
		try {
			/* modify @sz to be the number of character are converted successfully */
			result = std::stoi(input, &sz);

			/* Handling cases that numbers are trailing in a string */
			/* Example: 1a, 123.34, 123abc */
			if (sz == input.size()) 
				valid = true;
			else
				throw std::runtime_error("Invalid input. Please enter a number");
		} catch (const std::exception& e) {
			std::cout << "Invalid input. Please enter a number: ";
			valid = false;
		}
	} while (!valid);

	return result;
}

/* Check if user's input is in a specified range */
bool isInRange(int number, int min, int max) 
{
	if (number < min || number > max) 
		return false;
	else 
		return true;
}