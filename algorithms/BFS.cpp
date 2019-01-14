//
// Created by nisan on 1/12/19.
//

#include "BFS.h"


template<class Solution>
BFS<Solution>::BFS() {
    this->movingBreath = queue<State<Entry>>();
}

template<class Solution>
State<Entry> BFS<Solution>::popOpenList() {
    this->evaluatedNodes++;
    State<Entry> front = this->movingBreath.front();
    this->movingBreath.pop();
    return front;
}

template<class Solution>
int BFS<Solution>::openListSize() {
    return (int) this->movingBreath.size();
}

template<class Solution>
bool BFS<Solution>::exists(State<Entry> wanted) {
    // make copy of my queue.
    queue<State<Entry>> copy = this->movingDeep;
    // while still contains elements keep pop.
    while (!copy.empty()) {
        // if exists.
        if (wanted.isSameState(copy.front()))
            return true;
        copy.pop();
    }
    //no element equals.
    return false;
}

template<class Solution>
string BFS<Solution>::backTrace(State<Entry> target) {
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
string BFS<Solution>::search(ISearchable<Entry> *searchable) {
    //push first.
    this->movingBreath.push(searchable->getInitialState());
    //already visited.
    map<State<Entry>, bool> closed;
    //still entries to check.
    while (openListSize() > 0) {
        //get first in the line.
        State<Entry> current = popOpenList();
        // mark as visited
        closed.insert({current, 1});
        // target state.
        if (current.isSameState(searchable->getGoalState()))
            return backTrace(current);
        // get all possible directions.
        list<State<Entry>> mySons = searchable->getAllPossibleStates(current);
        for (State<Entry> son: mySons) {
            // if not visited yet and not in my pr queue.
            if ((closed.find(son) == closed.end()) && !exists(son) && son.getCost() != -1) {
                // set father
                son.setCameFrom(&current);
                // push to my queue.
                this->movingBreath.push(son);

            }
        }
    }
    // no possible solution.
    return NULL;
}

