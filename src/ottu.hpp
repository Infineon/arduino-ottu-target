#ifndef __ARDUINO_OTTU_H
#define __ARDUINO_OTTU_H

#include "ottunity/ottunity.h"

#define OTTUNITY_RUN() \
    void setup() { \
        Serial.begin(115200); \
        while (!Serial) { ; } \
        \
        OTTUNITY_SUITE_RUNNER(); \
    } \
    \
    void loop() { }

#endif /* __ARDUINO_OTTU_H */