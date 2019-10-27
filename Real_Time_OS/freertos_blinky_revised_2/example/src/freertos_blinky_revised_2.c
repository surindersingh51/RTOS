/* @brief FreeRTOS Blinky example
 A Simple Blinking Code with just using delays to alternatively blinking all 3 LEDs */
#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

xSemaphoreHandle	xMutex_led_blinky;

struct LED_struct
{
	int led_num;
};
typedef struct LED_struct led_value;

led_value led_no[3];



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


static void vLEDBlinky(int num)
{
	xSemaphoreTake(xMutex_led_blinky, portMAX_DELAY);
	{
		Board_LED_Set(num, true);
		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(num, false);
		vTaskDelay(configTICK_RATE_HZ*2);
	}
	xSemaphoreGive(xMutex_led_blinky);
}

static void vLEDTask(void *pvParameters)
{
	led_value *led_param = (led_value *)pvParameters;
	int num = led_param -> led_num;

	while (1)
	{
		vLEDBlinky(num);
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

	led_no[0].led_num=0;
	led_no[1].led_num=1;
	led_no[2].led_num=2;

	prvSetupHardware();

	/* LED1 toggle thread */
	xTaskCreate(vLEDTask, (signed char *) "vTaskLed0",
				configMINIMAL_STACK_SIZE,&led_no[0], (tskIDLE_PRIORITY + 3UL),
				(xTaskHandle *) NULL);

	/* LED2 toggle thread */
	xTaskCreate(vLEDTask, (signed char *) "vTaskLed1",
				configMINIMAL_STACK_SIZE,&led_no[1], (tskIDLE_PRIORITY + 2UL),
				(xTaskHandle *) NULL);

	/* LED3 toggle thread */
	xTaskCreate(vLEDTask, (signed char *) "vTaskLed2",
				configMINIMAL_STACK_SIZE,&led_no[2], (tskIDLE_PRIORITY + 1UL),
				(xTaskHandle *) NULL);

	/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}

/**
 * @}
 */
