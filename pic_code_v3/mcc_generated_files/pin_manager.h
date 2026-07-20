/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F18346
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()              PORTAbits.RA0
#define RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()             do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()           do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode()         do { ANSELAbits.ANSA0 = 1; } while(0)
#define RA0_SetDigitalMode()        do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set Main_Led aliases
#define Main_Led_TRIS                 TRISAbits.TRISA4
#define Main_Led_LAT                  LATAbits.LATA4
#define Main_Led_PORT                 PORTAbits.RA4
#define Main_Led_WPU                  WPUAbits.WPUA4
#define Main_Led_OD                   ODCONAbits.ODCA4
#define Main_Led_ANS                  ANSELAbits.ANSA4
#define Main_Led_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define Main_Led_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define Main_Led_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define Main_Led_GetValue()           PORTAbits.RA4
#define Main_Led_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define Main_Led_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define Main_Led_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define Main_Led_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define Main_Led_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define Main_Led_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define Main_Led_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define Main_Led_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set Second_Led aliases
#define Second_Led_TRIS                 TRISAbits.TRISA5
#define Second_Led_LAT                  LATAbits.LATA5
#define Second_Led_PORT                 PORTAbits.RA5
#define Second_Led_WPU                  WPUAbits.WPUA5
#define Second_Led_OD                   ODCONAbits.ODCA5
#define Second_Led_ANS                  ANSELAbits.ANSA5
#define Second_Led_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define Second_Led_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define Second_Led_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define Second_Led_GetValue()           PORTAbits.RA5
#define Second_Led_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define Second_Led_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define Second_Led_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define Second_Led_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define Second_Led_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define Second_Led_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define Second_Led_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define Second_Led_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set Sync_out aliases
#define Sync_out_TRIS                 TRISBbits.TRISB6
#define Sync_out_LAT                  LATBbits.LATB6
#define Sync_out_PORT                 PORTBbits.RB6
#define Sync_out_WPU                  WPUBbits.WPUB6
#define Sync_out_OD                   ODCONBbits.ODCB6
#define Sync_out_ANS                  ANSELBbits.ANSB6
#define Sync_out_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define Sync_out_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define Sync_out_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define Sync_out_GetValue()           PORTBbits.RB6
#define Sync_out_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define Sync_out_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define Sync_out_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define Sync_out_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define Sync_out_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define Sync_out_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define Sync_out_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define Sync_out_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set Sync_in aliases
#define Sync_in_TRIS                 TRISBbits.TRISB7
#define Sync_in_LAT                  LATBbits.LATB7
#define Sync_in_PORT                 PORTBbits.RB7
#define Sync_in_WPU                  WPUBbits.WPUB7
#define Sync_in_OD                   ODCONBbits.ODCB7
#define Sync_in_ANS                  ANSELBbits.ANSB7
#define Sync_in_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define Sync_in_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define Sync_in_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define Sync_in_GetValue()           PORTBbits.RB7
#define Sync_in_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define Sync_in_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define Sync_in_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define Sync_in_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define Sync_in_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define Sync_in_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define Sync_in_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define Sync_in_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set Trig_in1 aliases
#define Trig_in1_TRIS                 TRISCbits.TRISC0
#define Trig_in1_LAT                  LATCbits.LATC0
#define Trig_in1_PORT                 PORTCbits.RC0
#define Trig_in1_WPU                  WPUCbits.WPUC0
#define Trig_in1_OD                   ODCONCbits.ODCC0
#define Trig_in1_ANS                  ANSELCbits.ANSC0
#define Trig_in1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define Trig_in1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define Trig_in1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define Trig_in1_GetValue()           PORTCbits.RC0
#define Trig_in1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define Trig_in1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define Trig_in1_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define Trig_in1_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define Trig_in1_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define Trig_in1_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define Trig_in1_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define Trig_in1_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set Trig_in2 aliases
#define Trig_in2_TRIS                 TRISCbits.TRISC1
#define Trig_in2_LAT                  LATCbits.LATC1
#define Trig_in2_PORT                 PORTCbits.RC1
#define Trig_in2_WPU                  WPUCbits.WPUC1
#define Trig_in2_OD                   ODCONCbits.ODCC1
#define Trig_in2_ANS                  ANSELCbits.ANSC1
#define Trig_in2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define Trig_in2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define Trig_in2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define Trig_in2_GetValue()           PORTCbits.RC1
#define Trig_in2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define Trig_in2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define Trig_in2_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define Trig_in2_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define Trig_in2_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define Trig_in2_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define Trig_in2_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define Trig_in2_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set Trig_in3 aliases
#define Trig_in3_TRIS                 TRISCbits.TRISC2
#define Trig_in3_LAT                  LATCbits.LATC2
#define Trig_in3_PORT                 PORTCbits.RC2
#define Trig_in3_WPU                  WPUCbits.WPUC2
#define Trig_in3_OD                   ODCONCbits.ODCC2
#define Trig_in3_ANS                  ANSELCbits.ANSC2
#define Trig_in3_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define Trig_in3_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define Trig_in3_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define Trig_in3_GetValue()           PORTCbits.RC2
#define Trig_in3_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define Trig_in3_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define Trig_in3_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define Trig_in3_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define Trig_in3_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define Trig_in3_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define Trig_in3_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define Trig_in3_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set Trig_in4 aliases
#define Trig_in4_TRIS                 TRISCbits.TRISC3
#define Trig_in4_LAT                  LATCbits.LATC3
#define Trig_in4_PORT                 PORTCbits.RC3
#define Trig_in4_WPU                  WPUCbits.WPUC3
#define Trig_in4_OD                   ODCONCbits.ODCC3
#define Trig_in4_ANS                  ANSELCbits.ANSC3
#define Trig_in4_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define Trig_in4_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define Trig_in4_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define Trig_in4_GetValue()           PORTCbits.RC3
#define Trig_in4_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define Trig_in4_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define Trig_in4_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define Trig_in4_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define Trig_in4_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define Trig_in4_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define Trig_in4_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define Trig_in4_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set Trig_in5 aliases
#define Trig_in5_TRIS                 TRISCbits.TRISC4
#define Trig_in5_LAT                  LATCbits.LATC4
#define Trig_in5_PORT                 PORTCbits.RC4
#define Trig_in5_WPU                  WPUCbits.WPUC4
#define Trig_in5_OD                   ODCONCbits.ODCC4
#define Trig_in5_ANS                  ANSELCbits.ANSC4
#define Trig_in5_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define Trig_in5_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define Trig_in5_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define Trig_in5_GetValue()           PORTCbits.RC4
#define Trig_in5_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define Trig_in5_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define Trig_in5_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define Trig_in5_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define Trig_in5_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define Trig_in5_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define Trig_in5_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define Trig_in5_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set Trig_in6 aliases
#define Trig_in6_TRIS                 TRISCbits.TRISC5
#define Trig_in6_LAT                  LATCbits.LATC5
#define Trig_in6_PORT                 PORTCbits.RC5
#define Trig_in6_WPU                  WPUCbits.WPUC5
#define Trig_in6_OD                   ODCONCbits.ODCC5
#define Trig_in6_ANS                  ANSELCbits.ANSC5
#define Trig_in6_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define Trig_in6_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define Trig_in6_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define Trig_in6_GetValue()           PORTCbits.RC5
#define Trig_in6_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define Trig_in6_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define Trig_in6_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define Trig_in6_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define Trig_in6_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define Trig_in6_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define Trig_in6_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define Trig_in6_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set Trig_in7 aliases
#define Trig_in7_TRIS                 TRISCbits.TRISC6
#define Trig_in7_LAT                  LATCbits.LATC6
#define Trig_in7_PORT                 PORTCbits.RC6
#define Trig_in7_WPU                  WPUCbits.WPUC6
#define Trig_in7_OD                   ODCONCbits.ODCC6
#define Trig_in7_ANS                  ANSELCbits.ANSC6
#define Trig_in7_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define Trig_in7_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define Trig_in7_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define Trig_in7_GetValue()           PORTCbits.RC6
#define Trig_in7_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define Trig_in7_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define Trig_in7_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define Trig_in7_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define Trig_in7_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define Trig_in7_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define Trig_in7_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define Trig_in7_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set Trig_in8 aliases
#define Trig_in8_TRIS                 TRISCbits.TRISC7
#define Trig_in8_LAT                  LATCbits.LATC7
#define Trig_in8_PORT                 PORTCbits.RC7
#define Trig_in8_WPU                  WPUCbits.WPUC7
#define Trig_in8_OD                   ODCONCbits.ODCC7
#define Trig_in8_ANS                  ANSELCbits.ANSC7
#define Trig_in8_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define Trig_in8_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define Trig_in8_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define Trig_in8_GetValue()           PORTCbits.RC7
#define Trig_in8_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define Trig_in8_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define Trig_in8_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define Trig_in8_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define Trig_in8_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define Trig_in8_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define Trig_in8_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define Trig_in8_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/