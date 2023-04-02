#include "calculator.h"
#include "./ui_calculator.h"
#include "mathLib.h"
#include <QDebug>
#include <stack>

calculator::calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculator)
{
    ui->setupUi(this);

    connect(ui->Button0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->Button9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->ButtonAdd,SIGNAL(released()),this,SLOT(operation_pressed()));
    connect(ui->ButtonSub,SIGNAL(released()),this,SLOT(operation_pressed()));
    connect(ui->ButtonMul,SIGNAL(released()),this,SLOT(operation_pressed()));
    connect(ui->ButtonDiv,SIGNAL(released()),this,SLOT(operation_pressed()));
}

calculator::~calculator()
{
    delete ui;
}

double firstValue, secondValue;
bool digitPressed = false;
QString operation = "";

// Handle the digits buttons.
void calculator::digit_pressed(){
    QPushButton *button = (QPushButton*)sender();
    QString screenString;

    screenString = ui->label->text();
    if (!digitPressed){
        screenString = "";
    }
    screenString = screenString + button->text();

    ui->label->setText(screenString);
    digitPressed = true;
}

// Handle the decimal button.
void calculator::on_ButtonDec_released()
{
    QString screenString;
    screenString = ui->label->text();

    screenString = screenString + ".";

    ui->label->setText(screenString);
}

// Handle the plus-minus button.
void calculator::on_ButtonNeg_released()
{
    double screenNumValue;
    QString screenString;
    int textLength = 0;

    screenString = ui->label->text();
    if (screenString.contains(".")){
        textLength = screenString.split(".").last().length();
    }

    screenNumValue = (screenString.toDouble());
    screenNumValue = MATHLIB_H::Negation(screenNumValue);
    screenString = QString::number(screenNumValue,'f',textLength);

    if (screenNumValue != 0){
        ui->label->setText(screenString);
    }
}

// Handle the operation buttons.
void calculator::operation_pressed()
{
    QString screenString;
    QPushButton *button = (QPushButton*)sender();

    screenString = ui->label->text();

    if (button->text() == "+"){
        if (!digitPressed){
            digitPressed = true;
        }
        else{
            digitPressed = false;
            operation = "+";
            firstValue = screenString.toDouble();
        }
        screenString = "+";
    }
    else if (button->text() == "-"){
        if (!digitPressed){
            digitPressed = true;
        }
        else{
            digitPressed = false;
            operation = "-";
            firstValue = screenString.toDouble();
        }
        screenString = "-";
    }
    else if (button->text() == "*"){
        screenString = "*";
        operation = "*";
        digitPressed = false;
        firstValue = screenString.toDouble();
    }
    else if (button->text() == "/"){
        screenString = "/";
        operation = "/";
        digitPressed = false;
        firstValue = screenString.toDouble();
    }
    else{
        ;
    }

    ui->label->setText(screenString);
}

// Handle the equals button.
void calculator::on_ButtonEq_released()
{
    QString screenString;
    double result;

    screenString = ui->label->text();
    secondValue = screenString.toDouble();
    digitPressed = false;

    if (operation == "+"){
        result = MATHLIB_H::Addition(firstValue, secondValue);
    }
    else if (operation == "-"){
        result = MATHLIB_H::Subtraction(firstValue, secondValue);
    }
    else if (operation == "*"){
        result = MATHLIB_H::Multiplication(firstValue, secondValue);
    }
    else if (operation == "/"){
        result = MATHLIB_H::Division(firstValue, secondValue);
    }
    else{
        ;
    }

    screenString = QString::number(result,'g',15);
    ui->label->setText(screenString);
}

void calculator::on_ButtonCE_released()
{
    QString screenString;
    screenString = ui->label->text();

    screenString.chop(1);
    ui->label->setText(screenString);
}


void calculator::on_ButtonC_released()
{
    ui->label->setText("");
}
