


#include "stdio.h"  
#include <stdbool.h>     
#include "newxc8_header.h"

union PORTDx            
{                          
    struct {  
        unsigned char rb0:1;
        unsigned char rb1:1;
        unsigned char rb2:1;
        unsigned char rb3:1;
        unsigned char rb4:1;   
        unsigned char rb5:1;   
        unsigned char rb6:1;   
        unsigned char rb7:1;                                
    }PORTDBits;                  
    unsigned char registers;   
};       


       
             
int testPort(int *trisPort, int *Port, int direction, int direction2, int counter){             
    *trisPort = direction;                   
    *Port = direction2;
    int i = 0;
    while(i <= 5){        
        *Port = counter;
        _delay(50000);
        *Port = 0;
        counter <<= 1;
        i++;
    }                    
    return 1;            
}                       


void main(){ 
    unsigned int* PORTDx = (unsigned int*)0x0F;
    unsigned int* TRISDx = (unsigned int*)0x8F;
    unsigned int* PORTx = PORTDx;
    unsigned int* TRISx = TRISDx;
    *TRISx = 1;
    union PORTDx d;
    d.registers = 0;
    *PORTx = d.PORTDBits.rb3 = 1;
    while(1)
    {    
       *PORTx = d.registers;
       _delay(50000);
       *PORTx = 0;
       d.registers >>= 1;     
    }
}                         
                        