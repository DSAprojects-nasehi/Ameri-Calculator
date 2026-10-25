#ifndef CONVERTER_H
#define CONVERTER_H

#include <QStringList>

class Converter
{
public:
    Converter();
    int toPostfix(const QStringList &tokens,QString output[],int capacity) const;
};

#endif // CONVERTER_H
