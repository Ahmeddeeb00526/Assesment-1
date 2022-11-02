#include <avr/io.h>
#include "DIO.h"
#include "ADC.h"
#include "Uart.h"

int main(){
  init();
  int values;//identification of variables
  unsigned char buffer [4];// array of characters
  while(1)// superl loop
  {
 //functions initialiazation
 deebo_potn();
 deebo_buzzer();
 values =Adc_ReadChannel(3);
 itoa(values,buffer,10);
 Uart_SendString(buffer);
 Uart_SendString("\n");
  }
}

void init(){
    deebo_potn();// initialize pot function 
    deebo_buzzer();// initialize buzzer function
 Uart_Init();// initialize UART
}

void deebo_potn(void){
  float data;
  Dio_SetPinDirection('D',5,1);//setting DDRD pin 5 into output
  Dio_SetPinDirection('C',4,0);//setting DDRC pin 4 into input
  //DDRD=0b00010000
  //DDRC=ob00000000

  Adc_Init();//initialize ADC

  data = Adc_ReadChannel(4);//saving ADC data into variable

  

  if(data>500){// LED condition
    

    
    Dio_SetPortDirection('D',5,1);//data > 500
    //PORTB=0b00000100;
  }
    else
    Dio_SetPortDirection('D',5,0);// data < 500
    
 
}

void deebo_buzzer(void){
float volt;
  Dio_SetPinDirection('D',2,1);// setting DDRD pin 2 into output
  Dio_SetPinDirection('C',3,0);// setting DDRC pin 3 into input
// DDRD=0b00000010
//DDRC=0b00000000
  Adc_Init();// inatialize ADC

  volt = Adc_ReadChannel(3);//saving ADC into a variable

  if(volt>700){//buzzer condition
    

    
    Dio_SetPortDirection('D',2,1);//volt>700
    //PORTB=0b00000100;
  }
    else
    Dio_SetPortDirection('D',2,0);//volt<700
}