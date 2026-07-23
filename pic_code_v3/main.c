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

const uint8_t GRADIENT_RED[]   = {0,   4,  50, 100, 255, 255, 255, 255, 255, 255};
const uint8_t GRADIENT_GREEN[] = {0,   0,   0,   0,  20,  90, 120, 180, 190, 190};
const uint8_t GRADIENT_BLUE[]  = {0,   2,   0,   0,   0,   0,   0,  50,  80,  80};
const double GRADIENT_STEP_NUMBER = 9.0; // number of interval in the gradient array
const double GRADIENT_STEP_SIZE = 1.0 / GRADIENT_STEP_NUMBER;
const double DECAY_GRADIENT = 0.005;
bool interrupt_single_event = 0;
bool interrupt_cosmic_event = 0;

void INTInterruptHandler(void) {
    // an event happened here 
    interrupt_single_event = 1;
    // one or more neighbor also registered and event
    interrupt_cosmic_event = PORTC < 0xFF;  
}

void main(void) {
    // initialize the device, in/out, tmr2, pwm5, spi1, dac1...
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // set the interrupt code function
    INT_SetInterruptHandler(INTInterruptHandler);
    // enable SPI module
    SSP1CON1bits.SSPEN = 1;
    
    // set DAC output to max (4.096V)
    DAC1_SetOutput(0b11111);
    
    // variables
    double cosmic_brightness = 0.0;     // brightness value between 0.0 to 1.0
    double localGradientVal = 0.0;      // value in between two gradient points
    double redStart, greenStart, blueStart;
    double redStop, greenStop, blueStop;
    uint8_t red, green, blue;	// final color values
    uint8_t gradientStartIndex = 0;
    uint16_t loopCount = 0;
    uint16_t event_counter = 0;  // Number of event per ~16s, used to adjust DAC output
    
    // main loop
    while (1) {
        __delay_ms(10);
        
        // For debug: forced events 
//        if (loopCount % 400 == 0){
//            interrupt_single_event = true;
//            interrupt_cosmic_event = false;
//        }
//        if (loopCount % 1200 == 0){
//            interrupt_single_event = true;
//            interrupt_cosmic_event = true;
//        }
        loopCount++;
        
        // do we have a coincidence event or just a single event    
        if (interrupt_single_event && interrupt_cosmic_event) {
            cosmic_brightness = 1.0;
            interrupt_single_event = false;
            interrupt_cosmic_event = false;
            event_counter++;
        } else if (interrupt_single_event && !interrupt_cosmic_event) {
            PWM5_LoadDutyValue(500);    // for a flash on MainLed [0-999]
            interrupt_single_event = false;
            event_counter++;
        } else {
            PWM5_LoadDutyValue(0);
        }
        
        // decay the brightness value
        if (cosmic_brightness > 1.0) cosmic_brightness = 1.0;
        if (cosmic_brightness >= DECAY_GRADIENT) cosmic_brightness -= DECAY_GRADIENT;
        else cosmic_brightness = 0;
        
        // RGB gradient calculation
        gradientStartIndex = (uint8_t)(cosmic_brightness * GRADIENT_STEP_NUMBER);
        localGradientVal = (cosmic_brightness - (gradientStartIndex*GRADIENT_STEP_SIZE))/GRADIENT_STEP_SIZE;
        redStart    = GRADIENT_RED[gradientStartIndex];
        greenStart  = GRADIENT_GREEN[gradientStartIndex];
        blueStart   = GRADIENT_BLUE[gradientStartIndex];
        redStop     = GRADIENT_RED[gradientStartIndex+1];
        greenStop   = GRADIENT_GREEN[gradientStartIndex+1];
        blueStop    = GRADIENT_BLUE[gradientStartIndex+1];
        red     = (uint8_t)(redStart*(1.0-localGradientVal) + redStop*localGradientVal);
		green   = (uint8_t)(greenStart*(1.0-localGradientVal) + greenStop*localGradientVal);
		blue    = (uint8_t)(blueStart*(1.0-localGradientVal) + blueStop*localGradientVal);
        
        // send data to RGB LED APA102
        SPI1_ExchangeByte(0x00);  // start bytes
        SPI1_ExchangeByte(0x00);
        SPI1_ExchangeByte(0x00);
        SPI1_ExchangeByte(0x00);
        SPI1_ExchangeByte(0b11101111); // 1x LED data [111] + brightness[5]
        SPI1_ExchangeByte(blue);  //B
        SPI1_ExchangeByte(green); //G
        SPI1_ExchangeByte(red);   //R
        SPI1_ExchangeByte(0xFF);  // stop bytes
        SPI1_ExchangeByte(0xFF);
        SPI1_ExchangeByte(0xFF);
        SPI1_ExchangeByte(0xFF);
        
        // Timer0 flag (~16 seconds). Check the event count rate and adjust DAC output accordingly 
        if (TMR0IF){
            if (event_counter > 40 && DAC1_GetOutput() < 0b11111) {  // too much events, if DAC not maxed already:
                DAC1_SetOutput(DAC1_GetOutput() +1);  // increase the detection threshold
            }
            if (event_counter < 3 && DAC1_GetOutput() > 0b00111) {  // too few events, if DAC not too low already:
                DAC1_SetOutput(DAC1_GetOutput() -1);  // decrease the detection threshold
            }
            
            TMR0IF = 0;
            event_counter = 0;
            
            // for debug: generate a square signal on Sync_out pin
            Sync_out_Toggle();
        }
    }
}
/**
 End of File
*/
