// Copyright (c) 2014, Joe Krachey
// All rights reserved.
//
// Redistribution and use in binary form, with or without modification, 
// are permitted provided that the following conditions are met:
//
// 1. Redistributions in binary form must reproduce the above copyright 
//    notice, this list of conditions and the following disclaimer in 
//    the documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

//*****************************************************************************
// main.c
// Author: jkrachey@wisc.edu
//*****************************************************************************
#include <stdio.h>
#include <stdint.h>
#include <string.h>


#include "TM4C123.h"
#include "boardUtil.h"
#include "drv8833.h"


//*****************************************************************************
// Global Variables
//*****************************************************************************

volatile bool alert1s;
  
//*****************************************************************************
//*****************************************************************************
void initializeBoard(void)
{
  DisableInterrupts();
  serialDebugInit();
	drv8833_gpioInit();
  EnableInterrupts();
	// Every 1s assuming 50MHz clk
	SysTick_Config(50000000);
}


//*****************************************************************************
//*****************************************************************************
int 
main(void)
{

  
  initializeBoard();

  uartTxPoll(UART0_BASE, "\n\r");
  uartTxPoll(UART0_BASE,"**************************************\n\r");
  uartTxPoll(UART0_BASE,"* ECE315 Default Project\n\r");
  uartTxPoll(UART0_BASE,"**************************************\n\r");
  
	
	uint8_t medium_speed = 0x7F;
	uint8_t off = 0x00;
	
	// Forward 2 seconds,
	drv8833_leftForward(medium_speed);
	drv8833_rightForward(medium_speed);
	while(!alert1s){}	// wait 1s
	while(!alert1s){} // wait 1s
	drv8833_leftForward(off);
	drv8833_rightForward(off);
		
	// backward 2 seconds
	drv8833_leftReverse(medium_speed);
	drv8833_rightReverse(medium_speed);
	while(!alert1s){}	// wait 1s
	while(!alert1s){} // wait 1s
	drv8833_leftReverse(off);
	drv8833_rightReverse(off);
		
	// left 5 seconds
	drv8833_turnLeft(medium_speed);
  while(!alert1s){}	// wait 1s
	while(!alert1s){} // wait 1s
	while(!alert1s){}	// wait 1s
	while(!alert1s){} // wait 1s
	while(!alert1s){}	// wait 1s
	drv8833_turnLeft(off);
		
	// right 5 seconds
	drv8833_turnRight(medium_speed);
  while(!alert1s){}	// wait 1s
	while(!alert1s){} // wait 1s
	while(!alert1s){}	// wait 1s
	while(!alert1s){} // wait 1s
	while(!alert1s){}	// wait 1s
	drv8833_turnRight(off);
  // Infinite Loop
  while(1)
  {
  }
}
