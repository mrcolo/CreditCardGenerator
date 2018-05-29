#include <QApplication>
#include <QQmlApplicationEngine>
#include "../../src/parse.h"
#include "../../src/card.h"
#include "backend.h"
#include "createCards.h"
#include <QStringList>
#include <QQuickView>
#include <QQmlContext>
#include <QList>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
    qmlRegisterType<CreateCards>("io.qt.examples.createcards", 1, 0, "CreateCards");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));



    return app.exec();
}
