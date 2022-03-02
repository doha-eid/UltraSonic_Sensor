/***********************************************************************************************************
 * Module:App
 *
 *File Name:app.c
 *
 *Description : Source file of main function of ultrasonic application
 *
 *      Author: Doha Eid
 **********************************************************************************************************/
#include"lcd.h"
#include"icu.h"
#include"ultrasonic.h"
#include<avr/io.h>
#include<util/delay.h>

int main (void )
{
	uint16 Total_Distance=0;
	/*Enable the global interrupt I-bit*/
	SREG|=(1<<7);
	/*Initialize the Ultrasonic sensor */
	 Ultrasonic_Init();
	/*Initialize the LCD */
	LCD_init();
	/*Display this string "Distance=    cm" only once on the LCD at the first low */
	LCD_moveCursor(1,0);
	LCD_displayString("Distance=     cm");
	while (1)
	{
		/*get the distance */
		Total_Distance=Ultrasonic_readDistance();

		/*Display the distance on the LCD  */
		LCD_moveCursor(1,10);
		LCD_intgerToString(Total_Distance);
		LCD_displayCharacter(' ');
	}
}

