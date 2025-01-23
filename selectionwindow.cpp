#include "selectionwindow.h"

#include <QApplication>
#include <QKeyEvent>
#include <QPixmap>
#include <QScreen>

namespace shutter {

SelectionWindow::SelectionWindow() : QGraphicsView() {
	m_pix = qApp->primaryScreen()->grabWindow();
	m_scene = new QGraphicsScene(this);
	setScene(m_scene);
	m_scene->addPixmap(m_pix);
	// this is not exactly what we want, but good enough for prototype
	setDragMode(QGraphicsView::RubberBandDrag);
}

void SelectionWindow::keyPressEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key_Escape) {
		close();
	} else {
		QGraphicsView::keyPressEvent(event);
	}
}

void SelectionWindow::mouseReleaseEvent(QMouseEvent* event) {
	m_pix = QPixmap::fromImage(m_pix.toImage().copy(rubberBandRect()));
	setDragMode(DragMode::NoDrag);
	m_scene->clear();
	m_scene->addPixmap(m_pix);
	showNormal();
	resize(m_pix.size());
	QGraphicsView::mouseReleaseEvent(event);
}

}  // namespace shutter
