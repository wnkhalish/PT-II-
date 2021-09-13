//------------------------------------------------------------------------------
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 2, 2017/2018
// Revision Tutorial
//
// program1.cpp
//------------------------------------------------------------------------------

#include<iostream>
using namespace std;

// The code for the class Contact and Project are given.
//-------------------------------------------------------

class Contact{
	protected:
		string phone;
		string email;

	public:
		Contact(string p="", string e="") : phone(p), email(e) {}
		string getEmail() const {return email;}
		string getPhone() const {return phone;}
		//string setEmail() const {return email;}
};

class Project{
	protected:
		string title;
		string area;

	public:
		Project(string t="", string a="") : title(t), area(a){}
		string getTitle() const {return title;}
		void setTitle(string t) {title = t;}
};
//-------------------------------------------------------

class Person{
	protected:
		string name;
		Contact c;

	public:
		Person(string n="", string p="", string e=""): name(n), c(p,e) // n: name, p:phone, e:email
		{
			//c.setPhone(p);
			//c.setEmail(e);
		}

		string getName() const {return name;}
		void setName(string n) { name =n; }

		Contact getContact() const { return c; }
		string getPhone() const { return c.getPhone(); }
		string getEmail() const { return c.getEmail(); }
};

class Advisor: public Person{
	protected:
	string position;
	Contact c;

	public:
		Advisor(string pos="", string n="", string p="", string e="") : position(pos), Person(n,p,e) // pos: position, e.g. "Lecturer" , "Technician"
		{}

		string getPosition() const { return position; }
		void setPosition(string pos) { position = pos; }
		
};

class Student: public Person{
	protected:
 	string program;
	Project project;
	Advisor *advisor;

	public:
		Student(string prog="", string n="", string p="", string e="", string pn = "", string pa = ""): program(prog), Person(n,p,e), project(pn,pa), advisor(NULL)  // prog: program, e.g., "SCSJ", "SCSR", etc.
		{}
		
		string getProgram() const { return program; }
		void setProgram(string prog) { program = prog; }


		void setProject(Project p)
		{
			project =p;
		}

		void setAdvisor(Advisor *a)
		{
 			advisor = a;
		}

		string getEmailAddress() const
		{ return c.getEmail(); }

		string getProjectTitle() const
		{}

		string getAdvisorName() const
		{ 
			if (advisor!=NULL)
			return advisor->getName();
			return "";  }
};

int main()
{
  // Do nothing on the main function
  system ("pause");
  return 0;
}

