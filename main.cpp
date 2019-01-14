#include <iostream>
#include <vector>
#include "./problems/Matrix.h"
#include "algorithms/BFS.h"
#include "algorithms/DFS.h"

int main() {
    std::string src = "3,3";
    std::string dst = "0,0";
    std::vector<std::string> maze;
    maze.emplace_back("1,3,6,2");
    maze.emplace_back("1,2,1,2");
    maze.emplace_back("1,3,9,2");
    maze.emplace_back("1,5,6,7");
    Matrix *myOne = new Matrix(maze, src, dst);
    Searcher<Entry, string> *mySearcher = new BFS <string>();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}