#include "aboutdialog.h"

#include <QFile>

#include "ui_aboutdialog.h"
#include "version.h"

namespace shutter {
static QString readFile(QString name) {
	QFile file(name);
	file.open(QFile::ReadOnly | QFile::Text);
	QTextStream str(&file);
	return str.readAll();
}

AboutDialog::AboutDialog(QWidget* parent)
	: QDialog(parent), ui(new Ui::AboutDialog) {
	ui->setupUi(this);

	ui->textCredits->setText(readFile(":/shutter/data/credits.txt"));
	ui->textLicense->setText(readFile(":/shutter/data/license.txt"));
	ui->textBuild->setText(
		tr("Shutter %1\nRunning with Qt %2\nBuilt with Qt %3")
			.arg(getVersion(), qVersion(), QT_VERSION_STR));
}

AboutDialog::~AboutDialog() { delete ui; }
}  // namespace shutter
