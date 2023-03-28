#ifndef MATHLIB_H
#define MATHLIB_H
#include <stdexcept>

double Negation(double oldValue)
{
    double newValue = -1 * oldValue;
    return newValue;
}

double Addition(double addend1, double addend2)
{
    double sum = addend1 + addend2;
    return sum;
}

double Subtraction(double minuend, double subtrahend)
{
    double difference = minuend - subtrahend;
    return difference;
}

double Multiplication(double multiplicand, double multiplier)
{
    double product = multiplicand * multiplier;
    return product;
}

double Division(double dividend, double divisor)
{
    if (divisor == 0.0)
        throw std::overflow_error("Division by zero...");

    double quotient = dividend / divisor;
    return quotient;
}

double Power(double base, double exponent)
{
    if (exponent == 0)
        return 1;

    double result = base;
    for (int i = 0; i < exponent - 1; i++)
    {
        result *= base;
    }

    return result;
}

double Factorial(double factorial)
{
    if (factorial == 0)
    {
        return 1;
    }

    double result = factorial;

    for (int i = factorial - 1; i > 0; i--)
    {
        result *= i;
    }

    return result;
}

// TODO : Nth root!

#endif // MATHLIB_H