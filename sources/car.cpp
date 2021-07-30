#include "../headers/car.h"

Car::Car(std::vector<std::string>tokens)
{
    this->id = std::stoi(tokens[0]);
    this->model = tokens[1];
    this->color = std::stoi(tokens[2]);
    this->year = std::stoi(tokens[3]);
    count ++;
    this->id = count;
}

Car::Car(int id,std::string model, int color, int year)
{
    this->id = id;
    this->model = model;
    this->color = color;
    this->year = year;
    count ++;
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

std::ostream& operator<< (std::ostream &out,const Car &c1)
{
    out << c1.id << ';' << c1.model \
        << ';' << c1.color << ';' << c1.year;
    return out;
}
