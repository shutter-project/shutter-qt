#ifndef SELECTIONWINDOW_H
#define SELECTIONWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>

namespace shutter {

class SelectionWindow : public QGraphicsView {
	Q_OBJECT
  public:
	explicit SelectionWindow();

	void keyPressEvent(QKeyEvent*) override;
	void mouseReleaseEvent(QMouseEvent*) override;

  signals:

  private:
	QGraphicsScene* m_scene;
	QPixmap m_pix;
};

}  // namespace shutter

#endif  // SELECTIONWINDOW_H
