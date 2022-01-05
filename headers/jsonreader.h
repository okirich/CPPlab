#ifndef JSONREADER_H
#define JSONREADER_H

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "../headers/abstractreader.h"

class JSONReader : public AbstractReader
{
public:
    JSONReader(std::string filePath, std::string fileName);
    ~JSONReader();
    bool is_open() override;
    std::vector<std::vector<std::string>> read() override;
private:
    std::ifstream fin;
};

#endif // JSONREADER_H
