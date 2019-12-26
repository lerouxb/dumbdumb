DumbDumb Terminal
===

A little smart hardware serial terminal for use with REPLs like MicroPython in the form of a Feather Wing.


Directory structure
---

### cpp

platform.io and arduino stm32-core based firmware for the stm32g071r8. Scans the keyboard matrix, handles the LCD. Reads and writes over serial. Understands a small subset of VT100 terminal functionality. Just enough to fully support MicroPython's readline REPL.

### node

Some node.js based code to parse, modify and format KiCAD's PCB file format which is some variant of LISP. Contains a script that uses all of that to modify a pcb file to layout the keyboard's buttons. A lot more convenient for making changes to the button positioning than moving each of them around manually in KiCAD's interface every time I want to make changes to the layout.

### pcb

KiCAD files for the PCB. Includes tons of custom symbols and parts.

### py

The dupterm code for the esp32 port of MicroPython to duplicate the REPL on UART 2 which is the one that's exposed by the Adafruit Huzzah32 Feather's RX and TX pins. ie. the ones that are connected to DumbDumb's STM32 microcontroller when you plug the Feather in.
