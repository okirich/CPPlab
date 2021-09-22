#ifndef MYERROR_H
#define MYERROR_H

#include <QObject>
#include <string>

class myerror : public QObject
{
    Q_OBJECT
public:
    explicit myerror(QObject *parent = nullptr);
private:
    std::string message;

public slots:
    void setErrorMsg(std::string msg);

signals:
    void valueChanged(std::string msg);
};

#endif // MYERROR_H
