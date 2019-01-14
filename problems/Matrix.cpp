//
// Created by nisan on 1/13/19.
//

#include "Matrix.h"

//build my maze.
Matrix::Matrix(vector<string> mat, string src, string dst) {
    //initialize src
    this->src = new State<Entry>(Entry(src[0] - 48, src[src.length() - 1] - 48));
    //initialize dst
    this->dst = new State<Entry>(Entry(dst[0] - 48, dst[dst.length() - 1] - 48));
    // initialize running indexes
    int i, j, k;
    i = j = k = 0;
    // row number.(j)
    for (; j < mat.size(); ++j) {
        // col number.(i)
        while (k < mat[j].length()) {
            // separator.
            if (mat[j][k] == ',') {
                k++;
            }
                // push entry.
            else {
                // tmp.
                State<Entry> *current = new State<Entry>(Entry(j, i));
                // set cost.
                current->setCost(mat[j][k] - 48);
                this->matrix.emplace_back(current);
                i++;
                k++;
                if (current->getState() == this->src->getState())
                    this->src->setCost(current->getCost());
                if (current->getState() == this->dst->getState())
                    this->dst->setCost(current->getCost());

            }
        }
        // initialize col back to 0.
        i = 0;
        k = 0;
    }


}

State<Entry>* Matrix::getInitialState() {
    return this->src;
}

State<Entry>* Matrix::getGoalState() {
    return this->dst;
}

list<State<Entry> *> Matrix::getAllPossibleStates(State<Entry> origin) {
    // create list.
    list<State<Entry> *> ways = list<State<Entry> *>();
    // up, down, left, right.
    Entry up = Entry(origin.getState().getRow() - 1, origin.getState().getCol());
    Entry down = Entry(origin.getState().getRow() + 1, origin.getState().getCol());
    Entry left = Entry(origin.getState().getRow(), origin.getState().getCol() - 1);
    Entry right = Entry(origin.getState().getRow(), origin.getState().getCol() + 1);
    // iterate over states
    for (auto state: this->matrix) {
        if ((state->getState() == up) || (state->getState() == down) || (state->getState() == left) ||
            (state->getState() == right))
            ways.emplace_back(state);
    }
    // ret list of ways.
    return ways;

    // find all ways.


}

