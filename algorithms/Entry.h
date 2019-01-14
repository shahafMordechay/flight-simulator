//
// Created by nisan on 1/12/19.
//

#ifndef FLIGHTSIMULATOR_ENTRY_H
#define FLIGHTSIMULATOR_ENTRY_H


#include <string>

class Entry {
private:
    int row, col;
public:
    Entry(int r, int c) {
        this->col = c;
        this->row = r;
    }
    Entry() = default;

    int getRow() {
        return this->row;
    }

    int getCol() {
        return this->col;
    }

    // can make diagonal moves if implemented.
    std::string fromWhere(Entry origin) {
        int rowDiff = origin.getRow() - this->getRow();
        int colDiff = origin.getCol() - this->getCol();
        if (rowDiff == 0 && colDiff == -1)
            return "Left";
        else if (rowDiff == 0 && colDiff == 1)
            return "Right";
        else if (rowDiff == -1 && colDiff == 0)
            return "Up";
        else if (rowDiff == 1 && colDiff == 0)
            return "Down";
    }

    bool operator==(Entry compared) {
        return ((this->getCol() == compared.getCol()) && (this->getRow() == compared.getRow()));
    }

};


#endif //FLIGHTSIMULATOR_ENTRY_H
