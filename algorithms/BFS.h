//
// Created by nisan on 1/12/19.
//

#ifndef FLIGHTSIMULATOR_BFS_H
#define FLIGHTSIMULATOR_BFS_H

#include <queue>
#include "Entry.h"
#include "Searcher.h"
template<class Solution>
class BFS: public Searcher<class Entry,Solution> {
    //pr queue.
    queue<State<Entry>> movingBreath;
    virtual State<Entry> popOpenList();
    virtual int openListSize();
    virtual bool exists(State<Entry>);
    string backTrace(State<Entry>);
    virtual string search(ISearchable<Solution> searchable);
    BFS();
};




#endif //FLIGHTSIMULATOR_BFS_H
