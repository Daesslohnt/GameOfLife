#include <iostream>
#include <vector>

using namespace std;

//    Any live cell with fewer than two live neighbors dies as if caused by underpopulation.
//    Any live cell with two or three live neighbors lives on to the next generation.
//    Any live cell with more than three live neighbors dies, as if by overpopulation.
//    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

class Grid{
private: 
        vector<bool> liveCells;
        vector<vector<char>> cells;
        int countNeigbours(int x, int y);
        void fill(std::vector<std::vector<int>> initialCells);
public:
        Grid(std::vector<std::vector<int>> initialCells);
        void print();
        vector<vector<char>> getCells();
        void cycle();
};