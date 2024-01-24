#! /usr/bin/bash

SCRIPT_DIRECTORY=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

BUILD_DIRECTORY=$SCRIPT_DIRECTORY/build

sudo avrdude -c wiring -p m2560 -P /dev/ttyACM0 -U flash:w:$BUILD_DIRECTORY/avr-example-atmega2560.hex:i -l $BUILD_DIRECTORY/avrdude.log -v -D -b 115200
if [[ "$?" == "0" ]]; then
    echo "Flash succeeded!"
else
    echo "Flash failed..."
fi
