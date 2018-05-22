#ifndef _PCF8653_H
#define _PCF8653_H
#include "stm32f10x.h"

#define PCF8563_GPIO       GPIOB
#define PCF8563_SDA        GPIO_Pin_11 //PB11
#define PCF8563_SCL        GPIO_Pin_10 //PB10

typedef struct {
unsigned char ucSecond;
unsigned char ucMinute;	
unsigned char ucHour;	
unsigned char ucWeek;
unsigned char ucDay;
unsigned char ucMonth;	
unsigned char ucYear;
}PCF8653TypeDef;

void PCF8563_Init(void);
void PCF8563_Read(PCF8653TypeDef * pcf8563);
void PCF8563_ReadTime(PCF8653TypeDef * pcf8563);
void PCF8563_Write(PCF8653TypeDef * pcf8563);
#endif
