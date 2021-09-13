////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 2, 2017/2018
// Skill-based Test 2
// 22 April 2018
// 
// Template File 
// sbt2.cpp
//
// Use this file as the basis to answer this test
////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<fstream>

using namespace std;

// The definition of class Lecturer is FULLY given.
// Do nothing on this class.

class Lecturer{
	private:
		string name;		
	public:
		Lecturer(string n=""){name=n;}
		string getName() const{ return name;}
};

// Task 1:  Complete the definition of class Project

class Project{
	private:
		string title;          
	public:
		Project()
		{
		  title = "";
		  //_____________________
		}
		
		string getTitle() const { return title;}  
		void setTitle(string t){ title=t;}        

		// Define the method getSupervisor here
		//_____________________
		
		
		// Define the method setSupervisor here
		//_____________________
};

// Task 2: Complete the definition of class Student

class Student{
	private:
		string name;      
	public:
		Student(){ setName("");}
		void setName(string n) { name=n; }

		void setProject(string t)  // t is project's title
		{
		  //___________________________
		}

		
		// Define the method assignSupervisor here
		//_____________________

		
		
		// The method print is PARTIALLY given
		void print() const{
			cout << "Student    : " << endl;
			cout << "Project    : " << endl;   
			cout << "Supervisor : " << endl; 
			cout << endl;
		}
};

int main()
{
	Lecturer lect1("Dr. Ali Bakar");                 // First lecturer        
	Lecturer lect2("Prof. Dr. Abu Samah Abdullah");  // Second lecturer 
	
	Student studs[10];  // To hold the list of students
	int nStud;          // Number of students.

	// Task 3: Read a list of students from a file. Complete the blank line(s)
		
	string fileName ="student_list1.txt";   // Change the file name to test with another file
	fstream fin; 
	string sname, ptitle;     // student's name and project's title read from the file
		
	fin.open(fileName.c_str(), ios::in);
	
	nStud = 0;
	while ( getline(fin, sname,',' )){
		getline(fin, ptitle);
		
		//__________________________

		nStud++;
	}
	
	fin.close();
	
	// Task 4:
	// Assign supervisors
	//__________________________
		
	
	// Task 5:
	// Print the students
	//__________________________
		
	return 0;
}
