#include "stm32f10x.h"    //调用STM32官方库
#include <stdio.h>        //调用C标准库
#include <string.h>
#include <math.h>
#include "SystemInit.h"
#include "main.h"

#include "LED_Segment.h"
#include "PCF8653.h"



unsigned char ucLED_SegmentCnt = 0;
unsigned char ucDelayDisplayCnt = 0;
unsigned char ucDpBit=0;
unsigned char ucNumber = 0;////

PCF8653TypeDef  scmPCF8563;
/************************************************

************************************************/
 void Delay(u32 count)
 {
   u32 i=0;
   for(;i<count;i++);
 }

int main(void)
{	
	RCC_Configuration();
	SysTick_Configuration();
	
	LED_Segment_Init();
	PCF8563_Init();
	//GPIO_Write(GPIOB, 0xff);
	//GPIO_Write(GPIOA, 0x00);	
	
// example set time 11:25	
//scmPCF8563.ucHour = 11;   // hour
//scmPCF8563.ucMinute = 25;	// minute
//PCF8563_Write(&scmPCF8563);	
				
	while(1)
	{
		if(ucLED_SegmentCnt>=LED_SEGMENT_MAX)//2ms
		{
			ucLED_SegmentCnt = 0;			
				ucDelayDisplayCnt++;
			
				if(ucDelayDisplayCnt>=250){
					ucDelayDisplayCnt = 0;
					ucDpBit = !ucDpBit; 
//					ucNumber++;
//					if(ucNumber>99){
//						ucNumber = 0;
//					}
					PCF8563_ReadTime(&scmPCF8563);
				}
				
				//GPIOB->ODR ^= 0x01;
				LED_SegmentDisplay(scmPCF8563.ucHour,scmPCF8563.ucMinute,ucDpBit,ucNumber,ucNumber);
				
		  }
			
			
			
		
	}
}
