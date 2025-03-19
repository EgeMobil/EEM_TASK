#include <stdio.h>
#include <stdlib.h>

#include "LED.h"
#include "BUTTON.h"

int main(int argc, char *argv[]) 
{
	LED_Init();
	BUTTON_Init();
	
	printf("**********************\n");
	printf("BUTONA BASMAK ICIN 1'E BAS!\n");
	printf("**********************\n");
	
	while(1)
	{
		if(BUTTON_Read() == 1)
			LED_Write();
	}
	
	return 0;
}