/*
 * File:   MULTIPLEXING.c
 * Author: aswin
 *
 * Created on 15 March, 2024, 9:18 PM
 */

#include<xc.h>
#pragma config FOSC = XT        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON       // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 20000000
#define Segment_ON  1
#define Segment_OFF 0

unsigned char number = 78;
unsigned char i,j;
unsigned char seg[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7c,0x07,0x7f,0x6f};



void main()
{
    TRISB = 0x00; // All portb pins as output
    TRISC = 0x00; // All portc pins as output
     
while(1)
    {
      i = number / 10; // 78 / 10 First digit
      j = number % 10; // Second digit
      PORTCbits.RC0 = Segment_ON; PORTCbits.RC1 = Segment_OFF;   //1. Turn On First Display and turn Off second display
      PORTB = seg[i];                                            // 2. Print required data to be printed in first display
      __delay_ms(.5);                                            //ms or us
      PORTCbits.RC1 = Segment_ON; PORTCbits.RC0 = Segment_OFF;   //3. Turn On Second Display and turn Off first display
      PORTB = seg[j];                                            //4. Print required data to be printed in second display
      __delay_ms(.5);                                            //ms or us

    }     
}
