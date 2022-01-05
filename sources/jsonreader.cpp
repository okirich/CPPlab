#include "../headers/jsonreader.h"

JSONReader::JSONReader(std::string filePath, std::string fileName)
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

//std::vector<std::vector<std::string> > JSONReader::read()
//{
//    std::vector<std::vector<std::string> > vectBuf;
//    json j;
//    fin >> j;
//    std::cout<<j;
//    return vectBuf;
//}
