#! /usr/bin/bash

set -e

SCRIPT_DIRECTORY=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

BUILD_DIRECTORY=$SCRIPT_DIRECTORY/build
TOOLCHAIN_DIRECTORY=$SCRIPT_DIRECTORY/toolchain

echo "Clearing build directory"
rm -rf $BUILD_DIRECTORY
mkdir $BUILD_DIRECTORY

echo "Building project"
pushd $BUILD_DIRECTORY > /dev/null
cmake -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN_DIRECTORY/avr/generic.cmake -DAVR_MCU=atmega2560 $SCRIPT_DIRECTORY
make

echo "Finished!!!"
