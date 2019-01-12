#ifndef FLIGHTSIMULATOR_ISEARCHABLE_H
#define FLIGHTSIMULATOR_ISEARCHABLE_H

#include <list>

#include "State.h"

using namespace std;

template <class T>
class ISearchable {
    virtual State<T> getInitialState()=0;
    virtual State<T> getGoalState()=0;
    virtual list<State<T>> getAllPossibleStates(State<T>)=0;
};

#endif //FLIGHTSIMULATOR_ISEARCHABLE_H
