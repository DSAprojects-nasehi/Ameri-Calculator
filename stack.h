
#ifndef STACK_H
#define STACK_H

#include <stdexcept>
template <typename T, int Capacity = 100>
class Stack
{
private:
    T stack[Capacity];
    int top;

public:
    Stack()
    {
        init();
    }

    void init()
    {
        top = 0;
    }
    void push(const T &value)
    {
        if (isFull()) {
            throw std::overflow_error("Stack is full");
        }

        stack[top] = value;
        top++;
    }

    T pop()
    {
        if (isEmpty()) {
            throw std::out_of_range("Cannot pop from an empty stack");
        }
        top--;
        return stack[top];
    }

    T peek() const
    {
        if (isEmpty()) {
            throw std::out_of_range("Cannot peek at an empty stack");
        }

        return stack[top - 1];
    }

    bool isEmpty() const
    {
        return top == 0;
    }

    bool isFull() const
    {
        return top == Capacity;
    }
};

#endif // STACK_H