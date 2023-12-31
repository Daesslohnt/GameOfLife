#include "grid.h"

Grid::Grid(std::vector<std::vector<int>> initialCells){
        for (int i=0; i < 10; i++){
                vector<char> v;
                for (int j=0; j<10; j++){
                        v.push_back('o');
                }
                cells.push_back(v);
        }
        fill(initialCells);
}

vector<vector<char>> Grid::getCells(){
        return cells;
}

void Grid::print(){
        for (int i=0; i < 10; i++){
                for (int j=0; j < 10; j++){
                        std::cout << cells[i][j] << " "; 
                }
                std::cout << std::endl;
        }
        std::cout << std::endl;
}

void Grid::fill(std::vector<std::vector<int>> initialCells){
        for (std::vector<int> coord: initialCells){
                cells[coord[0]][coord[1]] = 'x';
        }
}

int Grid::countNeigbours(int x, int y){
        int counter = 0;
        for (int i=y-1; i < y+2; i++){
                for (int j=x-1; j < x+2; j++){
                        if (i >= 0 && j >= 0 && i < 10 && j < 10 && cells[i][j] == 'x'){
                                if (j != x || i != y)
                                        counter++;
                        }
                }
        }
        return counter;
}

//    Any live cell with fewer than two live neighbors dies as if caused by underpopulation.
//    Any live cell with two or three live neighbors lives on to the next generation.
//    Any live cell with more than three live neighbors dies, as if by overpopulation.
//    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

void Grid::cycle(){
        for (int i=0; i<10; i++){
                for (int j=0; j<10; j++){
                        int nCount = countNeigbours(j, i);
                        if (cells[i][j] == 'x'){
                                //cout << "Count: " << nCount << " Coord: " << i << " " << j << endl;
                                if (nCount < 2 || nCount > 3) {
                                        cells[i][j] = 'o';
                                }
                        }
                        else {
                                if (nCount == 3)
                                        cells[i][j] = 'x';
                        }
                }
        }
}