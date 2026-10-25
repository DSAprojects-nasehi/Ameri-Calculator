#include "converter.h"
#include "stack.h"
#include <stdexcept>

static int precedence(const QString &op)
{
    if (op == "+" || op == "-" || op == "−") {
        return 1;
    }

    if (op == "*" || op == "/" || op == "×" || op == "÷") {
        return 2;
    }

    return 0;
}

Converter::Converter() {}

int Converter::toPostfix(const QStringList &tokens,QString output[],int capacity) const
{
    if (capacity < 0 || capacity < tokens.size()) {
        throw std::length_error("Output capacity is too small");
    }

    Stack<QString> stack;
    int outputSize = 0;

    for (const QString &token : tokens) {
        bool isNumber = false;
        token.toDouble(&isNumber);

        if (isNumber) {
            output[outputSize] = token;
            ++outputSize;
            continue;
        }

        if (token == "(") {
            stack.push(token);
            continue;
        }

        if (token == ")") {
            while (!stack.isEmpty() && stack.peek() != "(") {
                output[outputSize] = stack.pop();
                ++outputSize;
            }

            if (stack.isEmpty()) {
                throw std::invalid_argument("Mismatched parentheses");
            }

            stack.pop();
            continue;
        }

        int currentPrecedence = precedence(token);

        if (currentPrecedence > 0) {
            while (!stack.isEmpty() &&
                   stack.peek() != "(" &&
                   precedence(stack.peek()) >= currentPrecedence) {

                output[outputSize] = stack.pop();
                ++outputSize;
            }

            stack.push(token);
            continue;
        }

        throw std::invalid_argument("Invalid token");
    }

    while (!stack.isEmpty()) {
        if (stack.peek() == "(") {
            throw std::invalid_argument("Mismatched parentheses");
        }

        output[outputSize] = stack.pop();
        ++outputSize;
    }

    return outputSize;
}