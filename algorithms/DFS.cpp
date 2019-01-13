//
// Created by nisan on 1/12/19.
//

#include "DFS.h"
#include <list>
#include <unordered_set>

template<class Solution>
State<Entry> DFS<Solution>::popOpenList() {
    this->evaluatedNodes++;
    State<Entry> top = this->movingDeep.top();
    this->movingDeep.pop();
    return  top;
}

template<class Solution>
int DFS<Solution>::openListSize() {
    return (int) (this->movingDeep.size());
}

template<class Solution>
DFS<Solution>::DFS() {
    this->movingDeep = stack<State<Entry>>();
}

template<class Solution>
string DFS<Solution>::search(ISearchable<Solution> searchable) {
    //push start point.
    this->movingDeep.push(searchable.getInitialState());
    //already visited.
    unordered_set<State<Entry>> closed;
    //still entries to check.
    while (openListSize() > 0) {
        //get first in the line.
        State<Entry> current = popOpenList();
        // mark as visited
        closed.insert(current);
        // target state.
        if (current.isSameState(searchable.getGoalState()))
            return backTrace(current);
        // get all possible directions.
        list<State<Entry>> mySons = searchable.getAllPossibleStates(current);
        for (State<Entry> son: mySons) {
            // if not visited yet and not in my pr queue.
            if ((closed.find(son) == NULL) && !exists(son) && son.getCost()!= -1) {
                // push to my queue.
                this->movingDeep.push(son);
            }
        }
        //set father as the node worked on before.
        this->movingDeep.top().setCameFrom(&current);
    }
    // no possible solution.
    return NULL;
}

template<class Solution>
string DFS<Solution>::backTrace(State<Entry> target) {
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
bool DFS<Solution>::exists(State<Entry> wanted) {
    // make copy of my queue.
    stack<State<Entry>> copy = this->movingDeep;
    // while still contains elements keep pop.
    while (!copy.empty()) {
        // if exists.
        if (wanted.isSameState(copy.top()))
            return true;
        copy.pop();
    }
    //no element equals.
    return false;
}
