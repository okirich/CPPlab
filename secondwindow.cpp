#include "secondwindow.h"
#include "ui_secondwindow.h"

secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);

    for(auto it = constants::Colors.begin();it != constants::Colors.end(); ++it)
    {
        ui->comboBox->addItem(QString().fromStdString(it->second));
    }
    connect(ui->modelLE,SIGNAL(textEdited(const QString)),this,SLOT(dataReady()));
    connect(ui->yearLE,SIGNAL(textEdited(const QString)),this,SLOT(dataReady()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(dataReady()));
}

secondwindow::~secondwindow()
{
    delete ui;    
}

std::string mapping(std::map<int,std::string> Colors,std::string str)
{
    int key = -1;
    for(auto c : Colors)
    {
        if (c.second == str)
        {
            key = c.first;
        }
    }
    return std::to_string(key);
}

void secondwindow::on_CancelBtn_clicked()
{
    this->~secondwindow();
}

void secondwindow::dataReady()
{
    QString tmp1 = this->ui->modelLE->text();
    QString tmp2 = this->ui->yearLE->text();
    if (!tmp1.isEmpty() && !tmp2.isEmpty() && (this->ui->comboBox->currentIndex()!= -1))
    {
        this->ui->OkBtn->setEnabled(true);
    }
    else
    {
        this->ui->OkBtn->setEnabled(false);
    }
}

void secondwindow::on_OkBtn_clicked()
{
    try {
        auto db = CSVWriter (constants::filePath,constants::fileName);
        std::vector<std::string> tmp;
        tmp.emplace_back("0");
        tmp.emplace_back(ui->modelLE->text().toStdString());
        tmp.emplace_back(mapping(constants::Colors,ui->comboBox->currentText().toStdString()));
        tmp.emplace_back(ui->yearLE->text().toStdString());
        auto tmp1 = Car(tmp).repr();
        db.write(tmp1);
    }  catch (const std::invalid_argument& ia) {
        myerror err;
        connect(&err,SIGNAL(valueChanged(QString)),this->parent()->findChild<mytextbrowser *>("error")\
                ,SLOT(errorReceived(QString)));
        err.setErrorMsg("<year> must be int!");
    }
    this->~secondwindow();
}
