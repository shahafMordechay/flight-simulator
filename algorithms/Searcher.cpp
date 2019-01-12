//
// Created by nisan on 1/12/19.
//

#include "Searcher.h"



template<class T, class Solution>
int Searcher<T, Solution>::getNumberOfNodesEvaluated() {
    return this->evaluatedNodes;
}

template<class T, class Solution>
Searcher<T, Solution>::Searcher() {
    this->evaluatedNodes = 0;
}