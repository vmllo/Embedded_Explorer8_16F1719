


#include "stdio.h"  
#include <stdbool.h>     
#include "newxc8_header.h"

                   
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
    if(testPort(0x8F,0x0F,0,1,0b0001)){
        printf("pass");
    }
    
    testPort(0x8F,0x0F,0,0,0x80); 
}                         
                        