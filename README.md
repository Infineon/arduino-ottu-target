# arduino-ottu-target

This library adapts [`ottu-target`](https://github.com/Infineon/ottu-target) for Arduino, enabling automated testing
directly on embedded devices. 

Find more all usage examples in the [`examples/`](examples/) directory, and the rest in the core `ottu-target` repository.


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

## License

This project is distributed under the [MIT License](LICENSE.md).
