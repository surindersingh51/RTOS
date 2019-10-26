/* @brief FreeRTOS Blinky example
 A Simple Blinking Code with just using delays to alternatively blinking all 3 LEDs */
#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

xSemaphoreHandle	xMutex_led_blinky;

/* sets up system hardware */
static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial state for each LED is off */
	Board_LED_Set(0, false);
	Board_LED_Set(1, false);
	Board_LED_Set(2, false);
}


static void vLEDBlinky(int led_num)
{
	xSemaphoreTake(xMutex_led_blinky, portMAX_DELAY);
	{
		Board_LED_Set(led_num, true);
		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(led_num, false);
	}
	xSemaphoreGive(xMutex_led_blinky);
}

static void vLEDTask(void *pvParameters)
{
	int *led_num = (int *) pvParameters;

	while (1)
	{
		vLEDBlinky(*led_num);
		vTaskDelay(configTICK_RATE_HZ*2);
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
	xTaskCreate(vLEDTask, (signed char *) "vTaskLed0",
				configMINIMAL_STACK_SIZE, 0, (tskIDLE_PRIORITY + 3UL),
				(xTaskHandle *) NULL);

	/* LED2 toggle thread */
	xTaskCreate(vLEDTask, (signed char *) "vTaskLed1",
				configMINIMAL_STACK_SIZE, 1, (tskIDLE_PRIORITY + 2UL),
				(xTaskHandle *) NULL);

	/* LED3 toggle thread */
	xTaskCreate(vLEDTask, (signed char *) "vTaskLed2",
				configMINIMAL_STACK_SIZE, 2, (tskIDLE_PRIORITY + 1UL),
				(xTaskHandle *) NULL);

	/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}

/**
 * @}
 */
