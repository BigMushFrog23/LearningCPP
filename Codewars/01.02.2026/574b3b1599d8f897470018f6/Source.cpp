#include <iostream>

/*Americans are odd people: in their buildings, the first floor is actually the ground floor and there is no 13th floor (due to superstition).

Write a function that given a floor in the american system returns the floor in the european system.

With the 1st floor being replaced by the ground floor and the 13th floor being removed, the numbers move down to take their place. In case of above 13, they move down by two because there are two omitted numbers below them.

Basements (negatives) stay the same as the universal level.

Examples:

1  =>  0
0  =>  0
5  =>  4
15  =>  13
-3  =>  -3
2>1
3>2
12>11
14>12
15>13

*/

int getRealFloor(int f) {

	if (f < 0)
	{
		return f;
	}

	else if (f == 0 || f == 1)
	{
		return 0;
	}

	else if (f >= 14)
	{
		return f - 2;
	}

	else
	{
		return f - 1;
	}

	return 0;
}

int main()
{
	std::cout <<  1	<< " -> " << getRealFloor(1) << "\n";
	std::cout << 0 << " -> " << getRealFloor(0) << "\n";
	std::cout <<  5	<< " -> " << getRealFloor(5) << "\n";
	std::cout << 15 << " -> " << getRealFloor(15) << "\n";
	std::cout << -3 << " -> " << getRealFloor(-3) << "\n";

	return 0;
}