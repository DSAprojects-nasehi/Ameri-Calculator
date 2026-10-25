#include "tokenizer.h"


Tokenizer::Tokenizer() {}

QStringList Tokenizer::tokenize(const QString &expression) const
{
    QStringList tokens;
    QString currentNumber;

    for (const QChar ch : expression) {
        if (ch.isSpace()) {
            continue;
        }

        if (ch.isDigit() || ch == '.') {
            currentNumber.append(ch);
            continue;
        }

        if (!currentNumber.isEmpty()) {
            tokens.append(currentNumber);
            currentNumber.clear();
        }
        tokens.append(QString(ch));
    }

    if (!currentNumber.isEmpty()) {
        tokens.append(currentNumber);
    }

    return tokens;
}