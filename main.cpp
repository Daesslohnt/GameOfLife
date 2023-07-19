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
        grid.print();

        std::cout << grid.countNeigbours(3, 2) << std::endl;
}