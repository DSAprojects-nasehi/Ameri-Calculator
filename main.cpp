#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "calculatorcontroller.h"
#include <QQmlContext>
#include "stack.h"
#include <QDebug>
#include "tokenizer.h"
#include "converter.h"
#include "postfixevaluator.h"
#include "calculatorengine.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    CalculatorEngine calculatorEngine;

    qDebug() << "Result:"
             << calculatorEngine.calculate("2+3*4");
    // Tokenizer tokenizer;
    // Converter converter;

    // QStringList tokens = tokenizer.tokenize("(2+3)*4");
    // QStringList tokens = tokenizer.tokenize("8-3+2");

    QString output[100];
    // int count = converter.toPostfix(tokens, output, 100);



    CalculatorController controller;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("controller", &controller);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("calc", "Main");

    return QGuiApplication::exec();
}
