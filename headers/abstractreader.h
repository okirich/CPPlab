#ifndef ABSTRACTREADER_H
#define ABSTRACTREADER_H
#include <vector>
#include <fstream>
#include <iostream>

class AbstractReader
{
public:
    AbstractReader();
    virtual std::vector<std::vector<std::string>> read() = 0;
    virtual bool is_open() = 0;
};

#endif // ABSTRACTREADER_H
