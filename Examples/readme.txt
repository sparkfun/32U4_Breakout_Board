This directory contains various examples for the SparkFun 32u4 Breakout Board.

All examples can be built using the command line.
Each example includes the appropriate source files and a hex file for quick testing.

To build:
CD (change directory) into the appropriate folder such as:
\SFE_32U4_Breakout_Board\Examples\32U4_digital_output

Type the command 'make' or 'make all' and hit enter.
This builds the project and gives you a .hex file for the microcontroller.
Other build files are also created.

To clean:
To get rid of all build files, use the command 'make clean'.

To program:
You can download a program a hex file to your Sparkfun 32u4 Breakout Board by first
hitting the physical reset button on the device.  This will put the device into
its bootloader state for 7 seconds.  Then use the command 'make program'.


Examples:

1. 32U4 digital output

Important files: main.c, makefile, main.hex

Demonstrates how to output a state, HIGH or LOW, to a pin.

2. 32U4 digital input

Important files: main.c, makefile, main.hex

Demonstrates to to read the input state of a pin, HIGH or LOW.

3. Sparkfun-VirtualSerial

Important files: VirtualSerial.c, makefile, VirtualSerial-ex1.hex, VirtualSerial-ex2.hex

Demonstrates basic functionality of how to send and receive characters from a PC via
USB and a virtual COM port.  Includes two examples.  VirtualSerial.c contains both
examples however, example 1 is active and 2 is commented out by default.  To try 
example 2, uncomment it and comment example 1.  The file has more detail.  If you
want to try either example without building the project, just download the
appropriate hex file to your board.






Notes concerning programming the board:

You will almost certainly have to change the line in the Makefile which specifies
which COM port to talk to. The line looks like this:
AVRDUDE_PORT = COM19
Change 'COM19' to 'COMx' where x is the number of the Sparkfun COM port that shows
up when you connect your 32u4 Breakout to the PC. This is an instruction for Windows,
however you do the same for MAC/Linux only they have fairly different COM port names.
Also, Windows asks for a driver the first time you plug in your board, direct it 
to the .inf file located in the \SFE_32U4_Breakout_Board\Bootloaders\CDC directory 
the first time you plug your board in.

Now that the board is programmed with an application the board will start in the 
user application when turned on.  If you want to reprogram a user application, 
you'll want to run the bootloader again.  To do this just hit the manual reset button
on the board.  Whenever the reset button is pressed, the bootloader runs for 7 
seconds to allow time for programming via avrdude before switching to the user's 
application.  So for programming in the future, just hit reset, type make program 
and hit enter.  The programming will fail if the board isn't in its bootloader state.