// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// ? Lab Exercise 3: Inheritance
// 15 Nov 2018

#include <iostream>
#include <string> 

using namespace std;


// The class Student and Project have been given.
// Do nothing on these classes

class Student
{
  protected:
	string name;
	string matric;

  public:
	Student(string _name = "", string _matric = "") : name(_name), matric(_matric)
	{}

	string getName() const { return name; }
	string getMatric() const { return matric; }
	void setName(string n) { matric = n; }
	void setMatric(string m) { matric = m; }

	void input()
	{
		cout << "Enter name => ";
		getline(cin, name);
		cout << "Enter matric => ";
		getline(cin, matric);
	}

	void print() const
	{
		cout << "Name  : " << name << endl;
		cout << "Matric: " << matric << endl;
	}
};

class Project
{
  protected:
	string title;
	string area;

  public:
	Project(string _title = "", string _area = "") : title(_title), area(_area)
	{}

	string getTitle() const { return title; }
	string getArea() const { return area; }

	void setTitle(string t) { title = t; }
	void setArea(string a) { area = a; }
};


class Undergraduate : public Student 
{
  protected:
	double cgpa;

  public:
	Undergraduate(string _name = "",
	              string _matric = "",
				  double _cgpa = 0.0): Student(_name, _matric), cgpa(_cgpa) 
	{}

	double getCGPA() const { return cgpa; }
	void setCGPA(double c) { cgpa = c; }

	void input()
	{
       Student::input();  
	   cout << "Enter CGPA => ";          
	   cin>>cgpa;

	}

	void print() const
	{
		 Student::print(); 
        cout << "CGPA  : " << cgpa << endl; 

	}
};


// Task 4: Complete the implementation of the class Postgraduate

class Postgraduate:public Student
{ 
	protected: 
	Project p;

  public:
	Postgraduate(string _name = "",
	              string _matric = "",
				  string prjTitle = "",
				  string prjArea = "")
	
  {}
  	string getProjectTitle() const
	{ 
	    string prj=p.getTitle();
        return prj;
	}


	string getProjectArea() const
	{
      string prj=p.getArea(); 
	  return prj;
	}

	void setProject(string _title, string _area)
	{ 
		p.setTitle( _title); 
		p.setArea(_area); 

       
	}

	void input()
	{ 
	    string t ,w;
		Student::input();  
         cout<<"Enter the project title=>";
         getline(cin,t);
		 cout<<"Enter the project area=>";
         getline(cin,w);
         setProject(t,w);
	} 

	void print() const
	{ 
		Student::print();  
        cout<<"title:"<<p.getTitle()<<endl; 
		cout<<"project:"<<p.getArea()<<endl;
	}

};

int menu()
{
	cout << "=============[ Menu ]=============" << endl;
	cout << "1. Add an undergraduate student" << endl;
	cout << "2. Add a postgraduate student" << endl;
	cout << "3. Display all students" << endl;
	cout << "9. Exit" << endl;
	cout << endl;
	cout << "Choose an operation [1,2,3 or 9] => ";

	int choice;
	cin >> choice;
	cin.ignore();
	return choice;
}

//-------------------------------------------------------
// The main function
//-------------------------------------------------------

int main()
{    


	// Task 5: Create two arrays to hold lists of undergraduate and postgraduate students, respectively.
	//        Tips: You also need to declare variables to hold the number of undergraduate and postgraduate
	//        students, respectively.
    
    Undergraduate us[10]; 
	Postgraduate ps[10]; 
	int x=0; 
	int y=0;
	int c = menu();

	while (c != 9)
	{
		switch (c)
		{
		case 1: 
		        
		    // Task 6: Read data for an undergraduate student and add it to the relevant array.
			 cout << endl << "The list of undergraduate students: " << endl << endl;
               us[x].input(); 
			   x++;  
			break;

		case 2:
			// Task 7: Read data for a postgraduate student and add it to the relevant array.
			cout << "adding a postgraduate student:" << endl << endl;
               ps[y].input(); 
			   y++;
			break;

		case 3:
			// Task 8: Diplay the list of undergraduate and postgraduate students.
             
			cout << endl << "The list of undergraduate students:" << endl << endl; 
			for(int x=0;x<10;x++){
			
             us[x].print(); 
			} 

			cout << endl << "The list of postgraduate students:" << endl << endl; 
			for(int y=0;y<10;y++) 
			{
			
               ps[y].print(); 
		    }

			break;
		}

		c = menu();
	}

	system("pause");
	return 0;
}

