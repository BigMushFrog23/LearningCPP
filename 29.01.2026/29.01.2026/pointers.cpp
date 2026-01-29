#include <iostream>

using namespace std;

void pp(int& i)
{
	cout << &i << " " << i << " " << sizeof(i) << "\n";
}

int main(int argc, char* argv[])
{

	int	  a	= 10;
	int	  b	= 25;
	int* pA = &a;
	int* pB = &b;

	//*(&a) = 17; // Same thing
	*pA = 17; // Same thing
	*(pB - 1) = 15;

	pp(a);
	pp(b);
	pp(*pA);

	/*
	
	int arr[10] = {};

	for (size_t i = 0; i < 10; i++)
	{
		pp(arr[i]);
	}
	*/

	return 0;
}