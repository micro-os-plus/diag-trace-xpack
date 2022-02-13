[![license](https://img.shields.io/github/license/micro-os-plus/diag-trace-xpack)](https://github.com/micro-os-plus/diag-trace-xpack/blob/xpack/LICENSE)
[![CI on Push](https://github.com/micro-os-plus/diag-trace-xpack/workflows/CI%20on%20Push/badge.svg)](https://github.com/micro-os-plus/diag-trace-xpack/actions?query=workflow%3A%22CI+on+Push%22)
[![GitHub issues](https://img.shields.io/github/issues/micro-os-plus/diag-trace-xpack.svg)](https://github.com/micro-os-plus/diag-trace-xpack/issues/)
[![GitHub pulls](https://img.shields.io/github/issues-pr/micro-os-plus/diag-trace-xpack.svg)](https://github.com/micro-os-plus/diag-trace-xpack/pulls)

# Maintainer info

## Project repository

The project is hosted on GitHub:

- <https://github.com/micro-os-plus/diag-trace-xpack.git>

To clone the stable branch (`xpack`), run the following commands in a
terminal (on Windows use the _Git Bash_ console):

```sh
rm -rf ~/Work/diag-trace-xpack.git && \
mkdir -p ~/Work && \
git clone \
  https://github.com/micro-os-plus/diag-trace-xpack.git \
  ~/Work/diag-trace-xpack.git
```

For development purposes, clone the `xpack-develop` branch:

```sh
rm -rf ~/Work/diag-trace-xpack.git && \
mkdir -p ~/Work && \
git clone \
  --branch xpack-develop \
  https://github.com/micro-os-plus/diag-trace-xpack.git \
  ~/Work/diag-trace-xpack.git
```

## Prerequisites

A recent [xpm](https://xpack.github.io/xpm/), which is a portable
[Node.js](https://nodejs.org/) command line application.

## Code formatting

Code formatting is done using `clang-format --style=file`, either manually
from a script, or automatically from Visual Studio Code, or the Eclipse
CppStyle plug-in.

Always reformat the source files that were changed.

## Tests

The project is fully tested via GitHub
[Actions](https://github.com/micro-os-plus/micro-test-plus-xpack/actions/);
the **CI** job is automatically triggered on **Push**;
it runs a selection of the tests on GitHub hosted runners.

In addition, it is possible to manually trigger a **test-all** job, that
runs all available builds, on all supported platforms, including Linux Arm
and macOS Apple Silicon.

For this, run the `trigger-workflow-test-all` action before publishing;
see below.

## Manual tests

It is also possible to run the tests manually:

```sh
cd ~Work/diag-trace-xpack.git

xpm run install-all
xpm run test-all
```

## Publish on the npmjs.com server

- select the `xpack-develop` branch
- commit all changes
- update versions in `README.md` and `README-MAINTAINER.md`
- update `CHANGELOG.md`
- commit with a message like _prepare v3.0.0_
- `npm pack` and check the content of the archive, which should list
  only `package.json`, `README.md`, `LICENSE`, `CHANGELOG.md`,
  the sources and CMake/meson files;
  possibly adjust `.npmignore`
- `npm version patch`, `npm version minor`, `npm version major`
- push the `xpack-develop` branch to GitHub
- the `postversion` npm script should also update tags via `git push origin --tags`
- wait for the CI job to complete
  (<https://github.com/micro-os-plus/diag-trace-xpack/actions/workflows/CI.yml>)
- `npm publish --tag next` (use `npm publish --access public` when
  publishing for the first time)

The version is visible at:

- <https://www.npmjs.com/package/@micro-os-plus/diag-trace?activeTab=versions>

## Update the repo

When the package is considered stable:

- with Sourcetree
- merge `xpack-develop` into `xpack`
- push to GitHub
- select `xpack-develop`

## Tag the npm package as `latest`

When the release is considered stable, promote it as `latest`:

- `npm dist-tag ls @micro-os-plus/diag-trace`
- `npm dist-tag add @micro-os-plus/diag-trace@3.0.0 latest`
- `npm dist-tag ls @@micro-os-plus/diag-trace`
