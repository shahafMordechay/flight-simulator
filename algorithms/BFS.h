//
// Created by nisan on 1/12/19.
//

#ifndef FLIGHTSIMULATOR_BFS_H
#define FLIGHTSIMULATOR_BFS_H

#include <queue>
#include "Entry.h"
#include "Searcher.h"

template<class Solution>
class BFS : public Searcher<class Entry, string> {
    //pr queue.
    queue<State<Entry>> movingBreath;
public:
    State<Entry> popOpenList() override;

    int openListSize() override;

    virtual bool exists(State<Entry>);

    string backTrace(State<Entry>);

    string search(ISearchable<Entry> *searchable) override;

    BFS();
};


#endif //FLIGHTSIMULATOR_BFS_H
