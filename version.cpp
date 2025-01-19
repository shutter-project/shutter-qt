#include "version.h"

#include "gen_version.h"

namespace shutter {
const char* getVersion() { return CMAKE_PROJECT_VERSION; }
}  // namespace shutter
