
                   _   _ _ ___ _
                  | | | | | __/ \
                  | |_| U | _| o | - The Lightweight USB
                  |___|___|_||_n_|    Framework for AVRs
                =========================================
                          Written by Dean Camera
                  dean [at] fourwalledcubicle [dot] com

                         http://www.lufa-lib.org
                =========================================

               LUFA is donation supported. To support LUFA,
             please donate at http://www.lufa-lib.org/donate

                For Commercial Licensing information, see
                     http://www.lufa-lib.org/license

Notes from SparkFun:

In order to compile the modified LUFA bootloader, or the Virtual Serial
example for your Sparkfun 32u4 Breakout Board, follow these instructions:

1. Download the LUFA Project, version 120219

Visit http://www.lufa-lib.org, then download LUFA-120219.zip

Alternatively, use the following official link to the file:
lufa-lib.googlecode.com/files/LUFA-120219.zip

2. Extract the zip file somewhere on your computer.

3. Copy the contents of the 'LUFA' folder from the zip to this folder.

The folder should be in the main directory:
\LUFA-120219\LUFA

Copy everything in that folder to this one where this readme resides:
\SFE_32U4_Breakout_Board\LUFA

4. ???

5. Profit!

You can now compile the Sparkfun modified LUFA bootloader and the Virtual
Serial demo found in the following locations respectively:
\SFE_32U4_Breakout_Board\Bootloaders\CDC
\SFE_32U4_Breakout_Board\Examples\Sparkfun-VirtualSerial

Enjoy!!





Also, a note about other examples included with the LUFA download:

LUFA includes all sorts of other examples too but they need their makefiles 
to be customized to work for the 32u4 processor and their driver files 
(.inf files and Descriptors.c) to be customized for Sparkfun's 32u4 Breakout
Board. More specifically, you will have to change the VID and PID in those 
files for them to work with this specific board, so just a heads up.
