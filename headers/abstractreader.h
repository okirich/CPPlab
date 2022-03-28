#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H
#include <vector>
#include <fstream>
#include <iostream>
#include "car.h"
#include "myerror.h"

class AbstractReader
{
private:
    std::ifstream fin;
public:
    AbstractReader();
    virtual std::vector<std::vector<std::string>> read() = 0;
    virtual bool is_open() = 0;
    virtual bool operator>>(Car&) = 0;
    virtual operator bool() = 0;
};

Car operator>>(std::istream&,Car&);

#endif // ABSTRACTREADER_H
