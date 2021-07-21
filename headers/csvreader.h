#ifndef CSVREADER_H
#define CSVREADER_H

#include <fstream>
#include <vector>

class CSVReader
{
public:
    CSVReader(std::ifstream);
    //try to open file
    bool fileFine(std::ifstream);
    //read file and pars each line into tokens
    std::vector<std::vector<std::string>> read(std::ifstream, std::string);
};

#endif // CSVREADER_H
