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

Car JSONReader::operator>>(Car& out)
{
    bool flag = true;
    std::string str_buff;
    while(flag){
        std::getline(this->fin,str_buff);
        if(str_buff.find('{')!=std::string::npos)
            flag = false;
        this->strCount ++;
    }
    json j;
    std::vector<std::string> tokenString;
    j = json::parse(str_buff);
    tokenString.emplace_back(j[0]["id"].dump());
    tokenString.emplace_back(j[0]["model"].dump());
    tokenString.emplace_back(j[0]["color"].dump());
    tokenString.emplace_back(j[0]["year"].dump());
    out = Car(tokenString);
    return out;
}

JSONReader::operator bool()
{
    if (this->is_open())
        if(!this->fin.eof())
            return true;
    return false;
}
