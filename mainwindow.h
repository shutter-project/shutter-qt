#ifndef SHUTTERMAINWINDOW_H
#define SHUTTERMAINWINDOW_H

#include <QMainWindow>

namespace shutter {
namespace Ui {
class MainWindow;
}

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
