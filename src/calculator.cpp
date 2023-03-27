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
}

calculator::~calculator()
{
    delete ui;
}

// Handle the digits buttons.
void calculator::digit_pressed(){
    QPushButton *button = (QPushButton*)sender();
    QString screenString;

    screenString = ui->label->text() + button->text();

    ui->label->setText(screenString);
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

    screenString = ui->label->text();
    screenNumValue = (screenString.toDouble());
    screenNumValue = MATHLIB_H::Negation(screenNumValue);
    screenString = QString::number(screenNumValue,'f',15);

    if (screenNumValue != 0){
        ui->label->setText(screenString);
    }
}

// Handle the plus button.
void calculator::on_ButtonAdd_released()
{
    QString screenString;
    QString plus;
    screenString = ui->label->text();
    plus = "+";

    if (screenString[screenString.size()-1] != plus){
        ui->label->setText(screenString + plus);
    }
}

// Handle the minus button.
void calculator::on_ButtonSub_released()
{
    QString screenString;
    QString minus;
    screenString = ui->label->text();
    minus = "-";

    if (screenString[screenString.size()-1] != minus){
        ui->label->setText(screenString + minus);
    }
}

// Handle the mul button.
void calculator::on_ButtonMul_released()
{
    QString screenString;
    QString mul;
    screenString = ui->label->text();
    mul = "*";

    if (screenString.size() != 0 && screenString[screenString.size()-1].isDigit() == 1){
        ui->label->setText(screenString + mul);
    }
}

// Handle the div button.
void calculator::on_ButtonDiv_released()
{
    QString screenString;
    QString div;
    screenString = ui->label->text();
    div = "/";

    if (screenString.size() != 0 && screenString[screenString.size()-1].isDigit() == 1){
        ui->label->setText(screenString + div);
    }
}


void calculator::on_ButtonLBra_released()
{
    QString screenString;
    screenString = ui->label->text();

    ui->label->setText(screenString + "(");
}


void calculator::on_ButtonRBra_released()
{
    QString screenString;
    screenString = ui->label->text();

    ui->label->setText(screenString + ")");
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


// Function to find precedence of operators.
int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}

// Function to perform arithmetic operations.
double applyOp(double a, double b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

// Function that returns value of expression after evaluation.
double evaluate(std::string tokens){
    std::stack <double> values;
    std::stack <char> ops;

    for(int i = 0; i < tokens.length(); i++){
        if(tokens[i] == ' ') continue;

        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }

        else if(isdigit(tokens[i]) || tokens[i] == '.'){
            std::string val = "";

            while(i < tokens.length() && (isdigit(tokens[i]) || tokens[i] == '.'))
            {
                val = val + tokens[i];
                i++;
            }

            double dval = atof(val.c_str());
            values.push(dval);
            i--;
        }

        else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                double val2 = values.top();
                values.pop();

                double val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            if(!ops.empty())
            ops.pop();
        }

        else
        {
            while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])){
                double val2 = values.top();
                values.pop();

                double val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            ops.push(tokens[i]);
        }
    }

    while(!ops.empty()){
        double val2 = values.top();
        values.pop();

        double val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

// Handle the equals button.
void calculator::on_ButtonEq_released()
{
    QString screenString;
    double value;

    screenString = ui->label->text();
    std::string std_screenString = screenString.toUtf8().constData();
    value = evaluate(std_screenString);
    screenString = QString::number(value,'g',15);
    ui->label->setText(screenString);
}

