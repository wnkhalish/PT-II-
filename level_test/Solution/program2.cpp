#include<iostream>
using namespace std;
int largest(int, int, int, int);

int main()
{
	 float n1, n2, n3, n4, large;

    cout << "Enter 4 numbers: ";
    cin >> n1 >> n2 >> n3 >> n4;
    
    large = largest(n1, n2, n3, n4);
  

    return 0;

}
int largest (int a, int b, int c, int d)
{
	if(a >= b && a >= c && a >= d)
    {
        cout << "Largest number: " << a;
    }

    if(b >= a && b >= c && b >= d)
    {
        cout << "Largest number: " << b;
    }

    if(c >= a && c >= b && c >= d) 
	{
        cout << "Largest number: " << c;
    }
    
    if(d >= a && d >= b && d >= c)
	 {
        cout << "Largest number: " << d;
    }
}
