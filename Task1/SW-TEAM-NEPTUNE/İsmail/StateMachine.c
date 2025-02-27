/**************************************************************/
/*
    Author : İsmail Güneş 
    27.02.25
*/



/*klima State Machine */

/*
State
INCREASE_TEMP
DECREASE_TEMP
IDLE

Event 
Sıcaklık 25 derecenin altına veya üstüne çıktığında


Transition

IDLE            -> INCREASE_TEMP        sıcaklık düştüyse
INCREASE_TEMP   -> IDLE                 sıcaklık normalse
IDLE            -> DECREASE_TEMP        sıcaklık yükseldiyse
DECREASE_TEMP   -> IDLE                 sıcaklık normalse


Action 
INCREASE_TEMP   kaloriferi aç
DECREASE_TEMP   klimayı aç
IDLE            Do nothing


*/

#include <stdio.h> 


#define OPTIMUMTEMP 25 // 2 derecelik tolerans
#define TOLERANCE 2 // 2 derecelik tolerans

typedef enum
{
IDLE = 0,
INCREASE_TEMP,
DECREASE_TEMP
}TempState_t;

float ReadTempValue (void);
void ClimateControl (TempState_t* TEMPState);

float ReadTempValue (void)
{
    float temp = 23;
    return temp;
}

void ClimateControl (TempState_t* TempState)
{
    switch (*TempState)
    {
    case IDLE:
        /* Ölçüme devam et */
        printf("Ortam sıcaklığı normal\n");
        break;
    case INCREASE_TEMP:
        /* kaloriferi aç */
        printf("Ortam sıcaklığı düşük kalorifer açılıyor\n");
        break;
    case DECREASE_TEMP:
        /* klimayı aç */
        printf("Ortam sıcaklığı düşük klima açılıyor\n");
        break;
    
    default:
        break;
    }
}



int main ()
{
 TempState_t TempState;
 int tempval = 0;
 printf("Ölçülen sıcaklık: %.2f°C\n", tempval);

 while (1)
 {
    tempval = ReadTempValue();
    if (tempval > (OPTIMUMTEMP + TOLERANCE) )      TempState = DECREASE_TEMP;
    else if (tempval < (OPTIMUMTEMP - TOLERANCE) ) TempState = INCREASE_TEMP;
    else                                           TempState = IDLE;
    ClimateControl(TempState);
    sleep(1000);
 }
 
}

/************************END OF FILE**************************/