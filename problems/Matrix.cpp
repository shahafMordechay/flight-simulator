//
// Created by nisan on 1/13/19.
//

#include "Matrix.h"

//build my maze.
Matrix::Matrix(vector<string> &mat, string &src, string &dst) {
    string row, col;
    row = src.substr(0, src.find(','));
    src = src.substr(src.find(',') + 1);
    col = src;
    //initialize src
    this->src = new State<Entry>(Entry(atoi(row.c_str()), atoi(col.c_str())));
    //initialize dst
    row = dst.substr(0, dst.find(','));
    dst = dst.substr(dst.find(',') + 1);
    col = dst;
    this->dst = new State<Entry>(Entry(atoi(row.c_str()), atoi(col.c_str())));
    // initialize running indexes
    int i, j, k;
    i = j = k = 0;
    // row number.(j)
    for (; j < mat.size(); ++j) {
        // col number.(i)
        string line = mat[j];
        while (!line.empty()) {
            // tmp.
            State<Entry> *current = new State<Entry>(Entry(j, i));
            // set cost.
            string cost = line.substr(0, line.find(','));
            if (line.find(',') != std::string::npos)
                line = line.substr(cost.length() + 1);
            else
                line = "";
            current->setCost(atoi(cost.c_str()));
            this->matrix.emplace_back(current);
            i++;
            k += cost.length();
            if (current->getState() == this->dst->getState())
                this->dst->setCost(current->getCost());

        }
        i = 0;

    }
    this->src->setCost(0);
}


State<Entry> *Matrix::getInitialState() {
    return this->src;
}

State<Entry> *Matrix::getGoalState() {
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
        if (((state->getState() == up) || (state->getState() == down) || (state->getState() == left) ||
             (state->getState() == right)) && state->getCost() != -1 && state->getState() != this->src->getState())
            ways.emplace_back(state);
    }
    // ret list of ways.
    return ways;

    // find all ways.


}

Matrix::~Matrix() {
    this->src->setCameFrom(nullptr);
    this->dst->setCameFrom(nullptr);
    for (auto &i: this->matrix) {
        i->setCameFrom(nullptr);
    }
    delete(this->src);
    delete(this->dst);
    while(!this->matrix.empty()){
        State<Entry>* state = this->matrix.back();
        this->matrix.pop_back();
        delete(state);
    }


}

