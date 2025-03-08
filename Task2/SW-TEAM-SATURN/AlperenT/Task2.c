#include"stdio.h"
#include"string.h"
#include "Windows.h"

#define PASSWORD "1234"
#define RFID     "ABC1234"

typedef enum {
    WAIT,
    LOCK,
    UNLOCK
}DoorState;

DoorState currentState = WAIT;



void unlock_door ()
{
    printf("Kapi açildi!\n");
    Sleep(500);
    currentState = LOCK;

}
void lock_door()
{
    printf("Kapi kilmitlendi!\n");
    currentState = WAIT;
}

void check (char *input)
{
    if(strcmp(input,PASSWORD) == 0 || strcmp(input,RFID) == 0)
    {
        unlock_door();
    }
    else 
    {
        printf("Hatali giriş!\n");
    }
}

int main(void)
{
    char input[20];
    while(1)
    {
        if(currentState == WAIT)
        {
            printf("RFID kartinizi veya şifrenizi giriniz: ");
            scanf("%s",input);
            check(input);
        }
        if(currentState == UNLOCK)
        {
            unlock_door();
        }
        if(currentState == LOCK)
        {
            lock_door();
        }
    }
    return 0;
}