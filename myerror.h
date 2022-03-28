#ifndef MYERROR_H
#define MYERROR_H

#include <QObject>
#include <string>
#include "./headers/splitFunc.h"

class myerror : public QObject
{
    Q_OBJECT
public:
    explicit myerror(QObject *parent = nullptr,std::string errMsg = "default");
private:
    QString message;

public slots:
    void setErrorMsg(QString msg);

signals:
    void valueChanged(QString msg);
};

std::vector<std::string> checkBuffer(std::string str_buff);

#endif // MYERROR_H
