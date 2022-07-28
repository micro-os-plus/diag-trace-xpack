# Change & release log

Releases in reverse chronological order.

Please check
[GitHub](https://github.com/micro-os-plus/diag-trace-xpack/issues/)
and close existing issues and pull requests.

## 2022-07-28

* fd63c99 CI.yml: try to ignore tags
* 50dcdd2 trace.h: silence clang compat
* 4.1.0
* 008892b semihosting.h comments cosmetics
* ab7e57a startup.cpp: message cosmetics (KiB)
* e51fa46 trace.h: namespace cosmetics
* 909fa41 #6: puts() with optional string in C++

## 2022-07-26

* 3016e30 trace.cpp: silence -Wc++98-c++11-c++14-compat

## 2022-07-25

* fb40646 trace.cpp: namespaces cosmetics
* c1f0807 #5: rename MICRO_OS_PLUS_INTEGER_TRACE_PRINTF_BUFFER_ARRAY_SIZE
* 23f0720 CMake update error message
* 726786d remove dependencies READMEs
* 9292f88 package.json minimumXpmRequired
* daa1f49 add preliminary xpack.json

## 2022-07-12

* ff16726 CMake: xpack_display_greetings() with arg
* c3131b3 package.json: bump deps

## 2022-06-04

* 445c14e update for arm-cmsis-core

## 2022-06-03

* aeebff5 tests: update for sections-flash.ld

## 2022-05-24

* 55edc76 GETCMDLINE

## 2022-04-03

* v3.0.1 maintenance release
* update for latest tests

## 2022-03-29

* 840bd8a package.json add clang13
* 18ebec5 updates from build-tools/templates
* d8faaa3 unit-test: update for expect() <<

## 2022-03-22

* 4cf0770 unit-test.cpp: update for new micro-test-plus
* 9c459f5 update from new template, new micro-test-plus
* 4514960 CI.yml: --quiet

## 2022-02-13

* v3.0.0

## 2022-02-12

* add support to run all tests on all platforms

## 2022-02-10

* v2.4.2
* 24e405e .c* include <micro-os-plus/config.h>
* 2819b94 package.json: bump build-helper
* c290a9c add platform-qemu-mps2-an386 & tests
* bf83676 add most test sources

## 2022-02-09

* f415f88 MICRO_OS_PLUS_INCLUDE_CONFIG_H
* e83560f rework cmake & meson globals & native

## 2022-02-08

* 384d5b4 CI.yml: update native tests
* 468bc23 tests: update cmake & meson configs
* 20b8a06 tests: add platform native
* 8e53b7f add tests sources
* 14aada4 add tests cmake & meson globals
* d962829 trace.cpp: disable default write()
* a9ada12 trace.cpp: empty block without `;`
* b8af835 trace.cpp: remove `__attribute__ ((weak))`
* a76a829 use MICRO_OS_PLUS_HAS_CONFIG_H
* fb58146 rename MICRO_OS_PLUS_TRACE

## 2022-02-05

* v2.4.1
* b9c900b move meson_options.txt to tests

## 2022-02-04

* v2.4.0
* 55ee3b5 cmake: add xpack_display_target_lists

## 2022-02-03

* 81c0475 cmake update for interface

## 2022-02-02

* 463d34c add meson support

## 2022-01-28

* 1140aa6 rework CMake, top config, no sources

## 2022-01-26

* v2.3.0
* rework CMake

## 2022-01-02

* v2.2.4
* bump deps
* v2.2.3 (tests fail)

## 2021-03-13

* v2.2.2
* fix warnings
* remove -Werror

* v2.2.1
* add #define trace_flush

## 2021-03-11

* v2.2.0
* [#4] - make the C API consistent
* add tests (running native on macOS/Linux)
* add CI via GitHub Actions

## 2021-03-09

* v2.1.0
* [#3] - add a third param to dump_args()
* fix/silence warnings

## 2021-03-01

* v2.0.0

## 2021-02-28

* rename micro_os_plus

## 2021-02-04

* v1.1.0
* first restructured release

## 2020-09-19

* v1.0.7
* [#1] Remove non-portable aliases from C to C++

## 2018-04-16

* v1.0.6
* move deps back to npm
* update README developer info

## 2018-01-25

* v1.0.5
* cosmetics

## 2018-01-24

* v1.0.4
* reformat

## 2018-01-09

* v1.0.3
* README updates

## 2017-10-04

* v1.0.2
* package.json clean-ups
* add CHANGELOG.md

## 2017-09-04

* v1.0.1
* initial version, copied from µOS++.
