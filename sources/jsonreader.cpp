#include "../headers/jsonreader.h"

JSONReader::JSONReader(std::string filePath,std::string fileName)
{
    this->fin = std::ifstream (filePath + '\\' + fileName);
}

JSONReader::~JSONReader()
{
    this->fin.close();
}

bool JSONReader::is_open()
{
    if (!fin.is_open()){
        std::cout << "Couldn't open file!" << std::endl;
        return false;
    }
    return true;
}

std::vector<std::vector<std::string>> JSONReader::read()
{
    std::vector<std::vector<std::string>> out;
    std::vector<std::string> tmpStr;
    json tmpJSON;
    this->fin >> tmpJSON;
    int id;
    std::string model;
    int color;
    int year;
    for(auto& e: tmpJSON)
    {
        tmpStr.clear();
        e.at("id").get_to(id);
        e.at("model").get_to(model);
        e.at("color").get_to(color);
        e.at("year").get_to(year);
        tmpStr.emplace_back(std::to_string(id));
        tmpStr.emplace_back(model);
        tmpStr.emplace_back(std::to_string(color));
        tmpStr.emplace_back(std::to_string(year));
        out.emplace_back(tmpStr);
    }
    return out;
}
