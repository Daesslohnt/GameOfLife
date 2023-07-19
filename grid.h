#include <iostream>
#include <vector>

using namespace std;

class Grid{
private: 
        vector<bool> liveCells;
        vector<vector<char>> cells;
public:
        int countNeigbours(int x, int y);
        Grid(std::vector<std::vector<int>> initialCells);
        void print();
        void fill(std::vector<std::vector<int>> initialCells);
        vector<vector<char>> getCells();
};