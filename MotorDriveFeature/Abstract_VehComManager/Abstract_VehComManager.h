#ifndef ABSTRACT_VEHCOMMANAGER_H_
#define ABSTRACT_VEHCOMMANAGER_H_

#include "ECUStateManager_global.h"

/*********************************************************/
/* ISpeed : Speed - Compu Method */
typedef uint16_t cmSpeed;
/* ISpeed : Speed - Data Constraint */
typedef struct
{
    uint8_t lowerLimit;     
    uint8_t upperLimit;     
    MonotonyType monotony;  
} dcSpeed;
/*********************************************************/

/*********************************************************/
/* IBdr : Bdr - Compu Method */
typedef uint16_t cmBdr;
/* IBdr : Bdr - Data Constraint */
typedef struct
{
    uint8_t lowerLimit;     
    uint8_t upperLimit;     
    MonotonyType monotony;  
} dcBdr;
/*********************************************************/

/*********************************************************/
/* IIndicator : Indicator - Compu Method */
typedef uint16_t cmIndicator;
/* IIndicator : Indicator - Data Constraint */
typedef struct
{
    uint8_t lowerLimit;     
    uint8_t upperLimit;     
    MonotonyType monotony;  
} dcIndicator;
/*********************************************************/

/*********************************************************/
/* IWheelSpeed : WheelSpeed - Compu Method */
typedef uint16_t cmWheelSpeed;
/* IWheelSpeed : WheelSpeed - Data Constraint */
typedef struct
{
    uint8_t lowerLimit;     
    uint8_t upperLimit;     
    MonotonyType monotony;  
} dcWheelSpeed;
/*********************************************************/



#endif /* ABSTRACT_VEHCOMMANAGER_H_ */