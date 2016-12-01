/**
  ******************************************************************************
  * @file    	GPIO/JTAG_Remap/main.c
  * @author  	ARMVN Application Team
  * @version 	V1.0.0
  * @date    	01/30/2010
  * @brief   	Main program body.
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2009 ARMVietNam</center></h2>
  */ 

  
/*
*************************************************************************************************************************************
*															INCLUDED FILES															*
*************************************************************************************************************************************
*/
#include "main.h"

  
/*
*************************************************************************************************************************************
*															PRIVATE DEFINE															*
*************************************************************************************************************************************
*/


/*
*************************************************************************************************************************************
*														 	DATA TYPE DEFINE															*
*************************************************************************************************************************************
*/


/*
*************************************************************************************************************************************
*													   		PRIVATE VARIABLES														*
*************************************************************************************************************************************
*/ 


/*
*************************************************************************************************************************************
*							  								LOCAL FUNCTIONS															*
*************************************************************************************************************************************
*/
/**
  * @brief  	Configures the different system clocks.
  * @param  	None
  * @retval 	None
  */
void RCC_Configuration(void)
{
	/* Setup the microcontroller system. Initialize the Embedded Flash Interface,  
	initialize the PLL and update the SystemFrequency variable. */
	//SystemInit();

	/* Enable GPIOB clocks */
	
}

/**
  * @brief  	Inserts a delay time with resolution is 10 milisecond..
  * @param  	nCount: specifies the delay time length.
  * @retval 	None
  */
 

/*
*************************************************************************************************************************************
*															GLOBAL FUNCTIONS														*
*************************************************************************************************************************************
*/
/**
  * @brief  	Main program.
  * @param  	None
  * @retval 	None
  */
int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	/* Configure the system clocks */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	

	/* Configure PB12, PB.13, PB14 and PB.15 as output push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/* Configure PB4, PB5 as input push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	


	while (1)
	{
		if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4) == 0)
		{
				GPIO_WriteBit(GPIOB, GPIO_Pin_12, (BitAction)(1));
				GPIO_WriteBit(GPIOB, GPIO_Pin_13, (BitAction)(1));
				GPIO_WriteBit(GPIOB, GPIO_Pin_14, (BitAction)(0));
				GPIO_WriteBit(GPIOB, GPIO_Pin_15, (BitAction)(0));
		}
		if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5) == 0)
		{
				GPIO_WriteBit(GPIOB, GPIO_Pin_12, (BitAction)(0));
				GPIO_WriteBit(GPIOB, GPIO_Pin_13, (BitAction)(0));	
				GPIO_WriteBit(GPIOB, GPIO_Pin_14, (BitAction)(1));
				GPIO_WriteBit(GPIOB, GPIO_Pin_15, (BitAction)(1));
		}
	}
}


#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif

/******************* (C) COPYRIGHT 2009 ARMVietNam *****END OF FILE****/
