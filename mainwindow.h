#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

#include "./secondwindow.h"

#include "./headers/splitFunc.h"
#include "./headers/query.h"
#include "./headers/csvreader.h"
#include "./headers/car.h"

#include "myerror.h"
#include "mytextbrowser.h"

//#include "./headers/jsonreader.h"

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_findBtn_clicked();

    void on_AddBtn_clicked();

    //void on_FileBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
