#include <iostream>
#include <vector>

using namespace std;

int mai(int argc, char* argv[])
{

	vector<int> vec;
	vec.push_back(6);
	vec.push_back(7);

	for (size_t i = 0; i < vec.size(); ++i) // size_t means long unsigned int.
	{
		cout << vec[i] << "\n";
	}

	for (int a : vec) // ':' means, "in". so its, for all values 'a' in 'vec'.
	{
		cout << a << "\n";
	}

	return 0;

}