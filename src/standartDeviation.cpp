/******************************************************
 * Project name: VUT FIT IVS Project 2 - Calculator
 * File: standartDeviation.cpp
 * Date: 14.4.2023
 * Authors: Marek Joukl (xjoukl00)
 *          Marko Olesak (xolesa00)
 *          Ondrej Kozanyi (xkozan01)
 *          Jan Findra (xfindr01)
 ******************************************************/
/**
 * @file standartDeviation.cpp
 *
 * @brief File that calculates standart deviation
 */
#include <vector>
#include <stdexcept>
#include <cstdio>
#include "mathLib.h"

// result = sqrt[ Σ(xᵢ - x̄)² / (n - 1) ]

// x̄

double Mean(const std::vector<double> &values)
{
    double sum = 0.0;
    for (double value : values)
    {
        sum = Addition(sum, value);
    }

    double mean = Division(sum, values.size());
    return mean;
}

// Σ(xᵢ - x̄)²
double SumOfSquares(const std::vector<double> &values, double mean)
{
    double sum = 0.0;
    for (double value : values)
    {
        double diff = Subtraction(value, mean);
        double square = Power(diff, 2.0);
        sum = Addition(sum, square);
    }
    return sum;
}

// Σ(xᵢ - x̄)² / (n - 1)
double Variance(const std::vector<double> &values)
{
    if (values.empty())
        throw std::invalid_argument("Input vector is empty");

    double meanValue = Mean(values);
    double sumOfSquaresValue = SumOfSquares(values, meanValue);
    double variance = Division(sumOfSquaresValue, values.size());
    return variance;
}

// sqrt[ Σ(xᵢ - x̄)² / (n - 1) ]
double StandardDeviation(const std::vector<double> &values)
{
    double varianceValue = Variance(values);
    double standardDeviation = Nthroot(varianceValue, 2.0);
    return standardDeviation;
}

int main()
{
    std::vector<double> values;
    double num;
    while (scanf("%lf", &num) == 1)
    {
        values.push_back(num);
    }

    double sd = StandardDeviation(values);
    printf("%lf\n", sd);

    return 0;
}
/************** END OF standartDeviation.cpp **************/