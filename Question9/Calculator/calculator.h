#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <qpushbutton.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT
    QString lnum=NULL;
    QString rnum=NULL;
    QString cal=NULL;
    int lnumber;
    int rnumber;

    public:
        Calculator(QWidget *parent = nullptr);
        ~Calculator();

private slots:
        void numClicked();
        void calClicked();
private:
        Ui::Calculator *ui;
};
#endif // CALCULATOR_H
