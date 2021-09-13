////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 1, 2017/2018
// Skill-based Test 1
// October 12, 2017
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>

using namespace std;

// Task 1: Complete the definition of class Date.
class Date 
{
	private: 
			
	
	public:	
	
	


		friend ostream & operator<< (ostream &, const Date &);	
		friend istream & operator>> (istream &, Date &);
};


// Task 1(e): The following function is partialy given. 
//              Complete the code of the operator >>.

istream & operator>> (istream &inp, Date &obj) 
{
	cout << "Enter your date (day, month, year): ";


			
	return inp; 
}	

// Task 1(f): The following function is partialy given. 
//              Complete the code of the operator <<
ostream & operator<< (ostream &out, const Date &obj) 
{

			
	return out; 
}




// Task 2: The following function is partialy given. 
//           Complete the code of the function displayDiff.

void displayDiff(Date d) 
{
	cout << "The difference: ";

}

int main()
{
	// Task 3:  
	
	
	
	
	// Task 4: 
	
	
	
	
	// Task 5: 
	
	
	
	
	
	// Task 6: 

		
		
		
	return 0;
}
