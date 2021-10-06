#ifndef TRUCK_H
#define TRUCK_H

#include "headers/car.h"

class Truck : public Car
{
public:
    Truck(std::vector<std::string>tokens);
private:
    int cargo;
};

class Bus : public Car
{
public:
    Bus(std::vector<std::string>tokens);
private:
    int seats;
};
#endif // TRUCK_H
