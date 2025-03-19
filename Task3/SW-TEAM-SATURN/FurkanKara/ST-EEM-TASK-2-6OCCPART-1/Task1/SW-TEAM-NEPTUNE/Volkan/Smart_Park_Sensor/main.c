#include "../Inc/ParkingAssistantManager_private.h"
#include "../Inc/ParkingAssistantManager_public.h"
int IntervalTime=0;
int CurrentTime(){
    int time=0;

    return time;
}

int main(){


    ParkingAssistans_Init();
    while(1){
    if(CurrentTime - IntervalTime){
        ParkingAssistant_Prosses();
    }
}
}