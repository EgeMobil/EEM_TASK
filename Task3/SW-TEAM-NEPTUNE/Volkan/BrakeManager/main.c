#include "Inc/BrakeManager_Private.h"
#include "Inc/BrakeManager_Public.h"
int main(){
    
    BrakeManager_ruInit();
 
    while(1){
    	BrakeManager_ruUpdateSelf();
    	BrakeManager_ruControl();
    }

}