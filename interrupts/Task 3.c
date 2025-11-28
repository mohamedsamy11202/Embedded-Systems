/*
 * File:   Task 3.c
 * Author: mohamed samy
 * Created on July 19, 2023, 8:07 AM
 */



#include "config.h"
#include "lcd.h"
#include <stdlib.h>
#include<stdio.h>
#define PRESCALAR 256

float t;
int msg = 0;

void __interrupt() isr() {
    char txt[16];
    if (INT0IF) {
        if (!PORTBbits.RB0) {
            TMR0ON = 1;
            if (TMR0IF == 1) {
                msg++;
                TMR0IF = 0;
            }
        } else {
            TMR0ON = 0;
            t = (1000 / _XTAL_FREQ)*4 * PRESCALAR * TMR0*msg;
            sprintf(txt, "Freq = %0.1f Hz ", 1 / t);
            LCDGoto(0, 0);
            LCDPutStr(txt);

            TMR0 = 0;
        }
        INT0IF = 0;
    }
}

void main(void) {
    GIE = 1;
    PEIE = 1;
    IPEN = 0;
    LCD_Initialize();

    INT0IE = 1;
    INT0IF = 0;
    INTEDG0 = 1;
    TMR0 = 0;

    TMR0 = 0;
    T08BIT = 0;
    T0CS = 0;
    PSA = 0;
    T0CONbits.T0PS = 0x7;
    TMR0IF = 1;
    TMR0ON = 1;
     
    while (1) {
    }
}


