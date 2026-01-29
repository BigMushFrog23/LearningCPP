#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Student
{

	// Anything written before "public:" will be private by default.

	string	m_firstName	= "First";
	string	m_lastName	= "Last";
	int		m_id		= 0;
	float	m_average	= 0.0;

public:

	// Default Constructor for the Student class 
	Student() {}

	// Constructor for the Student class
	Student(const string& firstName, const string& lastName, const int id, const float average)
		// This will assign the values to the default values
		: m_firstName	(firstName)
		, m_lastName	(lastName)
		, m_id			(id)
		, m_average		(average)
	{
	}
	
	// We assign const to all function that don't modify the values.

	float getAvg() const
	{
		return m_average;
	}

	int getId() const
	{
		return m_id;
	}

	string getFirst() const
	{
		return m_firstName;
	}

	string getLast() const
	{
		return m_lastName;
	}

	void print() const
	{
		cout << getFirst() << " " << getLast() << " " << getId() << " " << getAvg() << "\n";
	}

};

class Course
{
	string m_name = "Course";
	vector<Student> m_students;

public: 

	Course() {} // Default constructor

	Course(const string& name) // Constructor
		: m_name(name)
	{
	}

	void addStudent(const Student& s) // We don't wanna copy the student, so we will do a reference. Not const because we are modifying the vector m_students by adding something.
	{
		m_students.push_back(s); // Adds student 's' to the m_students vector
	}

	// const at the start means we cannot modify what vector<Student>& will return
	// const at the end means we cannot modify the values given by getStudents()
	// we pass the reference of the vector, so we don't copy the whole thing
	const vector<Student>& getStudents() const
	{
		return m_students;
	}

	void loadFromFile(const string& fileName)
	{
		ifstream fin(fileName); //ifstream means Input File Stream, fin is the name of the the variable (acronym for File In), then we put the argument being the file.
		string first, last;
		int id;
		float average;

		// Error to check if we managed to open the file / find it.
		if (!fin.is_open())
		{
			cerr << "Error: Could not open file " << fileName << endl;
			return;
		}

		// If we use ">>", it means we are putting the current value/token of fin into temp
		// "<<" means we are putting the value of a variable into the cout, which prints it.
		// It basically means, get the next token seperated by whitespace or a new line.
		while (fin >> first)
		{
			fin >> last >> id >> average; // While we still find first names, we input the tokens one by one into their variables (first, last, id, average).
										  // Since every student in the file is FirstName -> LastName -> ID -> Average, we always get all the values of one student at a time.
										  // And we also loop so we do the first values, then go to the next available one after the student is done.

			addStudent(Student(first, last, id, average));

		}
	}

	// Here we make a print function to print out the entire student information at once.
	void print() const
	{
		// auto will automatically assign the data type of the value inputed into it, since we never modify its value we will do a const, and since its an object, we pass a reference.
		for (const auto& s : m_students)
		{
			s.print();
		}
	}

};

int main(int argc, char *argv[])
{

	Course c("COMP 4300");
	c.loadFromFile("StudentList.txt"); // We parse in the information from the txt file
	c.print();

	/*
	Student s1;
	Student s2("Jeremy", "Popov", 1, 3.14f); // If it's a float, I gotta add 'f' at the end to precise its a float, otherwise it's a double.
	Student s3("BigMushFrog23", "UMR", 2, 3.15f);

	Course comp4300("COMP 4300");
	comp4300.addStudent(s1);
	comp4300.addStudent(s2);
	comp4300.addStudent(s3);
	comp4300.addStudent(Student("New", "Student", 3, 4));

	comp4300.print();
	*/

	return 0;

}