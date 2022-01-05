#ifndef JSONREADER_H
#define JSONREADER_H

#include <nlohmann/json.hpp>
#include "headers\abstractreader.h"

using json = nlohmann::json;

class JSONReader : public AbstractReader
{
public:
    JSONReader(std::string filePath, std::string fileName);
    ~JSONReader();
    bool is_open() override;
    std::vector<std::vector<std::string>> read() override;
private:
    std::ifstream fin;
    int strCount;
};

#endif // JSONREADER_H
