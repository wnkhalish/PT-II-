// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019
// ? Revision and Level Test of Procedural Programming
// ! Program 4: Date conversion 1

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int d, m, y; // Day, month, Year
    string month;
    int year;
    cout << "Enter your DOB (dd mm yy) => ";
    cin >> d >> m >> y;
/*
    if (m == 1)
        month = "Jan";
    if (m == 2)
        month = "feb";
    if (m == 3)
        month = "Mar";
    if (m == 4)
        month = "Apr";
    if (m == 5)
        month = "May";
    if (m == 6)
        month = "Jun";
    if (m == 7)
        month = "Jul";
    if (m == 8)
        month = "Aug";
    if (m == 9)
        month = "Sep";
    if (m == 10)
        month = "Oct";
    if (m == 11)
        month = "Nov";
    if (m == 12)
        month = "Dec";

*/

    // ! My Comment
    // ! You should "else"  for the ifs
    // ! Also, you can make the code cleaner using a loop and an array

    const string MONTHS[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i=0; i<12; i++){
        if (m==(i+1)){
             month = MONTHS[i];
             break;  //! stop the loop as we already found a match
        }
    }

    // ? The above code can be cleaner as follows:
    // month = MONTHS[m-1];





    cout << endl;
    if (y > 18)
        y += 1900;
    else
        y += 2000;

    cout << "Your Date of Birth is " << month << " " << d << ", " << y << endl;

    system("pause");

    return 0;
}
