#include "Production.h"

/// <summary>
/// Checks that each number is between 0 and 46
/// Returns true or false 
/// </summary>
/// <param name="v"></param>
/// <returns></returns>
bool Production::range(std::vector<int> v)
{
	if (v.size() == 0)
	{
		return false;
	}

	bool inRange = true;

	for (auto number : v)
	{
		if (number < 1 || number > 45)
		{
			inRange = false;
		}
	}
	return inRange;
}

/// <summary>
/// Sorts the passed vector and scanns for duplicates
/// </summary>
/// <param name="v"></param>
/// <returns></returns>
bool Production::duplicates(std::vector<int> v)
{	
	std::sort(v.begin(), v.end());
	auto last = std::unique(v.begin(), v.end());
	bool isUnique = (last == v.end());
	return isUnique;
}

/// <summary>
/// Checks that there are 6 numbers
/// </summary>
/// <param name="v"></param>
/// <returns></returns>
bool Production::arraySize(std::vector<int> v)
{
	bool size = true;

	if (v.size() != 6)
	{
		size = false;
	}

	return size;
}