#include "../headers/car.h"

Car::Car(int id, std::string model, int color, int year)
{
    this->id = id;
    this->model = model;
    this->color = color;
    this->year = year;
}

int Car::getColor()
{
    return this->color;
}

int Car::getYear()
{
    return this->year;
}

bool operator<(const Car &c1,const Car &c2)
{
    return c1.year < c2.year;
}

std::ostream& operator<< (std::ostream &out,const Car &c1)
{
    out << "| id: " << c1.id << " | model: " << c1.model \
        << " | color: " << c1.color << " | year: " << c1.year <<'|';
    return out;
}
