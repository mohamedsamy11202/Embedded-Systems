/*
 * File:   TASK 4.c
 * Author: mohamed samy
 *
 * Created on July 19, 2023, 3:58 PM
 */

#include "config.h"

void main(void) {
char i=0 ,seg[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

    TRISC=0;
    TRISD=0;
    TRISB0=1;
    TRISB1=1;
    LATC=0X3f;
    LATD=0x3f;

    while(1){
    
        if(i>=0&&i<100){
          if(!PORTBbits.RB0){ 
              __delay_ms(5);
             i++;
              LATD=seg[i%10];
              LATC=seg[i/10];
         while(!PORTBbits.RB0);
         
          }
          if(!PORTBbits.RB1){ 
               __delay_ms(5);
               i+=10;
              LATC=seg[i/10];
              LATD=seg[i%10];
          while(!PORTBbits.RB1);    
        }
        }
        else{
      i=0; 
       LATC=0X3f;
    LATD=0x3f;
        }
    }
}