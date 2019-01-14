//
// Created by nisan on 1/12/19.
//

#include "AStar.h"

template<class Solution>
AStar<Solution>::AStar() {
    this->Astar = priority_queue<State<Entry>>();
}

template<class Solution>
State<Entry> AStar<Solution>::popOpenList() {
    return State<Entry>(AStar::Entry());
}

template<class Solution>
int AStar<Solution>::openListSize() {
    return 0;
}

template<class Solution>
bool AStar<Solution>::exists(State<Entry>) {
    return false;
}

template<class Solution>
string AStar<Solution>::backTrace(State<Entry>) {
    return std::__cxx11::string();
}

template<class Solution>
string AStar<Solution>::search(ISearchable<Solution> searchable) {
    //push first.
    this->Astar.push(searchable.getInitialState());
    //already visited.
    map<State<Entry>, bool> closed;
    //still entries to check.
    while (openListSize() > 0) {
        //get first in the line.
        State<Entry> current = popOpenList();
        // mark as visited
        closed.insert({current, 1});
        // target state.
        if (current.isSameState(searchable.getGoalState()))
            return backTrace(current);
        // get all possible directions.
        list<State<Entry>> mySons = searchable.getAllPossibleStates(current);
        for (State<Entry> son: mySons) {
            // if not visited yet and not in my pr queue.
            if ((closed.find(son) == closed.end()) && !exists(son) && son.getCost() != -1) {
                // set father
                son.setCameFrom(&current);
                // push to my queue.
                this->Astar.push(son);

            }
        }
    }
    // no possible solution.
    return NULL;
}
