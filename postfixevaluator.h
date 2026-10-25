#ifndef POSTFIXEVALUATOR_H
#define POSTFIXEVALUATOR_H


#include <QString>

class PostfixEvaluator
{
public:
    PostfixEvaluator();

    double evaluate(const QString postfix[], int count) const;
};

#endif // POSTFIXEVALUATOR_H