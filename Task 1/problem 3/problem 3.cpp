#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int heights[n];
    for(int i=0; i<n; i++){
        cin >> heights[i];
    }
    
    int i = 0;
    int maxHeight = heights[0];
    while(i<n){
        if(heights[i] > maxHeight){
            maxHeight = heights[i];
        }
        i++;
    }
    cout << maxHeight;
}