#include "mainwindow.h"

#include <QToolButton>

#include "aboutdialog.h"
#include "selectionwindow.h"
#include "ui_mainwindow.h"

namespace shutter {
MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);

	connect(ui->actionQuit, &QAction::triggered,
	        [this](bool) { qApp->quit(); });

	connect(ui->actionAbout, &QAction::triggered,
	        [](bool) { AboutDialog().exec(); });

	connect(ui->actionSelection, &QAction::triggered, [this](bool) {
		SelectionWindow* win = new SelectionWindow();
		win->showFullScreen();
	});

	auto* desktop = new QToolButton(this);
	desktop->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	desktop->setPopupMode(QToolButton::MenuButtonPopup);
	desktop->setIcon(QIcon(":/shutter/icons/desktop.svg"));
	desktop->setText("Desktop");
	desktop->setToolTip(
		"Take a screenshot of your whole desktop or a specific desktop");
	ui->toolBar->insertWidget(ui->actionMenu, desktop);
	auto* m = new QMenu(this);
	desktop->setMenu(m);
	m->addAction(ui->actionCopy);

	auto* window = new QToolButton(this);
	window->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	window->setPopupMode(QToolButton::MenuButtonPopup);
	window->setIcon(QIcon(":/shutter/icons/sel_window.svg"));
	window->setText("Window");
	window->setToolTip("Select a window with your mouse");
	ui->toolBar->insertWidget(ui->actionMenu, window);
	auto* m2 = new QMenu(this);
	window->setMenu(m2);
	m2->addAction(ui->actionCopy);

	auto* expor = new QToolButton(this);
	expor->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	expor->setPopupMode(QToolButton::MenuButtonPopup);
	expor->setIcon(QIcon::fromTheme("document-share"));
	expor->setText("Export");
	expor->setToolTip(
		"Upload your images to an image hosting service, FTP site or export "
		"them to an arbitrary folder");
	ui->toolBar->addWidget(expor);
	auto* m3 = new QMenu(this);
	expor->setMenu(m3);
	m3->addAction(ui->actionCopy);
}

MainWindow::~MainWindow() { delete ui; }
}  // namespace shutter
