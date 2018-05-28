#include <QApplication>
#include <QQmlApplicationEngine>
#include "../../parser/parse.h"
#include "../../parser/card.h"
#include "backend.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
    parse myParser(true);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
