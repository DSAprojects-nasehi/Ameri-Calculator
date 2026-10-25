#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <QString>
#include <QStringList>

class Tokenizer
{
public:
    Tokenizer();

    QStringList tokenize(const QString &expression) const;
};

#endif // TOKENIZER_H