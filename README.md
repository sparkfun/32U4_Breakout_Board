ATMEGA32U4 Breakout Board
=========================

[![ATMEGA32U4 Breakout](https://dlnmh9ip6v2uc.cloudfront.net/images/products/1/1/1/1/7/11117-01a_i_ma.jpg) 
*ATMEGA32U4 Breakout Board (DEV-11117)*](https://www.sparkfun.com/products/11117)

This breakout board is designed for folks who would like to program outside of the Arduino IDE. THe board
comes preloaded with the LUFA CDC bootloader, allowing code to be built in WinAVR and program the board over USB
using AVRDUDE. 

Repository Contents
-------------------
* **/Bootloaders** - CDC bootloader and instructions for installation
* **/Examples** - Example code for the board
* **/Hardware** - All Eagle design files (.brd, .sch)
* **/LUFA** - Instructions for setting up the LUFA bootloader


License Information
-------------------
The hardware is released under [Creative Commons Share-alike 3.0](http://creativecommons.org/licenses/by-sa/3.0/).  
All other code is open source so please feel free to do anything you want with it; you buy me a beer if you use this and we meet someday ([Beerware license](http://en.wikipedia.org/wiki/Beerware)).

Notes for Installation
----------------------
This directory contains the bootloader and example source files for
Sparkfun's 32u4 Breakout board. Both were built on WinXP sp3 with
WinAVR-20100110 and AVRDUDE 5.10.

The bootloader is a modified LUFA-130303 CDC bootloader.

The bootloader directory contains the source and hex file for the bootloader
that ships with this board.  When you first plug in the board to a Windows
machine, it will ask you for a driver.  Point it to the following directory:
\SFE_32U4_Breakout_Board\Bootloaders\CDC
It will find the driver file (LUFA CDC Bootloader.inf) there.

Once your machine recognizes the Virtual COM port, you're ready to take a
look at the examples and try uploading them to your board. See the readme in
the examples directory for more information.

Before you can build any projects, you'll need to download and install
WinAVR if you're using Windows. It can be found [here](http://sourceforge.net/projects/winavr/files/). 

Linux Users
-----------
You will need to install the following packages:
* **avr-gcc** - A port of the GNU C compiler to the AVR Architecture
* **avr-binutils** - Converts the object code into AVR-readable hex files
* **avr-libc** - AVR Library for stuff like accessing and manipulating registers
* **avrdude** - The software that actually drives the physical programming