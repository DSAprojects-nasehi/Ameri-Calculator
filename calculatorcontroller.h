#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include <QObject>
#include "calculatorengine.h"
#include <QString>

class CalculatorController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString expression READ expression NOTIFY expressionChanged)
    Q_PROPERTY(QString displayText READ displayText NOTIFY displayTextChanged)
public:
    explicit CalculatorController(QObject *parent = nullptr);
    Q_INVOKABLE void appendInput(const QString &text);
    Q_INVOKABLE void clearExpression();
    Q_INVOKABLE void backspace();
    Q_INVOKABLE void calculate();

    QString displayText() const;
    QString expression() const;

signals:
    void expressionChanged();
    void displayTextChanged();

private:
    QString m_expression;
    CalculatorEngine m_engine;
    QString m_displayText = "0";
    bool m_resultDisplayed = false;
};

#endif // CALCULATORCONTROLLER_H
