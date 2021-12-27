#include "areas/grove04.h"

#include "util/compiler.h"

Grove04::Grove04() noexcept {
    clouds.setZ(10.0);
}

void
Grove04::onLoad() noexcept {
    clouds.createRandomCloud(*this);

#define SECOND 1000
    clouds.createCloudsRegularly(*this, 20 * SECOND, 30 * SECOND);
}
