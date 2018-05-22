/**
  ******************************************************************************
  * @file    GPIO/IOToggle/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h" 
#include "main.h" 


void NMI_Handler(void)
{
}
 
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}
 
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

 
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}
 
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}
 
void SVC_Handler(void)
{
}
 
void DebugMon_Handler(void)
{
}
 
void PendSV_Handler(void)
{
}
 
void SysTick_Handler(void)
{
	if(ucLED_SegmentCnt<LED_SEGMENT_MAX){
		ucLED_SegmentCnt++;
	}
	//GPIOB->ODR ^= 0x01;
}


void USART1_IRQHandler(void)  //WIFI
{
	unsigned char ucTempReceiveData = 0;
	if(USART_GetITStatus(USART1,USART_IT_RXNE)!= RESET){ 
		ucTempReceiveData = USART_ReceiveData(USART1);
	}
	USART_ClearFlag(USART1, USART_FLAG_TC);	
}

void USART2_IRQHandler(void)  //Lovo
{

	unsigned char ucTempReceiveData = 0;

	if(USART_GetITStatus(USART2,USART_IT_RXNE)!= RESET){ 
		ucTempReceiveData = USART_ReceiveData(USART2);
	}
	USART_ClearFlag(USART2, USART_FLAG_TC);	
}


void USART3_IRQHandler(void)  //RS485
{
	unsigned char ucTempReceiveData = 0;

	if(USART_GetITStatus(USART3,USART_IT_RXNE)!= RESET){ 
		ucTempReceiveData = USART_ReceiveData(USART3);

	}
	USART_ClearFlag(USART3, USART_FLAG_TC);	
}
/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/
