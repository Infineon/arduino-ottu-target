# arduino-ottu-target

This library adapts [`ottu-target`](https://github.com/Infineon/ottu-target) for Arduino, enabling automated testing
directly on embedded devices. 

Find more all usage examples in the [`examples/`](examples/) directory, and the rest of the documentation in the `ottu-target` repository.

Tests run on the board and report their results over the Arduino `Serial`
interface.

## Install

### Arduino CLI

```sh
arduino-cli lib install ottu-target
```

### Arduino IDE

Open **Tools > Manage Libraries...** (or **Sketch > Include Library > Manage
Libraries...** in older IDE versions), search for **ottu-target**, and select
**Install**.

Install the Arduino core for your board separately. After installing the
library, open an example from **File > Examples > ottu-target**.

## ottu-target library integration

This Arduino adaptation provides a custom `OTTUNITY_RUN()` through
[`ottunity_config.h`](src/ottunity_config.h). It defines the Arduino `setup()`
and `loop()` functions:
`setup()` starts `Serial` at `OTTU_SERIAL_INTF_BAUDRATE`, waits for the serial
connection, prints the OTTU start frame, runs the test suite, and prints the
end frame. Sketches can use `OTTUNITY_RUN()` without defining their own Arduino
entry points.

The OTTU frame settings in `ottu.h` can be overridden at compile time with
`arduino-cli --build-property`. For example, set the baud rate to `9600`,
enable framed output, and add a token to both frame markers:

```sh
arduino-cli compile \
  --fqbn <vendor:architecture:board> \
  --build-property "compiler.cpp.extra_flags=-DOTTU_SERIAL_INTF_BAUDRATE=9600 -DOTTU_FRAMED_OUTPUT_ENABLED=1 -DOTTU_TEST_FRAME_TOKEN=42" \
  path/to/sketch
```

By default, framed output is enabled. Set `OTTU_FRAMED_OUTPUT_ENABLED=0` to
disable the frames, or define `OTTU_TEST_FRAME_TOKEN` to add a build-time token
to the begin and end markers (for example, `42` produces `ottu begin 42` and
`ottu end 42`). `OTTU_SERIAL_INTF_BAUDRATE` defaults to `115200`; override it
with a value such as `9600` to change the baud rate used by `Serial.begin()`.
If the sketch or library code that uses these macros is compiled as C rather
than C++, pass the same definitions through `compiler.c.extra_flags` as well.

## License

This project is distributed under the [MIT License](LICENSE.md).
