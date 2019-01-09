#ifndef FSSERVER_STRINGREVERSER_H
#define FSSERVER_STRINGREVERSER_H


#include "Solver.h"
#include "ServerSide.h"

class StringReverser : public Solver<string, string> {
public:
    string solve(std::string &problem) {
        int len = (int)problem.length();
        int half = (len / 2);
        for (int i = 0; i < half; ++i) {
            char temp = problem[i];
            problem[i] = problem[len - 1 - i];
            problem[len - 1 - i] = temp;
        }

        return problem;
    }
};


#endif //FSSERVER_STRINGREVERSER_H
