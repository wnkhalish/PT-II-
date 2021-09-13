// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019
// ? Revision and Level Test of Procedural Programming
// ! Program 3: Find the sum of a list of numbers

#include <iostream>

using namespace std;

int main()
{
    int m, n;
    int sum=0;

    cout<< "Enter the starting number  => ";
    cin >> m;

    cout<< "Enter the ending number  => ";
    cin >> n;

    int i=m;

    while(i<=n)
    {
        sum=i+sum;
        i=i+1;
    };

     int j=m;
    while(j>=n)
    {
        sum=j+sum;
        j=j-1;
    };

    cout << endl;
    cout << "The sum is " << sum <<  endl;

    system("pause");

    return 0;
}

