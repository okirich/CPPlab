#ifndef MYTEXTBROWSER_H
#define MYTEXTBROWSER_H

#include <QWidget>
#include <QTextBrowser>

class mytextbrowser : public QTextBrowser
{
    Q_OBJECT
public:
    mytextbrowser(QWidget *parent);
private:
    QString message;
public slots:
    void errorReceived(QString msg);
};

#endif // MYTEXTBROWSER_H
