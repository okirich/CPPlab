#ifndef CSVREADER_H
#define CSVREADER_H

#include "../headers/abstractreader.h"
#include "../headers/splitFunc.h"
#include "myerror.h"

class CSVReader : public AbstractReader
{
public:
    CSVReader(std::string fileName);
    ~CSVReader();
    bool is_open() override;
    std::vector<std::vector<std::string>> read() override;
private:
    std::ifstream fin;
    int strCount;
};

#endif // CSVREADER_H
