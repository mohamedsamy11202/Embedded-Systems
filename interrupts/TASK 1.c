/*
 * File:   TASK 1.c
 * Author: mohamed samy
 *
 * Created on July 18, 2023, 3:54 PM
 */


#include "config.h"

void main(void) {
    TRISC=0;
    TRISB0=1;
    TRISB1=1;
    LATC=0;
  
short int i=0;
    
    while(1){
        if(!PORTBbits.RB0){
        __delay_ms(5);
        if(i<8){
         __delay_ms(200);
         LATC|=128>>i;  
         i++;
         
        }
        }
         if(!PORTBbits.RB1){
        __delay_ms(5);
        if(i>=0){
         __delay_ms(200);
         LATC&=~128>>i;  
         i--;
        }
        }
    }
}