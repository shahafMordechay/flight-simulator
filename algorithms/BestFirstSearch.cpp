//
// Created by nisan on 1/12/19.
//

#include "BestFirstSearch.h"

template<class Solution>
BestFirstSearch<Solution>::BestFirstSearch() {
    this->movingBest = priority_queue<State<Entry>>();
}

template<class Solution>
State<Entry> BestFirstSearch<Solution>::popOpenList() {
    return State<Entry>(BestFirstSearch::Entry());
}

template<class Solution>
int BestFirstSearch<Solution>::openListSize() {
    return (int) this->movingBest.size();
}

template<class Solution>
bool BestFirstSearch<Solution>::exists(State<Entry>) {
    return false;
}

template<class Solution>
string BestFirstSearch<Solution>::backTrace(State<Entry> target) {
    string mySol = "";
    while (target.getCameFrom() != NULL) {
        // concat string
        mySol = target.getState().fromWhere(target.getCameFrom()->getState()) + ", " + mySol;
        // go back.
        target = *target.getCameFrom();
    }
    // cut last ", "
    mySol = mySol.substr(0, mySol.length() - 3);
    return mySol;
}

template<class Solution>
string BestFirstSearch<Solution>::search(ISearchable<Solution> searchable) {
    return std::__cxx11::string();
}
