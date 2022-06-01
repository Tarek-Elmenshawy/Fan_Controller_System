/***********************************************************************/
/***********    Author     : Tarek Elmenshawy       		************/
/***********    File Name  : pwm_timer0.c			     	************/
/***********	Version	   : V0.1							************/
/***********    Date       : 24-05-2022             		************/
/***********    Description: AVR PWM0 driver source file    ************/
/***********************************************************************/

#include "pwm_timer0.h"
#include <avr/io.h>

/***********************************************************************/
/**********				Functions Definitions			  	  **********/
/***********************************************************************/

/*
 * Description:
 * - The function responsible for trigger the Timer0 with the PWM Mode.
 * - Setup the PWM mode with Non-Inverting.
 * - Setup the pre-scaler with F_CPU/8.
 */
void PWM_Timer0_init(void)
{
	/* Reset TCNT0 register */
	TCNT0 = 0;

	/* Reset OCR0 register */
	OCR0 = 0;

	/* Configure Timer0 on non-inverting mode with pre-scaler 8 */
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);
}

/*
 * Description:
 * Setup the compare value based on the required input duty cycle
 */
void PWM_Timer0_dutyCycle(uint8 a_dutyCycle)
{
	/* To avoid negative value in OCR0 register */
	if(a_dutyCycle != 0)
	{
		/* Load OCR0 with duty cycle value as required; a_dutyCycle[0:100] */
		OCR0  = ((uint16)(a_dutyCycle * 256 / 100) - 1);
	}
	else
	{
		OCR0 = 0;
	}


}
