//
// Created by nisan on 1/12/19.
//

#ifndef FLIGHTSIMULATOR_BESTFIRSTSEARCH_H
#define FLIGHTSIMULATOR_BESTFIRSTSEARCH_H

#include "Entry.h"
#include <queue>
#include "Searcher.h"
template <class Solution>
class BestFirstSearch: public Searcher<class Entry, Solution>{
    //pr queue.
    priority_queue<State<Entry>> movingBest;
    virtual State<Entry> popOpenList();
    virtual int openListSize();
    virtual bool exists(State<Entry>);
    string backTrace(State<Entry>);
    virtual string search(ISearchable<Solution> searchable);
    BestFirstSearch();
};



#endif //FLIGHTSIMULATOR_BESTFIRSTSEARCH_H
