#ifndef SHUTTERMAINWINDOW_H
#define SHUTTERMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class ShutterMainWindow;
}
QT_END_NAMESPACE

class ShutterMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ShutterMainWindow(QWidget *parent = nullptr);
    ~ShutterMainWindow();

private:
    Ui::ShutterMainWindow *ui;
};
#endif // SHUTTERMAINWINDOW_H
