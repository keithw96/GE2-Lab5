#include <iostream>
#include <assert.h>

#include "../ProductionProject/Production.h"

using namespace std;

int main()
{
	Production p;

	std::vector<int> validInput = { 1,2,3,4,5,6 };
	std::vector<int> invalidInput = { 2,5,4,2,1,'a', 7};
	std::vector<int> invalidEmptyImput = {};
	std::vector<int> invalidRangeInput = { 1 };
	
	//enough numbers tests
	assert(p.arraySize(validInput));
	assert(!p.arraySize(invalidInput));
	assert(!p.arraySize(invalidEmptyImput));

	//duplicate numbers tests
	assert(p.duplicates(validInput));
	assert(!p.duplicates(invalidInput));
	assert(p.duplicates(invalidEmptyImput));
	assert(p.duplicates(invalidRangeInput));

	//number range check
	assert(p.range(validInput));
	assert(!p.range(invalidInput));
	assert(!p.range(invalidEmptyImput));

	std::cout << "All Tests Passed" << std::endl;

	system("Pause");
}