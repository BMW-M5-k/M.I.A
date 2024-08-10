#include <iostream>
#include <string>
using namespace std;
int main()
{
    // getting grid data
    int rows{}; 
    int cols{};
    cin >> rows >> cols;
    int justice[rows][cols];
    int villains[rows][cols];

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> justice[i][j];
        }
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin >> villains[i][j];
        }
    }
    // determining the winner
    int justicePoints = 0;
    int villainPoints = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(justice[i][j] > villains[i][j]){
                justicePoints++;
            }
            else if(justice[i][j] < villains[i][j]){
                villainPoints++;
            }
        }
    }
    // announcing the winner
    if(justicePoints > villainPoints){
        cout << "Justice League";
    }
    else if(justicePoints < villainPoints){
        cout <<"Villains";
    }
    else{
        cout <<"Tie";
    }
}