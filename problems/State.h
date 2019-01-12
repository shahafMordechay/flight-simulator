#ifndef FLIGHTSIMULATOR_STATE_H
#define FLIGHTSIMULATOR_STATE_H

template <class T>
class State {
    T state;
    double cost;
    State<T> *cameFrom;

public:
    State(T state) {
        this->state = state;
        this->cost = 0;
        this->cameFrom = nullptr;
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    void setCameFrom(State<T> *cameFrom) {
        this->cameFrom = cameFrom;
    }

    State<T>* getCameFrom() {
        return this->cameFrom;
    }
};


#endif //FLIGHTSIMULATOR_STATE_H
