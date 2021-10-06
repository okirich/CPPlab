#include "../headers/truck.h"

Truck::Truck(std::vector<std::string>tokens) : Car(tokens)
{
    this->cargo = std::stoi(tokens[5]);
}

Bus::Bus(std::vector<std::string>tokens) : Car(tokens)
{
    this->seats = std::stoi(tokens[5]);
}
