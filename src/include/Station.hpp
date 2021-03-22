#ifndef STATION
#define STATION

class Station
{
private:
    int time;
    int price;

public:
    Station(){};
    Station(int time, int price);
    int getTime();
    double getPrice(double discount);
};

#endif
