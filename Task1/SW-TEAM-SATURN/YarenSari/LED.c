#include "LED.h"

static int stateOfLed = 0;	// default olarak kapalı

void LED_Init()
{
	printf("**********************\n");
	printf("LED KULLANIMA HAZIR!!!\n");	
	printf("**********************\n");
	
	LED_IDLE();							// başlangıç durumu 
}

void LED_Write()
{
	static int stateOfButton;
	stateOfButton++;
	
	if(stateOfButton == 1)
		LED_MODE_1();
	else if(stateOfButton == 2)
		LED_MODE_2();
	else if(stateOfButton == 3)
		LED_MODE_3();
	else if(stateOfButton == 4)
	{
		LED_IDLE();
		stateOfButton = 0;
	}
}

void LED_IDLE()
{
	printf("!LED KAPALI!\n");
	stateOfLed = 0;	
}

void LED_MODE_1()
{
	printf("!LED ACIK!\n");
	stateOfLed = 1;
}

void LED_MODE_2()
{
	printf("!LED TOGGLE!\n");	
	
	if(stateOfLed == 0)
		stateOfLed = 1;
	else
		stateOfLed = 0;
		
	delay(100);
}

void LED_MODE_3()
{
	printf("!LED FAST TOGGLE!\n");
	
	if(stateOfLed == 0)
		stateOfLed = 1;
	else
		stateOfLed = 0;
		
	delay(10);
}

void delay(uint32_t time)
{
	for(int i = 0;i < time; i++);
}
