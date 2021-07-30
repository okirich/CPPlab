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
    Car(int id,std::string model,int color,int year);
    friend bool operator<(const Car &c1,const Car &c2);
    friend std::ostream& operator<<(std::ostream &out,const Car &c1);
    std::string repr();
    int getId();
    std::string getModel();
    int getColor();
    int getYear();
    static void setCount(int);
private:
    int id;
    std::string model;
    int color;
    int year;
    static int count;
};

#endif // CAR_H
