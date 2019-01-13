//
// Created by nisan on 1/13/19.
//

#include "Matrix.h"

//build my maze.
Matrix::Matrix(vector<string> mat, string src, string dst) {
    //initialize src
    this->src = new State<Entry>(Entry(src[0], src[src.length() - 1]));
    //initialize dst
    this->dst = new State<Entry>(Entry(dst[0], dst[dst.length() - 1]));
    // initialize running indexes
    int i, j;
    i = j = 0;
    // row number.(j)
    for (; j < mat.size(); ++j) {
        // col number.(i)
        while (i < mat[j].length()) {
            // separator.
            if (mat[j][i] == ',') {
                i++;
            }
                // push entry.
            else {
                this->matrix.emplace_back(State<Entry>(Entry(j, i)));
                i++;
            }
        }
        // initialize col back to 0.
        i = 0;
    }


}

State<Entry> Matrix::getInitialState() {
    return *this->src;
}

State<Entry> Matrix::getGoalState() {
    return *this->dst;
}

list<State<Entry>> Matrix::getAllPossibleStates(State<Entry> origin) {
    // create list.
    list<State<Entry>> ways = list<State<Entry>>();
    // up, down, left, right.
    Entry up = Entry(origin.getState().getRow() - 1, origin.getState().getCol());
    Entry down = Entry(origin.getState().getRow() + 1, origin.getState().getCol());
    Entry left = Entry(origin.getState().getRow(), origin.getState().getCol() - 1);
    Entry right = Entry(origin.getState().getRow(), origin.getState().getCol() + 1);
    // iterate over states
    for (auto state: this->matrix) {
        if ((state.getState() == up) || (state.getState() == down) || (state.getState() == left) ||
            (state.getState() == right))
            ways.emplace_back(state);
    }
    // ret list of ways.
    return ways;

    // find all ways.


}

Matrix::~Matrix() {
    free(this->dst);
    free(this->src);

}
