#ifndef JSONREADER_H
#define JSONREADER_H

#include "../headers/abstractreader.h"
#include "myerror.h"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class JSONReader : public AbstractReader
{
public:
    JSONReader(std::string fileName);
    ~JSONReader();
    bool is_open() override;
    std::vector<std::vector<std::string>> read() override;
private:
    std::ifstream fin;
};

#endif // JSONREADER_H
