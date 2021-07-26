#include "mainwindow.h"
#include "./ui_mainwindow.h"

const std::string filePath = "C:\\Users\\Kirill\\Documents\\CarFinder";
const std::string fileName = "cars.txt";

// обнавление результирующей таблицы
void tabelReload(QTableWidget& Tabel,std::vector<Car>& cars)
{
    Tabel.setRowCount(cars.size());
    Tabel.setHorizontalHeaderLabels(QStringList() << "id" << "model" << "color" << "year");
    for (int i = 0; i < Tabel.rowCount();++i)
    {
        QTableWidgetItem *id = new QTableWidgetItem(QString::number(cars[i].getId()));
        QTableWidgetItem *model = new QTableWidgetItem(QString::fromStdString(cars[i].getModel()));
        QTableWidgetItem *color = new QTableWidgetItem(QString::number(cars[i].getColor()));
        QTableWidgetItem *year = new QTableWidgetItem(QString::number(cars[i].getYear()));
        Tabel.setItem(i,0,id);
        Tabel.setItem(i,1,model);
        Tabel.setItem(i,2,color);
        Tabel.setItem(i,3,year);
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto db = CSVReader(filePath,fileName);
    if (!db.is_open())
    {
        std::cout << "couldn't open db file" << std::endl;
    }
    else
    {
        std::vector<Car> cars;
        auto tmpVector = db.read();
        // создание Сar объектов из файла
        for (auto strVect : tmpVector)
        {
            cars.emplace_back(Car(strVect));
        }
        tabelReload(*ui->tableWidget,cars);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_findBtn_clicked()
{
    query request;
    std::string query = ui->queryLine->text().toStdString();
    setReqvParam(request,query);
}
