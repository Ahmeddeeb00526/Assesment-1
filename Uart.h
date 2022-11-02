#ifndef __uart__
#define __uart__

void Uart_SetBaudRate(unsigned short BuadRate);
void Uart_Init(void);

void Uart_SendChar(unsigned char DataByte);
unsigned char Uart_ReadData(void);
void Uart_SendString(const char DataString[]);
#endif