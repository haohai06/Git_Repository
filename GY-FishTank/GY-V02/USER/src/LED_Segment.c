#include "stm32f10x.h"


unsigned char ucSegmentNum[11]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xff};//ถฮัก
unsigned char ucSelectByte[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//ฮปัก

void LED_Segment_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); 
	//GPIO_ResetBits(GPIOA, GPIO_Pin_8);
	//GPIO_ResetBits(GPIOB, GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
}

void ShowNum(unsigned char ucByte,unsigned char ucNum)
{
	GPIO_ResetBits(GPIOB,0xff);
	GPIO_SetBits(GPIOB,ucByte);

	GPIO_ResetBits(GPIOA,0xff);
	GPIO_SetBits(GPIOA,ucNum);
}


void LED_SegmentDisplay(unsigned char ucHour,unsigned char ucMinute,unsigned char ucDp,\
                         unsigned char ucTemprature,unsigned char ucHum) 
{

	static unsigned char ScantCnt = 0,Byte= 0;
	//unsigned char ucT
	
	GPIO_Write(GPIOB, 0xff);
	GPIO_Write(GPIOA, 0x82);
	ScantCnt++;
	if(ScantCnt>7){
		ScantCnt = 0;
	}
	//GPIO_Write(GPIOB, 0x01<<ScantCnt);
	switch(Byte)
	{
		case 0:
			if(ucDp==0){
				ShowNum(ucSelectByte[Byte],ucSegmentNum[ucHour/10]&0x7f);
			}else{
				ShowNum(ucSelectByte[Byte],ucSegmentNum[ucHour/10]);
			}
			
			Byte = 1;
			break;
			
		case 1:
			if(ucDp==0){
				ShowNum(ucSelectByte[Byte],ucSegmentNum[ucHour%10]&0x7f);
			}else{
				ShowNum(ucSelectByte[Byte],ucSegmentNum[ucHour%10]);
			}	
			Byte = 2;
			break;
	
		case 2:
			if(ucDp==0){
				ShowNum(ucSelectByte[Byte],ucSegmentNum[ucMinute/10]&0x7f);
			}else{
				ShowNum(ucSelectByte[Byte],ucSegmentNum[ucMinute/10]);
			}			
			Byte = 3;
			break;
			
		case 3:
			if(ucDp==0){
				ShowNum(ucSelectByte[Byte],ucSegmentNum[ucMinute%10]&0x7f);
			}else{
				ShowNum(ucSelectByte[Byte],ucSegmentNum[ucMinute%10]);
			}	
			Byte = 4;
			break;			
		case 4:
			ShowNum(ucSelectByte[Byte],ucSegmentNum[ucTemprature/10]);
			//GPIO_Write(GPIOB, 0x10);
		 // GPIO_Write(GPIOA, 0xA4);//2				
			Byte = 5;
			break;
					
		case 5:
			ShowNum(ucSelectByte[Byte],ucSegmentNum[ucTemprature%10]);
			//GPIO_Write(GPIOB, 0x20);
		  //GPIO_Write(GPIOA, 0xA4);//2					
			Byte = 6;
			break;
				
		case 6:
			ShowNum(ucSelectByte[Byte],ucSegmentNum[ucHum/10]);
			//GPIO_Write(GPIOB, 0x40);
		  //GPIO_Write(GPIOA, 0xA4);//2					
			Byte = 7;
			break;
				
		case 7:
			ShowNum(ucSelectByte[Byte],ucSegmentNum[ucHum%10]);
			//GPIO_Write(GPIOB, 0x80);
		 // GPIO_Write(GPIOA, 0xA4);//2					
			Byte = 0;
			break;
			;			
	}	

}






