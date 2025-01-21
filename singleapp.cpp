#include "singleapp.h"

namespace shutter {

SingleApp::SingleApp(QObject* parent) : QObject{parent} {}

void SingleApp::raise() { emit raised(); }

}  // namespace shutter
