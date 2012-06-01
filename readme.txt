Files for Sparkfun's 32u4 Breakout Board

This directory contains the bootloader and example source files for
Sparkfun's 32u4 Breakout board. Both were built on WinXP sp3 with
WinAVR-20100110 and AVRDUDE 5.10.

The bootloader is a modified LUFA-120219 CDC bootloader.

The bootloader directory contains the source and hex file for the bootloader
that ships with this board.  When you first plug in the board to a Windows
machine, it will ask you for a driver.  Point it to the following directory:
\SFE_32U4_Breakout_Board\Bootloaders\CDC
It will find the driver file (LUFA CDC Bootloader.inf) there.

Once your machine recognizes the Virtual COM port, you're ready to take a
look at the examples and try uploading them to your board. See the readme in
the examples directory for more information.

Before you can build any projects, you'll need to download and install
WinAVR if you're using Windows. Found here:
http://sourceforge.net/projects/winavr/files/

If you're using Linux, you'll need the following packages:
- avr-gcc: A port of the GNU C Compiler to the AVR Architecture
- avr-binutils: Converts the object code into AVR-readable hex files
- avr-libc: AVR Library for stuff like accessing and manipulating registers
- avrdude: The software that actually drives the physical programming

More examples will be available in the future.

If you have questions, feel free to leave a comment on the 32u4 Breakout
Board product page and I'll try to answer it and continue to add important
information to the readme files in the github repository.

Enjoy!
