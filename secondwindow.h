#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

#include "./headers/Constants.h"
#include "./headers/csvwriter.h"
#include "./headers/car.h"

#include "myerror.h"
#include "mytextbrowser.h"

QT_BEGIN_NAMESPACE
namespace Ui {class secondwindow;}
QT_END_NAMESPACE

class secondwindow : public QDialog
{
    Q_OBJECT

public:
    explicit secondwindow(QWidget *parent = nullptr);
    ~secondwindow();

private slots:

    void on_CancelBtn_clicked();

    void dataReady();

    void on_OkBtn_clicked();

private:
    Ui::secondwindow *ui;
};

#endif // SECONDWINDOW_H
