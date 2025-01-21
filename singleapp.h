#ifndef SINGLEAPP_H
#define SINGLEAPP_H

#include <QObject>

namespace shutter {

class SingleApp : public QObject {
	Q_OBJECT
  public:
	explicit SingleApp(QObject* parent = nullptr);

  signals:
	void raised();

  public slots:
	void raise();
};

}  // namespace shutter

#endif  // SINGLEAPP_H
