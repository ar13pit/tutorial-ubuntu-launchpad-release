# tutorial-ubuntu-launchpad-release
[![Build Status](https://travis-ci.com/ar13pit/tutorial-ubuntu-launchpad-release.svg?branch=master)](https://travis-ci.com/ar13pit/tutorial-ubuntu-launchpad-release)

A tutorial on how to create a `.deb` package and release it on Ubuntu Launchpad for C++ and Python projects that are
either self contained or dependent on other libraries

## Build and test locally
### Build library
Clone the repository and in the root directory execute
```bash
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=../install ..
cmake --build . --target install
```

For system install remove the option `-DCMAKE_INSTALL_PREFIX`
### Test library
In the root of the repository execute
```bash
cd test
mkdir build
cd build
cmake ..
cmake --build .
```
