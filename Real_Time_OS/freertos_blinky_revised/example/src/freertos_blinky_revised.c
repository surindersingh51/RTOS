/* @brief FreeRTOS Blinky example
 A Simple Blinking Code with just using delays to alternatively blinking all 3 LEDs */

#include "board.h"
#include "FreeRTOS.h"
#include "task.h"

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/* Sets up system hardware */
static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial LEDs state is off */
	Board_LED_Set(0, false);
	Board_LED_Set(1, false);
	Board_LED_Set(2, false);
}

/* LED1 toggle thread */
static void vLEDTask0(void *pvParameters)
{
	while (1)
	{
		Board_LED_Set(0, true);				//turning Red LED ON
		vTaskDelay(configTICK_RATE_HZ);		//Keeping LED ON for 1 second

		Board_LED_Set(0, false);			//turning Red LED OFF
		vTaskDelay(configTICK_RATE_HZ*5);	//Keeping LED OFF for 5 seconds
	}
}

/* LED2 toggle thread */
static void vLEDTask1(void *pvParameters)
{
	while (1)
	{
		vTaskDelay(configTICK_RATE_HZ*2);	//Keeping LED at its initial state(OFF state) for 1 second

		Board_LED_Set(1, true);				//turning Green LED ON
		vTaskDelay(configTICK_RATE_HZ);		//Keeping LED ON for 1 second

		Board_LED_Set(1, false);			//Turning LED again to OFF state
		vTaskDelay(configTICK_RATE_HZ*3);	//Keeping it OFF for 3 seconds
	}
}

/* LED3 toggle thread */
static void vLEDTask2(void *pvParameters)
{
	while (1)
	{
		vTaskDelay(configTICK_RATE_HZ*4); //Keeping LED at its initial state(OFF state) for 4 second

		Board_LED_Set(2, true);				//turning BLUE LED ON
		vTaskDelay(configTICK_RATE_HZ);		//Keeping LED ON for 1 second

		Board_LED_Set(2, false);			//Turning LED again OFF
		vTaskDelay(configTICK_RATE_HZ);		//Keeping LED OFF for 1 second
	}
}


/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	main routine for FreeRTOS blinky example
 * @return	Nothing, function should not exit
 */
int main(void)
{
	prvSetupHardware();

	/* LED1 toggle thread */
	xTaskCreate(vLEDTask0, (signed char *) "vTaskLed0",
				configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
				(xTaskHandle *) NULL);

	/* LED2 toggle thread */
	xTaskCreate(vLEDTask1, (signed char *) "vTaskLed1",
				configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
				(xTaskHandle *) NULL);

	/* UART output thread, simply counts seconds */
	xTaskCreate(vLEDTask2, (signed char *) "vTaskLed2",
				configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
				(xTaskHandle *) NULL);

	/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}

/**
 * @}
 */
