/*
Rerun.c
Jorge Jesus Jurado-Garcia
Purpose_Conditional statements and Pins outputs exploration

Hardware required:
 *Launchpad with LED

Modified 12/08/2019 by Jorge Jurado to use MSP432 Register operations
Modified 12/13/2019 by Jorge Jurado to run in Code composer studio
 */

/*  BEGINNER LAB - Write a program that lights up 8 LEDs, one at a time, in order, for 1 second each.
    You must do this efficiently in your code: do not use 8 separate if/else statements or a long case statement.
 */

#include "msp432.h"
#include "ee1910delay.h"
#include "stdio.h"
#include "ee1910music.h"
/////////////////////////////////////////////////////////////
int on_time= 500;
int off_time= 500;
int light_9 = 0;   //Need to understand what this means
int light_4 = 0;
int direction = 1;
////////////////////////////////////////////////////////////
void main(void) {
    P9->DIR |= 0b11111111;         //Get all 8 pins from port 9
    P4->DIR |= 0b00000011;
    P9->OUT |= 0b11111111;
    P4->OUT |= 0b00000011;        //Turn on all of the pins
    delay(on_time);
    P9->OUT &= ~(0b11111111);      //Turn off all of the pins
    P4->OUT &= ~(0b00000011);
    delay(off_time);
    P9->OUT |= 0b00000001;         //Turn on all of the pins
    delay(on_time);
    P9->OUT &= ~(0b00000001);      //Turn off all of the pins
    delay(off_time);
    while(1){
        while(light_9<8){
            if(light_9 < 8){

                P9->OUT |= 1<<light_9;

                delay(on_time);

                P9->OUT &= ~(1<<light_9);

                delay(off_time);

                light_9 = light_9 + direction;



            if(light_9<=8 && light_4 <=2) {
                P4->OUT |= 1<<light_4;

                delay(on_time);

                P4->OUT &= ~(1<<light_4);

                delay(off_time);

                light_4 = light_4 + direction;
            }

            }

            if(light_4 < 3){
                P4->OUT |= 1>>light_4;

                delay(on_time);

                P9->OUT &= ~(1>>light_4);

                delay(off_time);

                light_4--;
            }

            if(light_9 <= 8){
                P9->OUT |= 1>>light_9;

                delay(on_time);

                P9->OUT &= ~(1>>light_9);

                delay(off_time);

                light_9--;
            }
        }
    }
}

