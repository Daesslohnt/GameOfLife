#include <iostream>
#include <vector>
#include "grid.h"

using namespace std;

int main(){
        vector<vector<int>> newCells = {
                {1,3},
                {1,4},
                {2,4},
                {5,3},
                {5,4},
                {6,2},
                {6,3},
                {7,5},
                {8,4}
        };
        Grid grid(newCells);
        
        int iterCount;
        cout << "Enter count of iterations: ";
        cin >> iterCount;

        cout << "Initial State:\n";
        grid.print();

        for (int i=0; i<iterCount; i++){
                grid.cycle();
                grid.print();
        }
}