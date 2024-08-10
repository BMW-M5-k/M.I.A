#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n{}; // initializing height of pyramid
    cin >> n; 
    for (int i = 0; i <= (n-1); i++) { // first loop for number of rows
        for (int j = 0; j <= i; j++) { // second loop for asterisks in each row
            cout << "*" ;
        }
        cout << endl;
    }
    return 0;
}