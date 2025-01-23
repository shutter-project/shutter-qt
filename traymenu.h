#ifndef TRAYMENU_H
#define TRAYMENU_H

#include <QMenu>
#include <QWidget>

namespace shutter {

namespace Ui {
class TrayMenu;
}

class TrayMenu : public QMenu {
	Q_OBJECT

  public:
	explicit TrayMenu(QWidget* parent = nullptr);
	~TrayMenu();

  private:
	Ui::TrayMenu* ui;
};

}  // namespace shutter
#endif  // TRAYMENU_H
