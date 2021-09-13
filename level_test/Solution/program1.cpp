// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019
// ? Revision and Level Test of Procedural Programming
// ! Program 1: Simple calculator

#include <iostream>

using namespace std;

int main()
{
     float n1, n2, result;
    char oper;
    
    cout << "Enter 2 numbers to compute =>";
    cin >> n1>> n2;
    cout << "Enter an arithmetic operation => ";
    cin >> oper;
   switch (oper)
   {
   
    	case '+':
            cout << n1+n2;
            break;

        case '-':
            cout << n1-n2;
            break;

        case '*':
            cout << n1*n2;
            break;

        case '/':
            cout << n1/n2;
            break;
	}
    return 0;
    }
    

