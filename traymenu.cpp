#include "traymenu.h"

#include "ui_traymenu.h"

namespace shutter {

TrayMenu::TrayMenu(QWidget* parent) : QMenu(parent), ui(new Ui::TrayMenu) {
	ui->setupUi(this);
}

TrayMenu::~TrayMenu() { delete ui; }

}  // namespace shutter
