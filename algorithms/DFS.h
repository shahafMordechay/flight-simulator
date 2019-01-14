//
// Created by nisan on 1/12/19.
//

#ifndef FLIGHTSIMULATOR_DFS_H
#define FLIGHTSIMULATOR_DFS_H


#include <stack>
#include "Searcher.h"
#include "Entry.h"

template<class Solution>
class DFS : public Searcher<class Entry, string> {
    //pr queue.
    stack<State<Entry>> movingDeep;
public:
    State<Entry> popOpenList() override;

    int openListSize() override;

    virtual bool exists(State<Entry>);

    string backTrace(State<Entry>);

    string search(ISearchable<Entry> *searchable) override;

    DFS();
};


#endif //FLIGHTSIMULATOR_DFS_H
