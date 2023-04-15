/******************************************************
 * Project name: VUT FIT IVS Project 2 - Calculator
 * File: calculator.cpp
 * Date: 14.4.2023
 * Authors: Marek Joukl (xjoukl00)
 *          Marko Olesak (xolesa00)
 *          Ondrej Kozanyi (xkozan01)
 *          Jan Findra (xfindr01)
******************************************************/
/**
 * @file calculator.cpp
 * @brief File that handles GUI for the calculator
 */
#include "calculator.h"
#include "./ui_calculator.h"
#include "mathLib.h"
#include <QDebug>
#include <stack>
/**
 * @brief Construct a new calculator::calculator object
 * 
 * @param parent 
 */
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
    connect(ui->ButtonPow,SIGNAL(released()),this,SLOT(operation_pressed()));
    connect(ui->ButtonSqrt,SIGNAL(released()),this,SLOT(operation_pressed()));
}
/**
 * @brief Destroy the calculator::calculator object
 * 
 */
calculator::~calculator()
{
    delete ui;
}

double firstValue, secondValue;
bool digitMode = false;
QString operation = "";

/**
 * @brief closes window of calculator
 */
void calculator::digit_pressed(){
    QPushButton *button = (QPushButton*)sender();
    QString screenString;

    screenString = ui->label->text();
    if (!digitMode){
        screenString = "";
    }
    screenString = screenString + button->text();

    ui->label->setText(screenString);
    digitMode = true;
}

/**
 * @brief Handle the decimal button.
 */
void calculator::on_ButtonDec_released()
{
    QString screenString;
    screenString = ui->label->text();

    screenString = screenString + ".";

    ui->label->setText(screenString);
}

/**
 * @brief Handle the plus-minus button.
 */
void calculator::on_ButtonNeg_released()
{
    double screenNumValue;
    QString screenString;

    screenString = ui->label->text();

    screenNumValue = (screenString.toDouble());
    screenNumValue = Negation(screenNumValue);
    screenString = QString::number(screenNumValue,'g',15);

    if (screenNumValue != 0){
        ui->label->setText(screenString);
    }
}

/**
 * @brief Handle the operation buttons.
 */
void calculator::operation_pressed()
{
    QString screenString;
    QPushButton *button = (QPushButton*)sender();

    if (digitMode){
        if (operation != ""){
            on_ButtonEq_released();
        }

        screenString = ui->label->text();
        digitMode = false;
        firstValue = screenString.toDouble();

        if (button->text() == "+"){
            operation = "+";
            screenString = "+";
        }
        else if (button->text() == "-"){
            operation = "-";
            screenString = "-";
        }
        else if (button->text() == "*"){
            operation = "*";
            screenString = "*";
        }
        else if (button->text() == "/"){
            operation = "/";
            screenString = "/";
        }
        else if (button->text() == "^"){
            operation = "^";
            screenString = "^";
        }
        else if (button->text() == "√"){
            operation = "√";
            screenString = "√";
        }
        else{
            ;
        }

        ui->label->setText(screenString);
    }
    else{
        if (button->text() == "-"){
            digitMode = true;
            ui->label->setText("-");
        }
    }
}

/**
 * @brief Handle the equals button.
 */
void calculator::on_ButtonEq_released()
{
    if (digitMode){
        QString screenString;
        double result;

        screenString = ui->label->text();
        secondValue = screenString.toDouble();

        digitMode = true;

        if (operation == "+"){
            result = Addition(firstValue, secondValue);
        }
        else if (operation == "-"){
            result = Subtraction(firstValue, secondValue);
        }
        else if (operation == "*"){
            result = firstValue * secondValue;
        }
        else if (operation == "/"){
            result = Division(firstValue, secondValue);
        }
        else if (operation == "^"){
            result = Power(firstValue, secondValue);
        }
        else if (operation == "√"){
            result = Nthroot(secondValue, firstValue);
        }
        else if (operation == ""){
            result = secondValue;
        }
        else{
            result = 42;
        }

        operation = "";
        screenString = QString::number(result,'g',15);
        firstValue = screenString.toDouble();
        ui->label->setText(screenString);
    }
}
/**
 * @brief Handles the CE button
 */

void calculator::on_ButtonCE_released()
{
    QString screenString;
    screenString = ui->label->text();

    screenString.chop(1);
    ui->label->setText(screenString);
}

/**
 * @brief Handles the C button
 */

void calculator::on_ButtonC_released()
{
    ui->label->setText("");
}
/**
 * @brief Handles the factorial button
 */
void calculator::on_ButtonFact_released()
{
    QString screenString;
    screenString = ui->label->text();

    double value = Factorial(screenString.toDouble());
    screenString = QString::number(value,'g',15);
    ui->label->setText(screenString);
}
/**
 * @brief Handles the percentile button
 */
void calculator::on_ButtonPer_released()
{
    QString screenString;
    screenString = ui->label->text();

    double value = Percentile(screenString.toDouble());
    screenString = QString::number(value,'g',15);
    ui->label->setText(screenString);
}
/************** END OF calculator.cpp **************/
