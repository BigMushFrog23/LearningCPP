#include <iostream>
#include <vector>

using namespace std;

class Student
{

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

	void print() const
	{
		for (const auto& s : m_students)
		{
			s.print();
		}
	}

};

int main(int argc, char *argv[])
{

	Student s1;
	Student s2("Jeremy", "Popov", 1, 3.14f); // If it's a float, I gotta add 'f' at the end to precise its a float, otherwise it's a double.
	Student s3("BigMushFrog23", "UMR", 2, 3.15f);

	Course comp4300("COMP 4300");
	comp4300.addStudent(s1);
	comp4300.addStudent(s2);
	comp4300.addStudent(s3);
	comp4300.addStudent(Student("New", "Student", 3, 4));

	comp4300.print();

	return 0;

}