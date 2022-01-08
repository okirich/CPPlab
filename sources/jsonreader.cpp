#include "../headers/jsonreader.h"

JSONReader::JSONReader(std::string fileName)
{
    this->fin = std::ifstream (fileName);
}

JSONReader::~JSONReader()
{
    this->fin.close();
}

bool JSONReader::is_open()
{
    if (!fin.is_open()){
        return false;
    }
    return true;
}

std::vector<std::vector<std::string> > JSONReader::read()
{
    std::vector<std::vector<std::string> > vectBuf;
    json j;
    fin >> j;
    for (auto obj : j){
        std::vector<std::string> objString;
        objString.emplace_back(obj["id"].dump());
        objString.emplace_back(obj["model"].dump());
        objString.emplace_back(obj["color"].dump());
        objString.emplace_back(obj["year"].dump());
        vectBuf.emplace_back(objString);
    }
    return vectBuf;
}
