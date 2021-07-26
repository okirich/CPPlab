#include "mainwindow.h"
#include "./ui_mainwindow.h"

const std::string filePath = "C:\\Users\\Kirill\\Documents\\CarFinder";
const std::string fileName = "cars.txt";

std::vector<Car> cars;
query reqv;
auto db = CSVReader(filePath,fileName);     //создание CSVreader объекта
auto const dbvect = db.read();
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

void carCreator(std::vector<std::vector<std::string>> db,std::vector<Car>& cars)
{
    cars.clear();
    // создание Сar объектов из файла CSV
    for (auto strVect : db)
    {
        cars.emplace_back(Car(strVect));
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    carCreator(dbvect,cars);
    tabelReload(*ui->tableWidget,cars);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_findBtn_clicked()
{
    std::string query = ui->queryLine->text().toStdString();

    if (reqv == DEFAULT_QUERY)
    {
        carCreator(dbvect,cars);
    }
    try
    {
        setReqvParam(reqv,query);
    }
    catch (const std::invalid_argument& ia)
    {
        std::cerr << "Invalid argument" << std::endl;
    }
    getRequest(cars,reqv);
    tabelReload(*ui->tableWidget,cars);
}
