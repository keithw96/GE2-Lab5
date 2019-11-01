#include "Production.h"
#include <vector>
#include <iostream>
#include <time.h>

int main()
{
	//random seed
	srand(time(NULL));
	
	Production p;
	int num;
	int countInput = 0;
	int numMatches = 0;
	std::vector<int> input;
	std::vector<int> lotteryNumbers;

	//Get Player Input
	std::cout << "Please enter six unique numbers between 0 and 46" << std::endl;
	while ((std::cin >> num) && countInput < 6)
	{
		input.push_back(num);
		countInput++;
	}

	//Check Player Input
	//Check if enough numbers entered
	if (p.arraySize(input) == false)
	{
		input.clear();

		std::cout << "Too many or too few numbers. please re-enter your 6 unique numbers between 0 and 46" << std::endl;
		while ((std::cin >> num) && countInput < 5)
		{
			input.push_back(num);
			countInput++;
		}
	}

	//Check for duplicates
	if (p.duplicates(input) == false)
	{
		input.clear();
		std::cout << "Duplicated Detected. please re-enter your 6 unique numbers between 0 and 46" << std::endl;
		while ((std::cin >> num) && countInput < 5)
		{
			input.push_back(num);
			countInput++;
		}
	}

	//Check that numbers are between 0 and 46
	if (p.range(input) == false)
	{
		input.clear();
		std::cout << "Numbers outside of range detected. please re-enter your 6 unique numbers between 0 and 46" << std::endl;
		while ((std::cin >> num) && countInput < 5)
		{
			input.push_back(num);
			countInput++;
		}
	}


	std::cout << "Lottery Numbers: ";

	//make lottery numbers
	for (int i = 0; i < 6; i++)
	{
		int random = rand() % 46 + 1;
		lotteryNumbers.push_back(random);

		while (p.duplicates(lotteryNumbers) == false)
		{
			lotteryNumbers.pop_back();
			random = rand() % 46 + 1;
			lotteryNumbers.push_back(random);
			
		}
		std::cout << lotteryNumbers[i] << ", ";
	}
	std::cout << std::endl;

	//Get amount of Matches
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < lotteryNumbers.size(); j++)
		{
			if (input[i] == lotteryNumbers[j])
			{
				numMatches++;
			}
		}
	}

	//Output number of matches
	std::cout << numMatches << " matches!" << std::endl;
	system("PAUSE");
	return 0;
}
