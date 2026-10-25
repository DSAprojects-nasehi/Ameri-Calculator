#include "postfixevaluator.h"
#include "postfixevaluator.h"
#include "stack.h"
#include <stdexcept>

#include "postfixevaluator.h"
#include "stack.h"
#include <stdexcept>

PostfixEvaluator::PostfixEvaluator() {}

double PostfixEvaluator::evaluate(const QString postfix[], int count) const
{
    if (count <= 0) {
        throw std::invalid_argument("Empty postfix expression");
    }

    Stack<double> values;

    for (int i = 0; i < count; ++i) {
        bool isNumber = false;
        double value = postfix[i].toDouble(&isNumber);

        // اگر توکن عدد باشد، آن را وارد Stack می‌کنیم.
        if (isNumber) {
            values.push(value);
            continue;
        }

        QString op = postfix[i];

        // اگر توکن عملگر معتبر نباشد، خطا می‌دهیم.
        if (op != "+" && op != "-" && op != "−" &&
            op != "*" && op != "×" &&
            op != "/" && op != "÷") {
            throw std::invalid_argument("Invalid postfix token");
        }

        // هر عملگر دودویی به دو عملوند نیاز دارد.
        if (values.isEmpty()) {
            throw std::invalid_argument("Missing operand");
        }

        double right = values.pop();

        if (values.isEmpty()) {
            throw std::invalid_argument("Missing operand");
        }

        double left = values.pop();

        double result = 0.0;

        if (op == "+") {
            result = left + right;
        }
        else if (op == "-" || op == "−") {
            result = left - right;
        }
        else if (op == "*" || op == "×") {
            result = left * right;
        }
        else if (op == "/" || op == "÷") {
            if (right == 0.0) {
                throw std::domain_error("Division by zero");
            }

            result = left / right;
        }

        // حاصل عملیات دوباره وارد Stack می‌شود.
        values.push(result);
    }

    // در پایان باید دقیقاً یک نتیجه باقی مانده باشد.
    if (values.isEmpty()) {
        throw std::invalid_argument("Postfix expression has no result");
    }

    double result = values.pop();

    if (!values.isEmpty()) {
        throw std::invalid_argument("Invalid postfix expression");
    }

    return result;
}