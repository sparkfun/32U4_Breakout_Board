/*
   LUFA Library
   Copyright (C) Dean Camera, 2012.

   dean [at] fourwalledcubicle [dot] com
   www.lufa-lib.org
   */

/*
   Copyright 2012  Dean Camera (dean [at] fourwalledcubicle [dot] com)

   Permission to use, copy, modify, distribute, and sell this
   software and its documentation for any purpose is hereby granted
   without fee, provided that the above copyright notice appear in
   all copies and that both that the copyright notice and this
   permission notice and warranty disclaimer appear in supporting
   documentation, and that the name of the author not be used in
   advertising or publicity pertaining to distribution of the
   software without specific, written prior permission.

   The author disclaim all warranties with regard to this
   software, including all implied warranties of merchantability
   and fitness.  In no event shall the author be liable for any
   special, indirect or consequential damages or any damages
   whatsoever resulting from loss of use, data or profits, whether
   in an action of contract, negligence or other tortious action,
   arising out of or in connection with the use or performance of
   this software.
   */

/** \file
 *
 *  Main source file for the VirtualSerial demo. This file contains the main tasks of
 *  the demo and is responsible for the initial application hardware configuration.
 *
 *  Modified by Sparkfun 5/31/12 by Jordan McConnell
 *  The purpose of this to be a simple demo of how to send serial information
 *  between your 32u4 Breakout Board and computer using USB as a virtual COM port.
 *
 *  The first time this is run, Windows will want a driver, point it to the
 *  file: 'LUFA VirtualSerial.inf' in this directory.  Now your board will have
 *  two COM ports associated with your 32u4 board, one for the bootloader, and
 *  one for your applications that involve serial communication to the PC.
 *
 *  Two examples are included.  By default, this program once loaded on the
 *  board will accept information from the computer via USB and the virtual COM
 *  port, put it into a buffer and then send it straight back to the user.
 *
 *  If the default example is commented out and the second is uncommented, a
 *  simple print statement to the computer happens about every couple seconds.
 */

#include "VirtualSerial.h"
#include <util/delay.h>

/** LUFA CDC Class driver interface configuration and state information. This structure is
 *  passed to all CDC Class driver functions, so that multiple instances of the same class
 *  within a device can be differentiated from one another.
 */
USB_ClassInfo_CDC_Device_t VirtualSerial_CDC_Interface =
{
	.Config =
	{
		.ControlInterfaceNumber         = 0,

		.DataINEndpointNumber           = CDC_TX_EPNUM,
		.DataINEndpointSize             = CDC_TXRX_EPSIZE,
		.DataINEndpointDoubleBank       = false,

		.DataOUTEndpointNumber          = CDC_RX_EPNUM,
		.DataOUTEndpointSize            = CDC_TXRX_EPSIZE,
		.DataOUTEndpointDoubleBank      = false,

		.NotificationEndpointNumber     = CDC_NOTIFICATION_EPNUM,
		.NotificationEndpointSize       = CDC_NOTIFICATION_EPSIZE,
		.NotificationEndpointDoubleBank = false,
	},
};

/** Standard file stream for the CDC interface when set up, so that the virtual CDC COM port can be
 *  used like any regular character stream in the C APIs
 */
static FILE USBSerialStream;

volatile char buffer[CDC_TXRX_EPSIZE];


/** Main program entry point. This routine contains the overall program flow, including initial
 *  setup of all components and the main program loop.
 */
int main(void)
{
	char* HelloString  = "Hello from SparkFun. You got it to work, congrats."; // The C style string to send to the computer in example 2
	
	// Count keeps track of # of characters in the buffer for the first example
	// It's used to keep track of milliseconds passed in the second example.
	uint16_t count = 0;

	SetupHardware();

	/* Create a regular character stream for the interface so that it can be used with the stdio.h functions */
	CDC_Device_CreateStream(&VirtualSerial_CDC_Interface, &USBSerialStream);

	LEDs_SetAllLEDs(LEDMASK_USB_NOTREADY);
	sei();

	while(1)
	{

	    // Ex. 1: Check and read the buffer of characters coming from the computer via USB
	    // and then send them straight back.
        if ((count = fread(&buffer,1,CDC_TXRX_EPSIZE,&USBSerialStream)) > 0)
        {
           fwrite(&buffer, 1, count, &USBSerialStream);
        }



        // Ex. 2: The following block of code demonstrates a simple print that is
        // sent about once each couple seconds.  To use uncomment the following
        // section and comment out the section above which is constantly taking
        // user input and putting it back to the screen.
        /*
        count++;
        if(count >=2000)
        {
            count=0;
            fprintf(&USBSerialStream, "%s", HelloString);
            _delay_ms(1);
        }
        */

        // LUFA USB functions necessary for USB/virtual serial communication to work
	    CDC_Device_USBTask(&VirtualSerial_CDC_Interface);
	    USB_USBTask();

    }
}

/** Configures the board hardware and chip peripherals for the demo's functionality. */
void SetupHardware(void)
{
	/* Disable watchdog if enabled by bootloader/fuses */
	MCUSR &= ~(1 << WDRF);
	wdt_disable();

	/* Disable clock division */
	clock_prescale_set(clock_div_1);

	// Initialize char buffer to all zeroes
	for(uint8_t i=0; i < CDC_TXRX_EPSIZE; i++)
	{
	    buffer[i]=0;
	}

	/* Hardware Initialization */
	LEDs_Init();
	USB_Init();
}

/** Event handler for the library USB Connection event. */
void EVENT_USB_Device_Connect(void)
{
	LEDs_SetAllLEDs(LEDMASK_USB_ENUMERATING);
}

/** Event handler for the library USB Disconnection event. */
void EVENT_USB_Device_Disconnect(void)
{
	LEDs_SetAllLEDs(LEDMASK_USB_NOTREADY);
}

/** Event handler for the library USB Configuration Changed event. */
void EVENT_USB_Device_ConfigurationChanged(void)
{
	bool ConfigSuccess = true;

	ConfigSuccess &= CDC_Device_ConfigureEndpoints(&VirtualSerial_CDC_Interface);

	LEDs_SetAllLEDs(ConfigSuccess ? LEDMASK_USB_READY : LEDMASK_USB_ERROR);
}

/** Event handler for the library USB Control Request reception event. */
void EVENT_USB_Device_ControlRequest(void)
{
	CDC_Device_ProcessControlRequest(&VirtualSerial_CDC_Interface);
}

