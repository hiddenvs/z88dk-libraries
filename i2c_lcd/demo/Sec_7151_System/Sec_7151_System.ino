#include <Wire.h>
#include <I2C_LCD.h>
I2C_LCD LCD;
uint8_t I2C_LCD_ADDRESS = 0x51; //Device address setting, default: 0x51
void setup(void)
{
    Wire.begin();           //I2C controler init.
}

void loop(void)
{
    LCD.CleanAll(WHITE);    //Erase all.
    delay(1000);            //Delay for 1s.
    
    //Set the font, character address update mode, display mode.
    //FM_ANL_AAA: FM_AutoNewLine_AutoAddrAdd
    LCD.FontModeConf(Font_10x20, FM_ANL_AAA, BLACK_BAC);
    LCD.DispStringAt("Sparking", 0, 20);    //Display string.
    delay(2000);            //Delay for 2s.

    //Set the contrast to 12, and save the configuration to ram.
    LCD.ContrastConf(LOAD_TO_RAM, 12);
    
    while(1); //Wait for ever.
}

