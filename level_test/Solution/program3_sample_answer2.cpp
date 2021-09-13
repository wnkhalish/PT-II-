// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019
// ? Revision and Level Test of Procedural Programming
// ! Program 3: Find the sum of a list of numbers

#include <iostream>

using namespace std;

int main()
{
    int m, n;
    int  sum = 0;

    cout << "Enter the starting number  => ";
    cin >> m;

    cout << "Enter the ending number  => ";
    cin >> n;

    if (m > n)
    {

        for (int i = n; i < m + 1; i++)
        {
            sum += i;
        }
    }
    else
    {

        for (int i = m; i < n + 1; i++)
        {
            sum += i;
        }
    }
    cout << endl;
    cout << "The sum is " << sum << endl;

    system("pause");

    return 0;
}
