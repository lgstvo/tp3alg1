#include "../include/Station.hpp"

Station::Station(int time, int price){
    this->time = time;
    this->price = price;
}

int Station::getTime(){
    return time;
}

double Station::getPrice(double discount){
    double doublePrice = (double)price;

    return (doublePrice - (doublePrice * discount));
}
