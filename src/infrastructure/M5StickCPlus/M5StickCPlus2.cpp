#include "M5StickCPlus2.h"

using namespace m5;

M5StickCPlus2 StickCP2;

void M5StickCPlus2::begin() {
    M5.begin();
}

void M5StickCPlus2::begin(m5::M5Unified::config_t cfg) {
    M5.begin(cfg);
}
void M5StickCPlus2::update(void) {
    M5.update();
}
