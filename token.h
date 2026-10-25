#ifndef TOKEN_H
#define TOKEN_H

#include <QString>

enum class TokenType
{
    Number,
    Operator,
    LeftParenthesis,
    RightParenthesis
};

struct Token
{
    TokenType type;
    QString text;
};

#endif // TOKEN_H