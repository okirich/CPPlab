#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <vector>

#include "./headers/Constants.h"

class Car
{
public:
    Car(std::vector<std::string>);
    Car(std::string model = "",int color = -1,int year = -1);
    Car(const Car &parent)=default;
    Car& operator=(const Car& parent)=default;
    Car(Car&& tmp)=default;
    Car& operator=(Car&& tmp);
    friend bool operator<(const Car &c1,const Car &c2);
    operator bool();
    std::string repr();
    int getId();
    std::string getModel();
    int getColor();
    int getYear();
    static void setCount(int);
protected:
    int id;
    std::string model;
    int color;
    int year;
private:
    static int count;
};

std::ostream& operator<<(std::ostream &out, Car c1);

#endif // CAR_H
