#include <iostream>
#include <vector>
#include "./problems/Matrix.h"
#include "algorithms/AStar.h"
#include "algorithms/BestFirstSearch.h"
#include "algorithms/BFS.h"
#include "algorithms/DFS.h"

using namespace std;

int main() {
    string src, src2, src3, src4, src5, src6, src7, src8, src9, src10;
    src = src2 = src3 = src4 = src5 = src6 = src7 = src8 = src9 = src10 = "0,0";
    string dst, dst2, dst3, dst4, dst5, dst6, dst7, dst8, dst9, dst10;
    vector<string> maze, maze2, maze3, maze4, maze5, maze6, maze7, maze8, maze9, maze10;
    Matrix *myOne;
    Matrix *myOne2;
    Matrix *myOne3;
    Matrix *myOne4;
    Matrix *myOne5;
    Matrix *myOne6;
    Matrix *myOne7;
    Matrix *myOne8;
    Matrix *myOne9;
    Matrix *myOne10;
    for (int i = 0; i < 10; ++i) {
        // size of matrix.
        int size = rand() % (50 - 10) + 10;
        for (int j = 0; j < size; ++j) {
            string row = "";
            for (int k = 0; k < size; ++k) {
                int entryCost = rand() % (30 - 10) - 1;
                // cant be 0.
                while (entryCost == 0)
                    entryCost = rand() % (30 - 10) - 1;
                row += to_string(entryCost) + ",";
            }
            row = row.substr(0, row.length() - 1);
            switch (i) {
                case 0:
                    maze.emplace_back(row);
                    break;
                case 1:
                    maze2.emplace_back(row);
                    break;
                case 2:
                    maze3.emplace_back(row);
                    break;


                case 3:
                    maze4.emplace_back(row);
                    break;


                case 4:
                    maze5.emplace_back(row);
                    break;


                case 5:
                    maze6.emplace_back(row);
                    break;


                case 6:
                    maze7.emplace_back(row);
                    break;


                case 7:
                    maze8.emplace_back(row);
                    break;


                case 8:
                    maze9.emplace_back(row);
                    break;


                case 9:
                    maze10.emplace_back(row);
                    break;

                default:
                    break;
            }
        }
        switch (i) {
            case 0:
                dst = to_string(size - 1) + "," + to_string(size - 1);
                myOne = new Matrix(maze, src, dst);

            case 1:
                dst2 = to_string(size - 1) + "," + to_string(size - 1);
                myOne2 = new Matrix(maze2, src2, dst2);

            case 2:
                dst3 = to_string(size - 1) + "," + to_string(size - 1);
                myOne3 = new Matrix(maze3, src3, dst3);

            case 3:
                dst4 = to_string(size - 1) + "," + to_string(size - 1);
                myOne4 = new Matrix(maze4, src4, dst4);

            case 4:
                dst5 = to_string(size - 1) + "," + to_string(size - 1);
                myOne5 = new Matrix(maze5, src5, dst5);

            case 5:
                dst6 = to_string(size - 1) + "," + to_string(size - 1);
                myOne6 = new Matrix(maze6, src6, dst6);

            case 6:
                dst7 = to_string(size - 1) + "," + to_string(size - 1);
                myOne7 = new Matrix(maze7, src7, dst7);

            case 7:
                dst8 = to_string(size - 1) + "," + to_string(size - 1);
                myOne8 = new Matrix(maze8, src8, dst8);

            case 8:
                dst9 = to_string(size - 1) + "," + to_string(size - 1);
                myOne9 = new Matrix(maze9, src9, dst9);

            case 9:
                dst10 = to_string(size - 1) + "," + to_string(size - 1);
                myOne10 = new Matrix(maze10, src10, dst10);
        }
    }
    Searcher<Entry, string> *mySearcher = new BestFirstSearch<string>();
    Searcher<Entry, string> *mySearcher2 = new BFS<string>();
    Searcher<Entry, string> *mySearcher3 = new DFS<string>();
    Searcher<Entry, string> *mySearcher4 = new AStar<string>();


    //best
    // 10 matrixs

    for (int j = 0; j < 10; ++j) {
        // 10 tries.
        for (int k = 0; k < 10; ++k) {
            switch (j) {
                case 0:
                    cout << mySearcher->search(myOne) << endl;
                    cout << mySearcher->getNumberOfNodesEvaluated() << endl;
                    break;
                case 1:
                    cout << mySearcher->search(myOne2) << endl;
                    cout << mySearcher->getNumberOfNodesEvaluated() << endl;
                    break;
                case 2:
                    cout << mySearcher->search(myOne3) << endl;
                    cout << mySearcher->getNumberOfNodesEvaluated() << endl;
                    break;
                case 3:
                    cout << mySearcher->search(myOne4) << endl;
                    cout << mySearcher->getNumberOfNodesEvaluated() << endl;
                    break;
                case 4:
                    cout << mySearcher->search(myOne5) << endl;
                    cout << mySearcher->getNumberOfNodesEvaluated() << endl;
                    break;
                case 5:
                    cout << mySearcher->search(myOne6) << endl;
                    cout << mySearcher->getNumberOfNodesEvaluated() << endl;
                    break;
                case 6:
                    cout << mySearcher->search(myOne7) << endl;
                    cout << mySearcher->getNumberOfNodesEvaluated() << endl;
                    break;
                case 7:
                    cout << mySearcher->search(myOne8) << endl;
                    cout << mySearcher->getNumberOfNodesEvaluated() << endl;
                    break;
                case 8:
                    cout << mySearcher->search(myOne9) << endl;
                    cout << mySearcher->getNumberOfNodesEvaluated() << endl;
                    break;
                case 9:
                    cout << mySearcher->search(myOne10) << endl;
                    cout << mySearcher->getNumberOfNodesEvaluated() << endl;
                    break;
            }
        }

    }
    //BFS
    // 10 matrixs
    for (int j = 0; j < 10; ++j) {
        // 10 tries.
        for (int k = 0; k < 10; ++k) {
            switch (j) {
                case 0:
                    cout << mySearcher2->search(myOne) << endl;
                    cout << mySearcher2->getNumberOfNodesEvaluated() << endl;
                    break;
                case 1:
                    cout << mySearcher2->search(myOne2) << endl;
                    cout << mySearcher2->getNumberOfNodesEvaluated() << endl;
                    break;
                case 2:
                    cout << mySearcher2->search(myOne3) << endl;
                    cout << mySearcher2->getNumberOfNodesEvaluated() << endl;
                    break;
                case 3:
                    cout << mySearcher2->search(myOne4) << endl;
                    cout << mySearcher2->getNumberOfNodesEvaluated() << endl;
                    break;
                case 4:
                    cout << mySearcher2->search(myOne5) << endl;
                    cout << mySearcher2->getNumberOfNodesEvaluated() << endl;
                    break;
                case 5:
                    cout << mySearcher2->search(myOne6) << endl;
                    cout << mySearcher2->getNumberOfNodesEvaluated() << endl;
                    break;
                case 6:
                    cout << mySearcher2->search(myOne7) << endl;
                    cout << mySearcher2->getNumberOfNodesEvaluated() << endl;
                    break;
                case 7:
                    cout << mySearcher2->search(myOne8) << endl;
                    cout << mySearcher2->getNumberOfNodesEvaluated() << endl;
                    break;
                case 8:
                    cout << mySearcher2->search(myOne9) << endl;
                    cout << mySearcher2->getNumberOfNodesEvaluated() << endl;
                    break;
                case 9:
                    cout << mySearcher2->search(myOne10) << endl;
                    cout << mySearcher2->getNumberOfNodesEvaluated() << endl;
                    break;
            }
        }

    }
    //DFS
    // 10 matrixs
    for (int j = 0; j < 10; ++j) {
        // 10 tries.
        for (int k = 0; k < 10; ++k) {
            switch (j) {
                case 0:
                    cout << mySearcher3->search(myOne) << endl;
                    cout << mySearcher3->getNumberOfNodesEvaluated() << endl;
                    break;
                case 1:
                    cout << mySearcher3->search(myOne2) << endl;
                    cout << mySearcher3->getNumberOfNodesEvaluated() << endl;
                    break;
                case 2:
                    cout << mySearcher3->search(myOne3) << endl;
                    cout << mySearcher3->getNumberOfNodesEvaluated() << endl;
                    break;
                case 3:
                    cout << mySearcher3->search(myOne4) << endl;
                    cout << mySearcher3->getNumberOfNodesEvaluated() << endl;
                    break;
                case 4:
                    cout << mySearcher3->search(myOne5) << endl;
                    cout << mySearcher3->getNumberOfNodesEvaluated() << endl;
                    break;
                case 5:
                    cout << mySearcher3->search(myOne6) << endl;
                    cout << mySearcher3->getNumberOfNodesEvaluated() << endl;
                    break;
                case 6:
                    cout << mySearcher3->search(myOne7) << endl;
                    cout << mySearcher3->getNumberOfNodesEvaluated() << endl;
                    break;
                case 7:
                    cout << mySearcher3->search(myOne8) << endl;
                    cout << mySearcher3->getNumberOfNodesEvaluated() << endl;
                    break;
                case 8:
                    cout << mySearcher3->search(myOne9) << endl;
                    cout << mySearcher3->getNumberOfNodesEvaluated() << endl;
                    break;
                case 9:
                    cout << mySearcher3->search(myOne10) << endl;
                    cout << mySearcher3->getNumberOfNodesEvaluated() << endl;
                    break;
            }
        }

    }
    //Astar
    // 10 matrixs
    for (int j = 0; j < 10; ++j) {
        // 10 tries.
        for (int k = 0; k < 10; ++k) {
            switch (j) {
                case 0:
                    cout << mySearcher4->search(myOne) << endl;
                    cout << mySearcher4->getNumberOfNodesEvaluated() << endl;
                    break;
                case 1:
                    cout << mySearcher4->search(myOne2) << endl;
                    cout << mySearcher4->getNumberOfNodesEvaluated() << endl;
                    break;
                case 2:
                    cout << mySearcher4->search(myOne3) << endl;
                    cout << mySearcher4->getNumberOfNodesEvaluated() << endl;
                    break;
                case 3:
                    cout << mySearcher4->search(myOne4) << endl;
                    cout << mySearcher4->getNumberOfNodesEvaluated() << endl;
                    break;
                case 4:
                    cout << mySearcher4->search(myOne5) << endl;
                    cout << mySearcher4->getNumberOfNodesEvaluated() << endl;
                    break;
                case 5:
                    cout << mySearcher4->search(myOne6) << endl;
                    cout << mySearcher4->getNumberOfNodesEvaluated() << endl;
                    break;
                case 6:
                    cout << mySearcher4->search(myOne7) << endl;
                    cout << mySearcher4->getNumberOfNodesEvaluated() << endl;
                    break;
                case 7:
                    cout << mySearcher4->search(myOne8) << endl;
                    cout << mySearcher4->getNumberOfNodesEvaluated() << endl;
                    break;
                case 8:
                    cout << mySearcher4->search(myOne9) << endl;
                    cout << mySearcher4->getNumberOfNodesEvaluated() << endl;
                    break;
                case 9:
                    cout << mySearcher4->search(myOne10) << endl;
                    cout << mySearcher4->getNumberOfNodesEvaluated() << endl;
                    break;
            }
        }

    }
    return 0;
}