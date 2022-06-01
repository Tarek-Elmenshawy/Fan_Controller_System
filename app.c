/***********************************************************************/
/***********    Author     : Tarek Elmenshawy       		************/
/***********    File Name  : app.c			    			************/
/***********    Date       : 24-05-2022             		************/
/***********    Description: Application layer			    ************/
/***********************************************************************/

#include "std_types.h"
#include "lcd.h"
#include "adc.h"
#include "lm35_sensor.h"
#include "dc_motor.h"

int main(void)
{
	/* A variable to save current temperature sensor value */
	uint8 l_temperature;
	/* A structure to set ADC configurations */
	ADC_ConfigType ADC_configuration = {ADC_VREF_2_56V_INT, ADC_8_PRESCALER};

	/* Configure ADC depends on configuration structure */
	ADC_init(&ADC_configuration);

	/* Configure motors pins */
	DC_MOTOR_init();

	/* Initialize LCD */
	LCD_init();

	while(1)
	{
		/* Get temperature sensor value */
		l_temperature = LM35_getTemperature();

		/* Control fan motor depends on temperature value */
		if(l_temperature >= 120)
			DC_MOTOR_rotate(DC_MOTOR_CW, 100);
		else if(l_temperature >= 90)
			DC_MOTOR_rotate(DC_MOTOR_CW, 75);
		else if(l_temperature >= 60)
			DC_MOTOR_rotate(DC_MOTOR_CW, 50);
		else if(l_temperature >= 30)
			DC_MOTOR_rotate(DC_MOTOR_CW, 25);
		else
			DC_MOTOR_rotate(DC_MOTOR_STOP, 0);

		/* Display fan motor state on LCD */
		if(l_temperature < 30)
			LCD_displayStringRowColumn(0, 0, "   Fan is OFF   ");
		else
			LCD_displayStringRowColumn(0, 0, "   Fan is ON    ");

		/* Display temperature value on LCD */
		LCD_displayStringRowColumn(1, 3, "Temp = ");
		LCD_integerToString(l_temperature);
		LCD_displayString(" C");
	}

	return 0;
}


