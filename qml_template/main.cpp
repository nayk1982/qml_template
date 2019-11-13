#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "GuiAppCore"
#include "Core"
//==================================================================================================
static QObject *coreProvider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    Core *core = new Core();
    return core;
}
//==================================================================================================
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    if(!nayk::GuiAppCore::initApplication(
                "Qml Template",
                "Qml Template",
                "nayk",
                "nayk.github.io")
            ) {
        return 0;
    }

    qmlRegisterSingletonType<Core>("Core", 1, 0, "Core", coreProvider);

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:///");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
//==================================================================================================
