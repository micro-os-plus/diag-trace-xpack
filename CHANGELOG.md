# Change & release log

Releases in reverse chronological order.

Please check
[GitHub](https://github.com/micro-os-plus/diag-trace-xpack/issues/)
and close existing issues and pull requests.

## 2026-07-14

* v5.0.0 published on npmjs.com
* v5.0.0 prepared
* 52d78fc website update
* 5a43a00 copilot-instructions.md update

## 2026-07-09

* c5dfe47 website api update

## 2026-07-07

* 2240229 re-generate website commons
* f7a698b re-generate tests commons
* 45d6b05 re-generate top commons
* 50dad8e doxygen adjustments
* 4b83ca2 cleanup namespace micro_os_plus
* 0ce71d6 add @file section
* 9fd9d11 reorder cosmetics
* 13aa5ba remove // #pragma
* 9fc8c2a trace-c-api.cpp size_t

## 2026-07-04

* 40b9384 fix doxygen after review
* e54e811 comments and doxygen updates
* c9662a2 pragma cleanups
* 1b3ba5f add noexcept to concepts
* 7c818ff std::strlen
* 91dedd1 doxygen @details
* 9e0dfc4 check MICRO_OS_PLUS_TRACE in trace-defines.h
* 1b29a6b fix target_link_cross_test_libraries
* 04badc1 include inlines in each header
* 61b2cf7 check MICRO_OS_PLUS_DIAG_TRACE_ENABLED
* d250fbc xcdl-package.jsonc cosmetics
* eac3983 package.json cosmetics
* a10aeb8 re-generate tests commons

## 2026-07-03

* d3f5b00 clang-format.sh add tests/platforms
* 564a042 re-format config.h
* 929fbc5 rename MICRO_OS_PLUS_DIAG_TRACE_PRINTF_BUFFER_ARRAY_SIZE_INTEGER
* 454f4ce cleanups
* bc99b4c meson updates
* 7e7d4ce fix project url to github.io
* 48732f0 tests cmake move MICRO_OS_PLUS_TRACE to common
* 153fd46 tests meson updates
* d065a23 tests no-trace clean-ups
* b37508b tests cmake updates

## 2026-06-20

* f9b6e6f cmake tests functional
* 4e68353 templates add EXCLUDE_FROM_ALL for libraries
* 34d9030 split c/cpp files

## 2026-06-19

* 620e96a function template version

## 2026-06-18

* 48888d3 add tests/config/tests-templates.json
* eb9d342 tests/sources add sub-folders
* 68fa4f3 tests/platforms rename platform-library
* e654264 re-generate top & xcdl export

## 2026-06-17

* fe65447 re-work with #if __has_include

## 2026-06-12

* d5c5444 re-generate top commons

## 2026-06-11

* c98f480 prefer project-config.h

## 2026-06-06

* 4e8b062 use __has_include(<micro-os-plus/config.h>)

## 2026-04-11

* 9023fac 4.2.3
* b39c53b preapre 4.2.3
* e0fd16a #7: clip the output of vsnprintf()

## 2026-03-09

* c025dce test-ci.yml updates

## 2026-03-08

* 6425752 test-ci.yml updates
* ff2394f package*.json bump deps
* 1a842f3 copyright 2026 updates

## 2025-11-19

* fbac5fd --prefix
* f6e3ab5 4.2.2
* b284053 prepare v4.2.2
* 9e486a7 trace.cpp silence warnings

## 2025-10-07

* 3be1463 update copyright notices

## 2025-03-21

* 79af703 tests: clean-ups
* 2436191 update package-lock.json
* e71b51a re-generate workflows
* 198b444 tests: remove old platforms
* ecbc237 meson.build: add *compile_c*_args
* 198c707 tests: all platforms functional

## 2025-03-20

* c82b51d tests: update to use the testing namespace
* 4a26a72 library: use separate testing namespace
* 1a9d9f2 tests/package.json updates
* da87d4a package.json cosmetics
* 833c4c2 tests: platforms/native updates
* 50232ed tests: silence warnings, add asserts
* ca4a8af tests cmake & meson updates
* f92a26b silence -Wpre-c++17-compat
* 8e8709f add MICRO_OS_PLUS_TRACE_TESTING

## 2025-03-18

* 0ae4299 initial website content
* 19142bf trace.h: re-work doxygen
* e81e6c6 README update
* c6de55f rename xcdl.json
* 0db98d3 re-generate top

## 2023-11-28

* 3f2248a README updates
* 626fd32 package.json: cosmetise scripts

## 2023-10-19

* a98654a tests/native/config.h: update *_BUFFER_ARRAY_SIZE

## 2023-10-18

* 3a7dc30 4.2.1
* f0d346e prepare v4.2.1
* 944ac54 README update
* 4244738 package.json: description cosmetics

## 2023-10-17

* badfbac trace.cpp: silence warnings

## 2023-10-12

* 2bdb99c ci.yml: non-sudo npm install

## 2023-07-14

* 681d474 ci.yml: xpm 0.16.2
* d9ca5ef README updates
* 9deb141 tests/CMakeLists.txt: cosmetics
* 31e01f1 package.json: cosmetise urls
* 1c66236 package.json: minXpm 0.16.2

## 2023-06-04

* 0110e7d update for xpacks/@scope/name
* 228dec6 cmake: add dependencies.cmake
* f493850 package.json: build-helper-xpack#xpack-develop
* 39177ab remove --quiet
* 219e896 ci.yml: bump xpm

## 2023-06-03

* f461e84 lower case ci.yml
* cf69dbf package.json min 0.16.0
* 468c3f1 package.json min 0.16.0
* 9ea9ede lower case ci.yml

## 2023-05-08

* a3ae928 CI.yml: re-enable windows
* 84f42a2 CI.yml: bump deps, node 18
* d3693f7 .npmignore update
* 52238fb READMEs updates
* 3b10890 README updates
* 8567d73 README update
* 5255082 meson.build cosmetics

## 2022-08-16

* 31e0505 package.json min 0.14.0 & defaults

## 2022-08-04

* 650c8d5 4.2.0
* 4a22166 prepare v4.2.0
* d560e9b .vscode/settings.json: ignoreWords
* 498dcd8 rename MICRO_OS_PLUS_INTEGER_TRACE_SEMIHOSTING_BUFFER_ARRAY_SIZE
* 4e018fc tests/cross.ini: add link to cpu-families

## 2022-08-03

* f3607fb .vscode/settings.json: cmake.ignoreCMakeListsMissing
* 1bd6ad0 .vscode/settings.json: makefile.configureOnOpen

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
