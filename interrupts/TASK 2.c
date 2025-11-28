/*
 * File:   TASK 2.c
 * Author: mohamed samy
 * Created on July 18, 2023, 8:07 AM
 */


#include <xc.h>
#include <pic18f4620.h>
#include<stdlib.h>
#include<stdio.h>
#include "newfile.h"
#include "lcd.h"
#define PRESCALAR 256

 float t;
 int glob=1 ;

void __interrupt() isr(){
    char txt[16];
    if(RBIF){
        if(!PORTBbits.RB4){
            TMR0ON=1;
           if (TMR0IF==1){
             glob++;
             TMR0IF=0;
         }
        }
        else{TMR0ON=0;
         t=(1000/_XTAL_FREQ)*4*PRESCALAR*TMR0*glob;
         sprintf(txt,"time=%0.1f ms",t);
         LCDGoto(0,0);
         LCDPutStr(txt);
         
         TMR0=0;
        }
        RBIF=0;
    }
}

void main(void) {
    
    LCD_Initialize();       
    GIE=1;
    PEIE=1; 
    IPEN=0;
    
    RBIE=1;
    RBIF=1;
    TMR0=0;
    T08BIT=0; 
    T0CS=0;
    PSA=0;
    T0CONbits.T0PS=0x7;
    TMR0ON=0;
    TMR0IF=0;
   
    while(1){
     }
}
