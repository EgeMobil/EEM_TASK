#include "BUTTON.h"

void BUTTON_Init()
{
	
	printf("**********************\n");
	printf("BUTON KULLANIMA HAZIR!!!\n");	
	printf("**********************\n");
	
}

uint8_t BUTTON_Read()
{
	uint8_t stateOfButton;
	
	scanf("%d", &stateOfButton);
	
	return stateOfButton;
}
