#include "calculatorcontroller.h"
#include <exception>

CalculatorController::CalculatorController(QObject *parent)
    : QObject{parent}
{}

QString CalculatorController::expression() const
{
    return m_expression;
}

QString CalculatorController::displayText() const
{
    return m_displayText;
}

void CalculatorController::appendInput(const QString &text)
{
    bool isOperator =
        text == "+" || text == "-" || text == "−" ||
        text == "*" || text == "/" || text == "×" || text == "÷";

    if (m_resultDisplayed) {
        if (isOperator) {
            m_expression = m_displayText + text;
        } else {
            m_expression = text;
        }

        m_resultDisplayed = false;
    } else {
        m_expression += text;
    }

    m_displayText = m_expression;

    emit expressionChanged();
    emit displayTextChanged();
}

void CalculatorController::clearExpression()
{
    m_expression.clear();
    m_displayText = "0";
    m_resultDisplayed = false;

    emit expressionChanged();
    emit displayTextChanged();
}

void CalculatorController::backspace()
{
    if (m_expression.isEmpty()) {
        return;
    }

    m_expression.chop(1);
    m_displayText = m_expression.isEmpty() ? "0" : m_expression;

      m_resultDisplayed = false;

    emit expressionChanged();
    emit displayTextChanged();
}

void CalculatorController::calculate()
{
    if (m_expression.isEmpty()) {
        m_displayText = "0";
        m_resultDisplayed = false;
        emit displayTextChanged();
        return;
    }

    try {
        double result = m_engine.calculate(m_expression);
        m_displayText = QString::number(result, 'g', 15);
        m_resultDisplayed = true;
    }
    catch (const std::exception &) {
        m_displayText = "Error";
        m_resultDisplayed = false;
    }

    emit displayTextChanged();
}