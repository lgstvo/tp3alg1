#include "../include/Station.hpp"
#include "../include/Controller.hpp"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

Control::Control(){
    this->StationsCount = 0;
    this->maxStations = 0;
    this->discountTimeLimit = 0;
}

void Control::initCosts(){
    this->costs = new double* [this->StationsCount];
    for (int i = 0; i < this->StationsCount; i++){
        this->costs[i] = new double[this->StationsCount];
    }

}

double Control::getMinimumFromColumn(int column){

    if(column < 0){
        return 0;
    }

    double minimum = this->costs[0][column];

    for(int row = 1; row < this->StationsCount; row++){
        double cost = costs[row][column];

        if(cost < minimum && cost > 0){
            minimum = cost;
        }

    }

    return minimum;
}

void Control::costsMatrix(){

    for (int i = 0; i < this->StationsCount; i++){
        int currentTime = 0;
        int currentDiscount = 0;
        int elapsedStations = 0;
        double minimumPreviusCosts = getMinimumFromColumn(i -1);

        for (int j = i; j < this->StationsCount; j++){
            Station Station = this->stations.at(j);

            if(elapsedStations < this->maxStations){
                currentDiscount += this->discounts.at(elapsedStations);
            }
            else{
                currentDiscount = 0;
            }

            this->costs[i][j] = minimumPreviusCosts + Station.getPrice(currentDiscount / 100.0);
            minimumPreviusCosts = this->costs[i][j];
            elapsedStations++;
            currentTime += Station.getTime();

            if(currentTime >= this->discountTimeLimit){
                currentDiscount = 0;
                currentTime = 0;
                elapsedStations = 0;
            }
        }
    }

}

void Control::init(){

    cin >> this->StationsCount >> this->maxStations >> this->discountTimeLimit;

    for (int i = 0; i < this->maxStations; i++){
        int discount;
        cin >> discount;

        this->discounts.push_back(discount);
    }

    for (int i = 0; i < this->StationsCount; i++){
        int time;
        int price;

        cin >> time >> price;

        this->stations.push_back(Station(time, price));
    }

    initCosts();
    costsMatrix();

    double minimumCost = getMinimumFromColumn(this->StationsCount - 1);
    cout << fixed << setprecision(2) << minimumCost << endl;

}