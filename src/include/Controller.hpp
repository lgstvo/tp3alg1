#ifndef CONTROL
#define CONTROL
#include <vector>
#include "Station.hpp"

using namespace std;

class Control{
    private:
        int StationsCount;
        int maxStations;
        int discountTimeLimit;
        vector<double> discounts;
        vector <Station> stations;
        double** costs;

    public:
        Control();

        void initCosts();
        void init();
        double getMinimumFromColumn(int);
        void costsMatrix();
};

#endif