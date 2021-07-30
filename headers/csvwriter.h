#ifndef CSWRITER_H
#define CSWRITER_H

#include <string>
#include <fstream>

class CSVWriter
{
public:
    CSVWriter(std::string filePath, std::string fileName);
    ~CSVWriter();
    void write(std::string);
private:
    std::ofstream fout;
};

#endif // CSWRITER_H
