////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 2, 2017/2018
// Skill-based Test 2
// 22 April 2018
// Solution
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

// Task 1: (6 marks)
// The definition of class Project is PARTIALLY given.
// Complete this class according to the diagram.

class Project{
	private:
		string title;          
		Lecturer *supervisor;  // 1m  // T1a1
	public:
		Project(){
			title="";           
			supervisor = NULL;  //1m  // T1a2
		}
		
		string getTitle() const { return title;}
		void setTitle(string t){ title=t;}
		
		// Define the method getSupervisor here  
		Lecturer* getSupervisor() const { // 1m   // T1b1
			return supervisor;            // 1m   // T1b2
		}
		
		// Define the method setSupervisor here 
		void setSupervisor(Lecturer* sv){ // 1m  // T1c1
			supervisor = sv;              // 1m  // T1c2
		}
};

// Task 2: (12 marks)
// The definition of class Student is PARTIALLY given.
// Complete this class according to the diagram.

class Student{
	private:
		string name;      
		Project project;  // 1m   // T2?
	public:
		Student(){ setName("");}
		void setName(string n) { name=n; }
		
		void setProject(string t) {  // t is project's title
			project.setTitle(t);     // 1m  // T2a
		}

		void assignSupervisor(Lecturer* sv){  // 1m  // T2b1
			project.setSupervisor(sv);        // 2m  // T2b2
		}
		
		// The method print is PARTIALLY given
		void print() const{
			cout << "Student    : " << name << endl;                 // 1m  // T2c1
			cout << "Project    : " << project.getTitle() << endl;   // 2m  // T2c2
			
			Lecturer *sv = project.getSupervisor();                  // 1m  // T2c3
						
			if (sv)                                                  // 1m  // T2c4
				cout << "Supervisor : " << sv->getName() << endl;    // 2m  // T2c5
				
			cout << endl;
		}
};

int main()
{
	// Lecturer objects. There are only two lecturers. First lecturer = lect1, Second lecturer = lect2
	Lecturer lect1("Dr. Ali Bakar");                  
	Lecturer lect2("Prof. Dr. Abu Samah Abdullah");   
	
	Student studs[10];   // To hold the list of students
	int nStud = 0; // Number of students.  Initially, there is no student.

	// Task 3: (4 marks)
	// Read the list of students from an input file and store them into the array.
	// The main part for reading from the file is already given.
	// Complete the blank line(s)
	
	string fileName ="student_list1.txt";   // Change the file name to test with another file
	fstream fin; 
	string sname;      // Student's name
	string ptitle;     // Project's title
	
	fin.open(fileName.c_str(), ios::in);
	
	while ( getline(fin, sname,',' )){
		getline(fin, ptitle);
		
		studs[nStud].setName(sname);      // 2m  // T3a
		studs[nStud].setProject(ptitle);  // 2m  // T3b

		nStud++;
	}
	
	fin.close();
	
	// Task 4: (5 marks)
	// Assign supervisors

	studs[0].assignSupervisor(&lect1);        // 1.5m  // T4a
	studs[1].assignSupervisor(&lect1);        // 1.5m  // T4b
	studs[nStud-1].assignSupervisor(&lect2);  // 2m    // T4c 
	
	// Task 5: (3 marks)
	// Print the students

	for (int i=0; i<nStud; i++)  // 1m  // T5a
		studs[i].print();        // 2m  // T5b
		
	return 0;
}


