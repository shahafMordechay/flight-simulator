//
// Created by nisan on 1/12/19.
//

#ifndef FLIGHTSIMULATOR_DFS_H
#define FLIGHTSIMULATOR_DFS_H


#include <stack>
#include "Searcher.h"
#include "Entry.h"

template<class Solution>
class DFS : public Searcher<class Entry, Solution> {
    //pr queue.
    stack<State<Entry>> movingDeep;
    virtual State<Entry> popOpenList();
    virtual int openListSize();
    virtual bool exists(State<Entry>);
    string backTrace(State<Entry>);
    virtual string search(ISearchable<Solution> searchable);
    DFS();
};




#endif //FLIGHTSIMULATOR_DFS_H
