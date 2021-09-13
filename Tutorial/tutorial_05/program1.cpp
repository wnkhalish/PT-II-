#include<iostream>
#include<string>
using namespace std;

int main()
{
    string p("Welcome to");
    string q("UTM Skudai", 3);

    string s = "100";
    string t = "1";
    string u = "";
                       
    cout << p << endl;  // (i). 
    cout << q << endl;  // (ii).
    cout << p.length() << endl; // (iii). 
    u = s + t;
    cout << u << endl;  // (iv). 
    cout << p.compare(q) << endl;  // (v). //compare character by character
    cout << p.substr(0, 3) << endl;  // (vi). 
    p.insert(0, "Hello "); // insert certain location in string
    cout << p << endl;  // (vii). 
    s.replace(0,2,"99"); // replace string
    cout << s << endl;  // (viii). 

     
    return 0;
}

