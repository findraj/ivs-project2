#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class calculator; }
QT_END_NAMESPACE

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    calculator(QWidget *parent = nullptr);
    ~calculator();

private:
    Ui::calculator *ui;

private slots:
    void digit_pressed();
    void operation_pressed();
    void on_ButtonDec_released();
    void on_ButtonNeg_released();
    void on_ButtonCE_released();
    void on_ButtonC_released();
    void on_ButtonEq_released();
    void on_ButtonFact_released();
    void on_ButtonPer_released();
};
#endif // CALCULATOR_H
