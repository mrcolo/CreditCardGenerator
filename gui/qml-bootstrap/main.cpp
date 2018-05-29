#include <QApplication>
#include <QQmlApplicationEngine>
#include "../../src/parse.h"
#include "../../src/card.h"
#include "backend.h"
#include <QStringList>
#include <QQuickView>
#include <QQmlContext>
#include <QList>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
