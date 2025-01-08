// doxygen'e uygun brief eklenecek chatgpt kullanilabilir BrakeAndDirectionManager örnek alabilirsin
#ifndef SPEEDCONTROLMANAGER_INC_SPEEDCONTROLMANAGER_DEFINITION_H_
#define SPEEDCONTROLMANAGER_INC_SPEEDCONTROLMANAGER_DEFINITION_H_

// yorumlar silinecek Doxygen'e uygun eklenecek ve doxy'dan generate edilecek.

#include "ECUStateManager_global.h"

/* Include interface headers */
#include "IRawSpeed.h"
#include "ISpeedStatus.h"
#include "IIndicatorSpeedStatus.h"

// retVal enum eklenecek ve komponent isimli Return type eklenecek

// interface'lerin compumethod'lari (cm)'ler component bazli eklenecek

typedef struct SpeedControlManager
{
    /* Interface pointer */
    // kullanilan interface'ler eklenecek 

    /* Attributes */
    // interface üzerinden okunan değişkenlerin local halleri eklenecek
    //[[[[[[[[[[[[[[[[
    // componentin internal olarak kullanabilecegi degiskenler eklenecek.
    // bu algoritma tasarimiyla alakali olacak bunun icin detaylar;
    //]]]]]]]]]]]]]]]] 
    
    /* Getter/Setter */
    // Attributele'ın getter/setter methotlari eklenecek.

}dtSpeedControlManager;



#endif /* SPEEDCONTROLMANAGER_INC_SPEEDCONTROLMANAGER_DEFINITION_H_ */