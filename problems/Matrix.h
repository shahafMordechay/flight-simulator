//
// Created by nisan on 1/13/19.
//

#ifndef FLIGHTSIMULATOR_MATRIX_H
#define FLIGHTSIMULATOR_MATRIX_H


#include <tgmath.h>
#include <vector>
#include "ISearchable.h"
#include "../algorithms/Entry.h"

class Matrix : public ISearchable<Entry> {
    State<Entry>* src ;
    State<Entry>* dst ;
    vector<State<Entry>*> matrix;
public:
    State<Entry>* getInitialState() override;

    State<Entry>* getGoalState() override;

    list<State<Entry>*> getAllPossibleStates(State<Entry>) override;

    Matrix(vector<string> &mat, string &src, string &dst);

    ~Matrix();

};


#endif //FLIGHTSIMULATOR_MATRIX_H
