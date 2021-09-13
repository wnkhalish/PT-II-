// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019
// ? Revision and Level Test of Procedural Programming
// ! Program 3: Find the sum of a list of numbers

#include <iostream>

using namespace std;

int main()
{
    int m, n;
    int sum = 0;

    cout << "Enter the starting number  => ";
    cin >> m;

    cout << "Enter the ending number  => ";
    cin >> n;

    // ! The original code (by MD RAQIBUL ISLAM) is working fine
    // ! The changes I made here is to make it better or cleaner.
    // ! The key idea, use only one case for the summation, instead of two.
    // ! Heer I choose to perform summation only from low to high.
    //
    // ! Thus, before performing the summation, we first need to check whether
    // ! m <= n or not. Otherwise, we need to swap or exchange m and n
    //
    // ! Jumail

    if (m > n)
    { // ! swap m and n if it is the other case
        // These are the swapping algorithm
        int hold = m;
        m = n;
        n = hold;
    }

    // ! And we perform only one type of summation (i.e., from low to high)
    for (int i = m; i < n + 1; i++)
    {
        sum += i;
    }
    cout << endl;
    cout << "The sum is " << sum << endl;

    system("pause");

    return 0;
}
