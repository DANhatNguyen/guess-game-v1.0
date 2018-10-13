#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
// #include <cstdlib>
/* 
* Helper functions
*/
/* Get input from std::cin and check if the input is a valid number or not */
int getValidNumber();

/* Check if user's input is in a specified range */
bool isInRange(int number, int min, int max);

#endif