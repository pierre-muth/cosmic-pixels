/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F18346
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

bool localEvent = 0;
bool cosmicEvent = 0;

void INTInterruptHandler(void){
    localEvent = 1;
    cosmicEvent = PORTC < 0xFF;
}

// reverse the bits in a char
uint32_t bitflip(uint8_t b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return (uint32_t)b;
}

void sendSK6812rgbw(uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
    char i;
    
    r = bitflip(r);
    g = bitflip(g);
    b = bitflip(b);
    w = bitflip(w);

    INTCONbits.GIE = 0;
    
    for (i=0; i<8; i++){
        if ((g & 1) == 1) {
            Main_Led_PORT = 1;
            NOP();NOP();NOP();NOP();NOP();
            Main_Led_PORT = 0;
        } else {
            Main_Led_PORT = 1;
            NOP();
            Main_Led_PORT = 0;
        }
        g = g >> 1;
    }
    
    for (i=0; i<8; i++){
        if ((r & 1) == 1) {
            Main_Led_PORT = 1;
            NOP();NOP();NOP();NOP();NOP();
            Main_Led_PORT = 0;
        } else {
            Main_Led_PORT = 1;
            NOP();
            Main_Led_PORT = 0;
        }
        r = r >> 1;
    }
    
    for (i=0; i<8; i++){
        if ((b & 1) == 1) {
            Main_Led_PORT = 1;
            NOP();NOP();NOP();NOP();NOP();
            Main_Led_PORT = 0;
        } else {
            Main_Led_PORT = 1;
            NOP();
            Main_Led_PORT = 0;
        }
        b = b >> 1;
    }
    
    for (i=0; i<8; i++){
        if ((w & 1) == 1) {
            Main_Led_PORT = 1;
            NOP();NOP();NOP();NOP();NOP();
            Main_Led_PORT = 0;
        } else {
            Main_Led_PORT = 1;
            NOP();
            Main_Led_PORT = 0;
        }
        w = w >> 1;
    }
    
    INTCONbits.GIE = 1;
}

void resetSK6812() {
    Main_Led_PORT = 0;
    __delay_us(15);
}

/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
//    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
//    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    INT_SetInterruptHandler(INTInterruptHandler);
    
    uint8_t cosmic_bright = 0;
    
    while (1)
    {
        __delay_ms(10);
        if (localEvent && !cosmicEvent) {
            sendSK6812rgbw((cosmic_bright/4)+100, cosmic_bright, 0x00, 0x00);
            localEvent = false;
        } else if (localEvent && cosmicEvent) {
            cosmic_bright = 150;
            sendSK6812rgbw(cosmic_bright/4, cosmic_bright, 0x00, 0x00);
            localEvent = false;
            cosmicEvent = false;
        } else {
            sendSK6812rgbw(cosmic_bright, cosmic_bright, 0x01, 0x00);
        }
        if (cosmic_bright > 0) cosmic_bright-=3;
        
        b4_Toggle();
        
        resetSK6812();
        
    }
}
/**
 End of File
*/