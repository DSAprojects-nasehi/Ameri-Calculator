#ifndef CALCULATORENGINE_H
#define CALCULATORENGINE_H

#include <QString>

class CalculatorEngine
{
public:
    CalculatorEngine();
    double calculate(const QString &expression) const;
};

#endif // CALCULATORENGINE_H
