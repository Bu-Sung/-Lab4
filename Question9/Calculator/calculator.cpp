#include "calculator.h"
#include "ui_calculator.h"

#include <qpushbutton.h>
#include <qstring.h>
#include <sstream>

using namespace std;

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    /*버튼 사이즈 조절*/
    ui->setupUi(this);
    ui->btn0->setFixedSize(80,80);
    ui->btn1->setFixedSize(80,80);
    ui->btn2->setFixedSize(80,80);
    ui->btn3->setFixedSize(80,80);
    ui->btn4->setFixedSize(80,80);
    ui->btn5->setFixedSize(80,80);
    ui->btn6->setFixedSize(80,80);
    ui->btn7->setFixedSize(80,80);
    ui->btn8->setFixedSize(80,80);
    ui->btn9->setFixedSize(80,80);
    ui->btnp->setFixedSize(80,80);
    ui->btnmi->setFixedSize(80,80);
    ui->btnmu->setFixedSize(80,80);
    ui->btnd->setFixedSize(80,80);
    ui->btne->setFixedSize(80,80);
   /*버튼 coonect*/
    connect(ui->btn0, SIGNAL(clicked()), this, SLOT(numClicked()));
    connect(ui->btn1, SIGNAL(clicked()), this, SLOT(numClicked()));
    connect(ui->btn2, SIGNAL(clicked()), this, SLOT(numClicked()));
    connect(ui->btn3, SIGNAL(clicked()), this, SLOT(numClicked()));
    connect(ui->btn4, SIGNAL(clicked()), this, SLOT(numClicked()));
    connect(ui->btn5, SIGNAL(clicked()), this, SLOT(numClicked()));
    connect(ui->btn6, SIGNAL(clicked()), this, SLOT(numClicked()));
    connect(ui->btn7, SIGNAL(clicked()), this, SLOT(numClicked()));
    connect(ui->btn8, SIGNAL(clicked()), this, SLOT(numClicked()));
    connect(ui->btn9, SIGNAL(clicked()), this, SLOT(numClicked()));

    connect(ui->btnp, SIGNAL(clicked()), this, SLOT(calClicked())); //더하기
    connect(ui->btnmi, SIGNAL(clicked()), this, SLOT(calClicked())); //빼기
    connect(ui->btnmu, SIGNAL(clicked()), this, SLOT(calClicked())); //곱하기
    connect(ui->btnd, SIGNAL(clicked()), this, SLOT(calClicked())); //나누기
    connect(ui->btne, SIGNAL(clicked()), this, SLOT(calClicked())); //연산하기
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::calClicked(){ //사칙연산 가져오기
    QObject *obj = sender(); //클린된 버튼이 무엇인지
    if(lnum.length()==0){ //왼쪽 숫자 없으면 사칙연산 적용 X

    }else{
        if( obj == ui->btnp){
            cal = "+";
        }else if(obj == ui->btnmi){
            cal = "-";
        }else if(obj == ui->btnmu){
            cal = "*";
        }else if(obj == ui->btnd){
            cal = "/";
        }else if(obj == ui->btne){
            int a;
            if(cal.at(0) == '+'){ //연산후 출력
               a = lnumber + rnumber;
            }else if(cal.at(0) == '-'){
               a = lnumber - rnumber;
            }else if(cal.at(0) == '*'){
               a = lnumber * rnumber;
            }else if(cal.at(0) == '/'){
               a = lnumber / rnumber;
            }
            ui->result->setText(QString::number(a));
            lnum.clear();
            rnum.clear();
            cal.clear();
        }
        ui->preview->setText(lnum+cal);
    }
}
void Calculator::numClicked() //어떤 숫자가 눌렸는지
{
    QObject *obj = sender();
    if(!lnum.isNull() && !cal.isNull()){// 왼쪽 숫자와 사칙연산이 둘다 비어있지 않으면 오른쪽 숫자 입력
        if(obj == ui->btn0){
            rnum = rnum + "0";
        }else if(obj == ui->btn1){
            rnum = rnum + "1";
        }else if(obj == ui->btn2){
            rnum = rnum + "2";
        }else if(obj == ui->btn3){
            rnum = rnum + "3";
        }else if(obj == ui->btn4){
            rnum = rnum + "4";
        }else if(obj == ui->btn5){
            rnum = rnum + "5";
        }else if(obj == ui->btn6){
            rnum = rnum + "6";
        }else if(obj == ui->btn7){
            rnum = rnum + "7";
        }else if(obj == ui->btn8){
            rnum = rnum + "8";
        }else if(obj == ui->btn9){
            rnum = rnum + "9";
        }
        ui->result->setText(rnum);
        rnumber = rnum.toInt();
    }else{                      //왼쪽 숫자 입력
        if(obj == ui->btn0){
             lnum = lnum + "0";
        }else if(obj == ui->btn1){
            lnum = lnum + "1";
        }else if(obj == ui->btn2){
            lnum = lnum + "2";
        }else if(obj == ui->btn3){
            lnum = lnum + "3";
        }else if(obj == ui->btn4){
            lnum = lnum + "4";
        }else if(obj == ui->btn5){
            lnum = lnum + "5";
        }else if(obj == ui->btn6){
            lnum = lnum + "6";
        }else if(obj == ui->btn7){
            lnum = lnum + "7";
        }else if(obj == ui->btn8){
            lnum = lnum + "8";
        }else if(obj == ui->btn9){
            lnum = lnum + "9";
        }
        ui->preview->setText(lnum);
        lnumber = lnum.toInt();
    }
}

