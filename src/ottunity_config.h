#ifndef OTTUNITY_ARDUINO_CONFIG_H
#define OTTUNITY_ARDUINO_CONFIG_H

#include "ottu.h"

#define OTTU_TEST_FRAME_START_PRINT() Serial.println(OTTU_TEST_FRAME_START)
#define OTTU_TEST_FRAME_END_PRINT() Serial.println(OTTU_TEST_FRAME_END)

#define OTTUNITY_RUN() \
    void setup() { \
        Serial.begin(OTTU_SERIAL_INTF_BAUDRATE); \
        while (!Serial) { ; } \
        \
        OTTU_TEST_FRAME_START_PRINT(); \
        OTTUNITY_SUITE_RUNNER(); \
        OTTU_TEST_FRAME_END_PRINT(); \
    } \
    \
    void loop() { }

#endif /* OTTUNITY_ARDUINO_CONFIG_H */
