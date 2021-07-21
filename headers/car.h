#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <vector>

class Car
{
public:
    Car(std::vector<std::string>);
    Car(int id, std::string model,int color,int year);
    friend bool operator<(const Car &c1,const Car &c2);
    friend std::ostream& operator<<(std::ostream &out,const Car &c1);
    int getColor();
    int getYear();
private:
    int id;
    std::string model;
    int color;
    int year;
};

#endif // CAR_H
