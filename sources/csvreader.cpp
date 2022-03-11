#include "../headers/csvreader.h"


CSVReader::CSVReader(std::string fileName)
{
    this->fin = std::ifstream (fileName);
}

CSVReader::~CSVReader()
{
    this->fin.close();
}

bool CSVReader::is_open()
{
    if (!fin.is_open()){
        return false;
    }
    return true;
}

std::vector<std::vector<std::string>> CSVReader::read()
{
    std::vector<std::vector<std::string>> out;
    std::string str_buff;
    while (std::getline(this->fin,str_buff)) {
        this->strCount ++;
        auto tokens = split(str_buff, ';');
        out.emplace_back(tokens);
    }
    this->fin.close();
    return out;
}

Car &CSVReader::operator >>(AbstractReader &)
{
    std::string str_buff;
    std::getline(this->fin,str_buff);
    this->strCount ++;
    auto tokens = split(str_buff, ';');
    this->fin.close();
    auto out = new Car(tokens);
    return *out;
}
