#include "calculatorengine.h"
#include "tokenizer.h"
#include "converter.h"
#include "postfixevaluator.h"

CalculatorEngine::CalculatorEngine() {}

double CalculatorEngine::calculate(const QString &expression) const
{
    Tokenizer tokenizer;
    Converter converter;
    PostfixEvaluator evaluator;

    QStringList tokens = tokenizer.tokenize(expression);

    QString postfix[100];
    int count = converter.toPostfix(tokens, postfix, 100);

    return evaluator.evaluate(postfix, count);
}