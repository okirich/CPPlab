#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H
#include <vector>
#include <fstream>
#include <iostream>
#include "car.h"

class AbstractReader
{
public:
    AbstractReader();
    virtual std::vector<std::vector<std::string>> read() = 0;
    virtual bool is_open() = 0;
    virtual Car& operator>>(AbstractReader &) = 0;
private:
    std::ifstream fin;
};

#endif // ABSTRACTREADER_H
