## Introduction to selected z88dk Libraries
This file describes some z88dk compatible libraries.

### time
The implementation of `time.h` aspires to conform with ISO/IEC 9899 (C90). However, due to limitations of the target processor and the nature of its development environment, a practical implementation must of necessity deviate from the standard.

### FatFs
FatFs is a generic FAT/exFAT filesystem module for small embedded systems. The FatFs module is written in compliance with ANSI C (C89) and completely separated from the disk I/O layer. Therefore it is independent of the platform. It can be incorporated into small microcontrollers with limited resource, such as 8051, PIC, AVR, ARM, Z80, RX and etc.

### diskio_hbios
FatFs is a generic FAT/exFAT filesystem module for small embedded systems. The FatFs module is written in compliance with ANSI C (C89) and completely separated from the disk I/O layer. This is the disk I/O layer for hbios, using hbios calls as implemented in ROMWBW.

### diskio_sd
FatFs is a generic FAT/exFAT filesystem module for small embedded systems. The FatFs module is written in compliance with ANSI C (C89) and completely separated from the disk I/O layer. This is the disk I/O layer for the SC126 and SC130, using SD interface as implemented in z88dk for the z180 CSIO.

### i2c_lcd
This library is build for I2C_LCD12864 from Seeed Studio - Sparking. Please do not use this library on any other devices, that could cause unpredictable damage to an unknown device.

### ft80x
This library is build for FT801 EVE display, using I2C. Hardware tested is 4D Systems ADAM and EVE platform (with modification to convert from SPI). Please do not use this library on any other devices, that could cause unpredictable damage to an unknown device.

### th02
This is a multifunctional sensor that gives you temperature and relative humidity information at the same time. It utilizes a TH02 sensor that can meet measurement needs of general purposes. It provides reliable readings when environment humidity condition inbetween 0-80% RH, and temperature condition inbetween 0-70°C, covering needs in most home and daily applications that don't contain extreme conditions.

### z88dk-FreeRTOS
TBA

## Preparation
The libraries can be compiled using the following command lines in Linux, with the `+target` modified to be relevant to your machine, from the relevant library sub-directory. e.g. for any `library`.

```bash
cd ~/library/source
zcc +target -lm -x -SO3 -clib=sdcc_ix --opt-code-size --allow-unsafe-read --max-allocs-per-node400000 @library.lst -o library
mv library.lib ../target/lib/newlib/sdcc_ix
zcc +target -lm -x -SO3 -clib=sdcc_iy --opt-code-size --allow-unsafe-read --max-allocs-per-node400000 @library.lst -o library
mv library.lib ../target/lib/newlib/sdcc_iy
```
The resulting `library.lib` file should be moved to `~/library/target/lib/newlib/sdcc_ix` or `~/library/target/lib/newlib/sdcc_iy` respectively, as noted above.

Then, the `z88dk-lib` function is used to install for the desired target. e.g. for the time library on the yaz180 machine.

```bash
cd ..
z88dk-lib +yaz180 time
```

Some further examples of `z88dk-lib` usage.

+ libraries list help
```bash
z88dk-lib
```
+ list 3rd party libraries already installed for the zx target
```bash
z88dk-lib +zx
```
+ remove the `libname1` `libname2` ... libraries from the zx target, -f for no nagging about deleting files.
```bash
z88dk-lib +zx -r -f libname1 libname2 ...
```

## Usage
Once installed, the libraries can be linked against on the compile line by adding `-llib/target/library` and the include file can be found with `#include <lib/target/library.h>`.
