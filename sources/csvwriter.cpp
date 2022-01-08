#include ".\headers\csvwriter.h"

CSVWriter::CSVWriter(std::string fileName)
{
    this->fout.open(fileName,std::ofstream::app);
}

CSVWriter::~CSVWriter()
{
    this->fout.close();
}

void CSVWriter::write(std::string str)
{
    fout << std::endl << str;// << std::endl;
    this->fout.close();
}

