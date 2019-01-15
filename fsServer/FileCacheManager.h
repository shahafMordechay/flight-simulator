#ifndef FSSERVER_FILECACHEMANAGER_H
#define FSSERVER_FILECACHEMANAGER_H

#include <unordered_map>
#include <fstream>
#include <list>

#include "CacheManager.h"

using namespace std;

class FileCacheManager : public CacheManager {
    string probFileName;
    string solFileName;
    unordered_map<string, string> solutions;
    unordered_map<string, string> newSolutions;
public:

    FileCacheManager(const string &problemFileName, const string &solutionFileName) {
        this->probFileName = problemFileName;
        this->solFileName = solutionFileName;
        loadSolutions();
    }

    bool containSolution(const string &problem) {
        return !(solutions.find(problem) == solutions.end());

    }

    string getSolution(const string &problem) {
        if (containSolution(problem)) {
            return this->solutions.at(problem);
        }

        return nullptr;
    }

    void saveSolution(const string problem, const string solution) {
        pair<string, string> tempPair(problem, solution);
        solutions.insert(tempPair);
        newSolutions.insert(tempPair);
    }

    void loadSolutions() {

        list<string> problemsList;
        list<string> solutionsList;
        string line;

        ifstream probFile;
        probFile.open(this->probFileName);

        while (getline(probFile, line)) {
            problemsList.push_back(line);
        }

        ifstream solFile;
        solFile.open(this->solFileName);

        while (getline(solFile, line)) {
            solutionsList.push_back(line);
        }

        auto probIt = problemsList.begin();
        auto solIt = solutionsList.begin();

        for (; probIt != problemsList.end(), solIt != solutionsList.end(); probIt++, solIt++) {
            pair<string, string> tempPair(*probIt, *solIt);
            solutions.insert(tempPair);
        }

        probFile.close();
        solFile.close();
    }

    void writeSolutions() override{
        ofstream probFile;
        probFile.open(this->probFileName, ios::app);

        ofstream solFile;
        solFile.open(this->solFileName, ios::app);

        for (pair<string, string> element : newSolutions) {
            probFile << element.first << endl;
            solFile << element.second << endl;
        }

        probFile.close();
        solFile.close();
    }
};


#endif //FSSERVER_FILECACHEMANAGER_H
