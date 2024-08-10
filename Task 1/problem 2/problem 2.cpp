#include <iostream>
#include <string>
using namespace std;
int main()
{
    int elements{};
    cin >> elements;
    int array[elements];
    for (int i=0; i<elements; i++) {
        cin >> array[i];
    }
    int number{};
    cin >> number;
    

    int i =0;
    bool found = false;
    while(i<elements){
        if(array[i] == number){
           cout << i;
            found = true;
            break;
        }
        i++;
    }
    if(found == false){
        cout << -1;
    }
    return 0;
}