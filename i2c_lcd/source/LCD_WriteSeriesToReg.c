/******************************************************************************
  I2C_LCD.cpp - I2C_LCD library Version 1.11
  Copyright (C), 2015, Sparking Work Space. All right reserved.

 ******************************************************************************

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is build for I2C_LCD12864. Please do not use this library on
  any other devices, that could cause unpredictable damage to the unknow device.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

*******************************************************************************/

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <arch/yaz180.h>
#include <arch/yaz180/i2c.h>

#include "i2c_lcd.h"

/**************************************************************
        Write multiple bytes to device register.
***************************************************************/

void LCD_WriteSeriesToReg(enum LCD_RegAddress regAddr, uint8_t *buf, uint16_t length)
{
    static uint8_t writeBuffer[I2C_TX_SENTENCE+1];
    static uint8_t *bufIndex;

    writeBuffer[0] = (uint8_t)regAddr;
    bufIndex = buf;

    while( length/I2C_TX_SENTENCE )
    {
        i2c_available( LCD_Port );
        memcpy(&writeBuffer[1], bufIndex, I2C_TX_SENTENCE); // do buffer copy only after some delay
        i2c_write( LCD_Port, LCD_ADDRESS, writeBuffer, I2C_TX_SENTENCE+1, I2C_RESTART|I2C_MODE_BUFFER );
        bufIndex+=I2C_TX_SENTENCE;
        length-=I2C_TX_SENTENCE;
    }

    if( length%I2C_TX_SENTENCE )
    {
        i2c_available( LCD_Port ); 
        memcpy(&writeBuffer[1], bufIndex, length);          // do buffer copy only after some delay
        i2c_write( LCD_Port, LCD_ADDRESS, writeBuffer, (uint8_t)(length+1), I2C_STOP|I2C_MODE_BUFFER );
    }
    else
    {
        i2c_write( LCD_Port, LCD_ADDRESS, writeBuffer, 1, I2C_STOP|I2C_MODE_BUFFER );
    }
}

