#include "myerror.h"

myerror::myerror(QObject *parent) : QObject(parent)
{
    this->message = "defalut";
}

void myerror::setErrorMsg(std::string msg)
{
    this->message = msg;
    emit valueChanged(msg);
}
