#include <iostream>

using namespace std;

void pp(int& i)
{
	cout << &i << " " << i << " " << sizeof(i) << "\n";
}

template <class T> // or <typename T>
// instead of doing "IntArray, FloatArray, etc etc... I can do DynamicArray
// and in the main call DynamicArray<*type*> name(size)
class DynamicArray
{
	size_t  m_size;
	T* m_arr;

public:

	DynamicArray(size_t size)
		: m_size(size)
		, m_arr(new T[size]())
	{
		cout << "Array Constructor\n";
	}

	~DynamicArray()
	{
		delete[] m_arr;
		cout << "Array Destructor" << "\n";
	}

	T get(size_t index) const
	{
		return m_arr[index];
	}

	void set(size_t index, T val)
	{
		m_arr[index] = val;
	}

	void print() const
	{
		for (size_t i = 0; i < m_size; i++)
		{
			cout << i << " " << m_arr[i] << "\n";
		}
		cout << "\n\n";
	}

	// operator overloading
	// const "function and stuff", means it will return a const
	// "function and stuff" const, means the value inside the argument won't be modified. 
	const T& operator [](size_t index) const // Make sure to say its const, if the array is const.
	{
		return m_arr[index];
	}

	// We need to create a duplicate NON CONST, to call it on non const arrays too.
	// It will use the const or non const version, depending on what we use (const array or normal array)
	T& operator [](size_t index)
	{
		return m_arr[index];
	}

};

int main(int argc, char* argv[])
{
	DynamicArray<int> myArray(10);
	DynamicArray<float> myFloatArray(5);


	myFloatArray.set(2, 5.34);

	// with the operator overloading, instead of .set, i can do myArray[index] = value;
	myFloatArray[3] = 3.14159;
	myFloatArray[0] = 2.45;

	myArray[1] = 68;
	myArray.set(4, 7);
	myArray.set(2, 134);

	myArray.print();
	myFloatArray.print();

	return 0;
}