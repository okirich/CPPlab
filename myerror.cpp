#include "myerror.h"

myerror::myerror(QObject *parent, std::string errMsg) : QObject(parent)
{
    this->message = "defalut";
}

void myerror::setErrorMsg(QString msg)
{
    this->message = msg;
    emit valueChanged(msg);
}

std::vector<std::string> checkCSV(std::string str_buff)
{
    if (str_buff.empty())
            throw new myerror(nullptr,"DB corrupted!");
        for (auto ch : str_buff)
            if (ch == '\n')
                throw new myerror(nullptr,"DB corrupted!");
        auto tokens = split(str_buff, ';');
        if (tokens.size() < 4)
            throw new myerror(nullptr,"DB corrupted!");
        return tokens;
}
