//
// Created by nisan on 1/12/19.
//

#ifndef FLIGHTSIMULATOR_ASTAR_H
#define FLIGHTSIMULATOR_ASTAR_H


#include <queue>
#include "Searcher.h"
#include "Entry.h"
template <class Solution>
class AStar: public Searcher<class Entry, Solution>  {
    //pr queue.
    priority_queue<State<Entry>> Astar;
    virtual State<Entry> popOpenList();
    virtual int openListSize();
    virtual bool exists(State<Entry>);
    string backTrace(State<Entry>);
    virtual string search(ISearchable<Solution> searchable);
    AStar();
};




#endif //FLIGHTSIMULATOR_ASTAR_H
