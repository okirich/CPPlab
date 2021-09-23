#include "mytextbrowser.h"

mytextbrowser::mytextbrowser(QWidget *parent)
{

}

void mytextbrowser::errorReceived(QString msg)
{
    this->setTextColor(QColor(255,0,0));
    this->message += msg + "\n";
    this->setText(message);
}
