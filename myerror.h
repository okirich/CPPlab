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
    QString message;

public slots:
    void setErrorMsg(QString msg);

signals:
    void valueChanged(QString msg);
};

#endif // MYERROR_H
