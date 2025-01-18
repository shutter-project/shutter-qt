#include "shuttermainwindow.h"

#include <QToolButton>

#include "ui_shuttermainwindow.h"

ShutterMainWindow::ShutterMainWindow(QWidget* parent)
	: QMainWindow(parent), ui(new Ui::ShutterMainWindow) {
	ui->setupUi(this);
	connect(ui->actionQuit, &QAction::triggered,
	        [this](bool) { this->close(); });

	auto* desktop = new QToolButton(this);
	desktop->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	desktop->setPopupMode(QToolButton::MenuButtonPopup);
	desktop->setIcon(QIcon(":/shutter/icons/desktop.svg"));
	desktop->setText("Desktop");
	ui->toolBar->insertWidget(ui->actionMenu, desktop);
	auto* m = new QMenu(this);
	desktop->setMenu(m);
	m->addAction(ui->actionCopy);

	auto* window = new QToolButton(this);
	window->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	window->setPopupMode(QToolButton::MenuButtonPopup);
	window->setIcon(QIcon(":/shutter/icons/sel_window.svg"));
	window->setText("Window");
	ui->toolBar->insertWidget(ui->actionMenu, window);
	auto* m2 = new QMenu(this);
	window->setMenu(m2);
	m2->addAction(ui->actionCopy);
}

ShutterMainWindow::~ShutterMainWindow() { delete ui; }
