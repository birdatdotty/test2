#include "ComboBoxDayModel.h"
#include "ComboBoxModel.h"
#include "MySQLite.h"
#include "NewPeopleModel.h"
#include "PeopleModel.h"

#include <QDate>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // register class:
    qmlRegisterType<NewPeopleModel>("Test2", 1, 0, "NewPeopleModel");
    qmlRegisterType<ComboBoxDayModel>("Test2", 1, 0, "ComboBoxDayModel");
    qmlRegisterType<MySQLite>("MyMisc", 1, 0, "MySQLite");
    qmlRegisterType<ComboBoxModel>("MyMisc", 1, 0, "ComboBoxModel");
    qmlRegisterType<PeopleModel>("MyMisc", 1, 0, "PeopleModel");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
