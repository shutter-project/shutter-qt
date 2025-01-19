#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

namespace shutter {
namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog {
	Q_OBJECT

  public:
	explicit AboutDialog(QWidget* parent = nullptr);
	~AboutDialog();

  private:
	Ui::AboutDialog* ui;
};
}  // namespace shutter

#endif  // ABOUTDIALOG_H
