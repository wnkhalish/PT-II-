#include<iostream>
#include<string>
#include<cstdlib>
#include<cctype>

using namespace std;

string getMonthName(int month)
{
	if (iMonth==1) return "Jan";
	else if (iMonth==2) return "Feb";
	return "Dec";
}

int main()
{
	string name;
	string id;
	
	// Task 1: Allow user to enter his or her full name and id number
	cout << "Enter your full name => ";
	name = "Siti Aminah Abdul Karim";
	
//	getline(cin, name);
	

	cout << "Enter your ID Number => ";
	id ="990220011234";
//	cin >> id;

	cout << endl << endl;
	// Task 2: To determine the gender from the last digit
	// Task 2a: Extract the last digit from the id
	string gender = id.substr(11, 1);

	// Task 2b: Convert the last digit to a number
	int iGender = atoi(gender.c_str());
	
	
	// Task 2c: Determine the gender such that, an odd value is male and even is female
	string genderType;
	
	genderType = (iGender % 2) ? "Male" : "Female";
	
	
//	if ( (iGender % 2)==1) {
//		genderType = "Male";
//	}
//	else{
//		genderType = "Female";
//	}	
	//________________________
	
	
	// Task 3: To extract the dob
	// Task 3a: Extract the year, month and day from the id

	string sYear  = id.substr(0,2);
	string sMonth = id.substr(2,2);
	string sDay = id.substr(4,2);
	
	// Task 3b: Convert the year, month and day to integers
	int iYear = atoi(sYear.c_str());
	int iMonth = atoi(sMonth.c_str());
	int iDay = atoi(sDay.c_str());
	
	// Task 3c: Convert the year to be in full value form, e.g. 99 becomes 1999 and 02 becomes 2002
	iYear = (iYear < 19) ? 2000 + iYear : 1900 + iYear;
	
//	sYear = (iYear < 19) ? "20" + sYear : "19" + sYear;
	
	//________________________

	
	// Task 4: Calculate the age
	int age = 2018 - iYear;
	//________________________

	
	// Task 5: Determine the string name for the month
	// Refactor:

	const string MONTHS={"Jan","Feb"};
	month = MONTHS[iMonth-1];
	
//	month = getMonthName(iMonth);
	


	// Task 6: Using a loop, convert the name to capital letters
	//________________________
	
	for (int i=0; i<name.length(); i++)
		name[i] = toupper(name[i]);


	cout << endl << endl;
	
	// Task 7: print all the required output
	cout << "Output: " << endl << endl;
	cout << "Name    : " << name << endl;
	cout << "ID      : " << id << endl;
	cout << "Gender  : " << gender << endl;
	cout << "Age     : " << " years old" << endl;
	cout << "DOB     : " << endl << endl;

//	system("pause"); //! remove this line if you are using Dev C++

    return 0;
}

