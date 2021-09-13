// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019
// ? Revision and Level Test of Procedural Programming
// ! Program 3: Find the sum of a list of numbers

#include <iostream>

using namespace std;

int main()
{
    int m, n, sum;

    cout << "Enter the starting number  => ";
    cin >> m;

    cout << "Enter the ending number  => ";
    cin >> n;
    
    if (m>n)
    {
    	for (int m; m>=n; m--)
    	{
    		sum = m+n;
    		
		}
		cout << "The sum is " <<sum<< endl;
	}
	if (m<n)
    {
    	for (int m; m<=n; m++)
    	{
    		sum = m+n;
    		
		}
		cout << "The sum is " <<sum<< endl;
	}
    

	 
   

    

    return 0;
}

