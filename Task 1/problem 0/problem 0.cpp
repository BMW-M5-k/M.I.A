#include <iostream>
#include <string>
using namespace std;
int main()
{
    string name{};                  // for longer names 
    getline(cin,name);              // to handle space between names
    cout << "Hello, " << name << "!";
    return 0;
}