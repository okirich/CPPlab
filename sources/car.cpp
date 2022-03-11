#include "../headers/car.h"

Car::Car(std::vector<std::string>tokens)
{
    this->id = std::stoi(tokens[0]);
    this->model = tokens[1];
    this->color = std::stoi(tokens[2]);
    this->year = std::stoi(tokens[3]);
    count++;
    this->id = count;
}

Car::Car(std::string model, int color, int year)
{
    this->model = model;
    this->color = color;
    this->year = year;
    count ++;
    this->id = count;
}

Car &Car::operator=(Car&& tmp)
{
    if (&tmp == this)
                return *this;
    model = tmp.model;
    color = tmp.color;
    year = tmp.year;
    id = tmp.id;
    return *this;
}

std::ostream& operator<<(std::ostream &out, Car c1)
{
    out << c1.repr();
    return out;
}

std::string Car::repr()
{
    std::string tmp;
    tmp += std::to_string(this->id);
    tmp +=';';
    tmp += this->model;
    tmp +=';';
    tmp += std::to_string(this->color);
    tmp +=';';
    tmp += std::to_string(this->year);
    return tmp;
}

int Car::getId()
{
    return this->id;
}

std::string Car::getModel()
{

    return this->model;
}

int Car::getColor()
{
    return this->color;
}

int Car::getYear()
{
    return this->year;
}

void Car::setCount(int cnt)
{
    count = cnt;
}

bool operator<(const Car &c1,const Car &c2)
{
    return c1.year < c2.year;
}


