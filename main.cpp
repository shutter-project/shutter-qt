#include <QApplication>
#include <QDBusConnection>
#include <QDBusInterface>
#include <QLocale>
#include <QTranslator>
#include <QWindow>

#include "mainwindow.h"
#include "singleapp.h"

int main(int argc, char* argv[]) {
	auto dbus = QDBusConnection::sessionBus();
	shutter::SingleApp single;
	dbus.registerObject("/org/shutter_project/Shutter", &single,
	                    QDBusConnection::ExportAllContents);

	// TODO startup is racy, because here SingleApp is not yet connected to
	// MainWindow. Maybe split D-Bus service to separate lock service and actual
	// messaging service?
	if (!dbus.registerService("org.shutter-project.ShutterQt")) {
		// TODO define the interface in xml and use qdbusxml2cpp instead of
		// ExportAllContents
		QDBusInterface i("org.shutter-project.ShutterQt",
		                 "/org/shutter_project/Shutter");
		i.call("raise");
		return 0;
	}

	QApplication a(argc, argv);

	QTranslator translator;
	const QStringList uiLanguages = QLocale::system().uiLanguages();
	for (const QString& locale : uiLanguages) {
		const QString baseName = "shutter_" + QLocale(locale).name();
		if (translator.load(":/i18n/" + baseName)) {
			a.installTranslator(&translator);
			break;
		}
	}

	shutter::MainWindow w;
	QObject::connect(&single, &shutter::SingleApp::raised, [&] {
		auto f = w.windowFlags();
		w.setWindowFlags(f | Qt::WindowStaysOnTopHint |
		                 Qt::X11BypassWindowManagerHint);
		w.setWindowFlags(f);
		w.show();
		w.activateWindow();
	});
	w.show();
	return a.exec();
}
