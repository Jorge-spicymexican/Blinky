/*
Lab 3
Jorge Jesus Jurado-Garcia
Purpose_Conditional statements and Pins outputs exploration

Hardware required:
*Launchpad with LED

Modified 12/08/2019 by Jorge Jurado to use MSP432 Register operations
Modified 12/09/2019 by Jorge Jurado to run in Code composer studio
*/

/*  BEGINNER LAB - Write a program that lights up 8 LEDs, one at a time, in order, for 1 second each.
    You must do this efficiently in your code: do not use 8 separate if/else statements or a long case statement.
*/
#include "msp432.h"
#include "ee1910delay.h"
#include "stdio.h"

 int on_time = 1000;
 int off_time = 1000;
 int number;
void main(void){

     printf("Select which Pin");

     scanf("%d",&number);

     switch (number) {
      case 0:
          P9->DIR |= 0b00000001;
          P9->OUT |= 0b00000001;
          delay(on_time);
          P9->OUT &= ~(0b00000001);
          delay(off_time);
      break;
      case 1:
           P9->DIR |= 0b00000010;
           P9->OUT |= 0b00000010;
           delay(on_time);
           P9->OUT &= ~(0b00000010);
           delay(off_time);
      break;
      case 3:
          P9->DIR |= 0b00000100;
          P9->OUT |= 0b00000100;
          delay(on_time);
          P9->OUT &= ~(0b00000100);
          delay(off_time);
      break;
      case 4:
          P9->DIR |= 0b00001000;
          P9->OUT |= 0b00001000;
          delay(on_time);
          P9->OUT &= ~(0b00001000);
          delay(off_time);
      break;
      default:
      printf("WTF JORGE!");
      break;
     }
     return number;
     }

