#ifndef FSSERVER_STRINGREVERSER_H
#define FSSERVER_STRINGREVERSER_H


#include "Solver.h"
#include "ServerSide.h"

class StringReverser : public Solver<string, string> {
public:
    string solve(std::string &problem) {
        string probCopy = problem;
        int len = (int)probCopy.length();
        int half = (len / 2);
        for (int i = 0; i < half; ++i) {
            char temp = probCopy[i];
            probCopy[i] = probCopy[len - 1 - i];
            probCopy[len - 1 - i] = temp;
        }

        return probCopy;
    }
};


#endif //FSSERVER_STRINGREVERSER_H
