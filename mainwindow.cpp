#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./headers/Constants.h"

std::vector<Car> cars;
query reqv;

int type;

enum TypeOfFile{
    CSV,
    JSON,
};

int Car::count = 0;
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

std::vector<Car> carCreator(AbstractReader &db)
{
    std::vector<std::vector<std::string>> tmp = db.read();
    std::vector<Car> cars;
    // создание Сar объектов из файла CSV
    for (auto strVect : tmp)
    {
        cars.emplace_back(Car(strVect));
    }
    return cars;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    auto db = CSVReader(fileName);
//    cars = carCreator(db);
//    tabelReload(*ui->tableWidget,cars);
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
        if(type == 0){
            Car::setCount(0);
            auto db = CSVReader(fileName);
            if(!db.is_open()){
                    myerror err;
                    connect(&err,SIGNAL(valueChanged(QString)),ui->error,SLOT(errorReceived(QString)));
                    err.setErrorMsg("Couldn't open the file!");
                    return;
                }
            cars.clear();
            cars = carCreator(db);
            auto filtred = cars;
        }else{
            Car::setCount(0);
            auto db = JSONReader(fileName);
            if(!db.is_open()){
                    myerror err;
                    connect(&err,SIGNAL(valueChanged(QString)),ui->error,SLOT(errorReceived(QString)));
                    err.setErrorMsg("Couldn't open the file!");
                    return;
                }
            cars.clear();
            cars = carCreator(db);
            auto filtred = cars;
        }
    }
    try
    {
        setReqvParam(reqv,query);
    }
    catch (const std::invalid_argument& ia)
    {
        myerror err;
        connect(&err,SIGNAL(valueChanged(QString)),ui->error,SLOT(errorReceived(QString)));
        err.setErrorMsg("Check the query params:<year> and <color> must be int!");
    }
    auto filtred = getRequest(cars,reqv);
    tabelReload(*ui->tableWidget,filtred);
}

void MainWindow::on_AddBtn_clicked()
{
    secondwindow *window = new secondwindow(this);
    window->setModal(true);
    window->show();
}

void MainWindow::on_FileBtn_clicked()
{
    fileName = QFileDialog::getOpenFileName
            (this,"","./",tr("Text files(*.txt *.csv *.json)")).toStdString();
    if (fileName.rfind(".json")!=std::string::npos){
        type = JSON;
    }else{
        type = CSV;
    }
    std::ofstream init;
    init.open("./init.txt");
    if(init.is_open()){
        init << fileName;
    }
}
