#ifndef CSVREADER_H
#define CSVREADER_H

#include "../headers/abstractreader.h"
#include "../headers/splitFunc.h"

class CSVReader : public AbstractReader
{
public:
    CSVReader(std::string filePath, std::string fileName);
    bool is_open() override;
    std::vector<std::vector<std::string>> read() override;
private:
    std::ifstream fin;
};

#endif // CSVREADER_H
