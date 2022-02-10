# platform-qemu-mps2-an386

Support files for building application to run on the "QEMU mps2-an386"
emulated board.

Since the run-time refers to diag-trace, local copies of those packages,
but with the trace code disabled, is provided locally in  `dependencies`.

In addition, a few support files, with minimal content, are added:

- `include/micro-os-plus/config.h`
- `include/micro-os-plus/platform.h`
- `src/initialize-hardware.cpp`
- `src/interrupt-handlers.cpp`
