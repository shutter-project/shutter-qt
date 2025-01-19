#ifndef SHUTTERMAINWINDOW_H
#define SHUTTERMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace shutter {
class MainWindow : public QMainWindow {
	Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private:
  Ui::MainWindow* ui;
};
}  // namespace shutter
#endif // SHUTTERMAINWINDOW_H
