#ifndef MOTORDRIVERCONTROLMANAGER_DEFINITION_H_
#define MOTORDRIVERCONTROLMANAGER_DEFINITION_H_

/* ECU StateManager Global Include*/
#include "ECUStateManager_global.h"

/* Receiver Port Interface Definition Include */
#include "ISpeed.h"
#include "IBdr.h"

/* Sender Port Interface Definition Include */
#include "IRawSpeed.h"
#include "IBrakeAndDirection.h"

/* Base Return Value Definition */
typedef enum
{
    MDC_ERR = 0,
    MDC_EOK ,
    MDC_UNKNOWN
}dtMdcReturn;

/* Compu Method Alias Type Definitions */
typedef dtMdcReturn dtMotorDriverControlManager_dtMdcReturn;

typedef cmSpeed             dtMotorDriverControlManager_Speed          ;
typedef cmBdr               dtMotorDriverControlManager_Bdr            ;
typedef cmRawSpeedStatus    dtMotorDriverControlManager_RawSpeedStatus ;
typedef cmBrakeStatus       dtMotorDriverControlManager_BrakeStatus    ;
typedef cmDirectionStatus   dtMotorDriverControlManager_DirectionStatus;

/* Configuration Child-Class Definition (IF NEEDED!) */

/* BaseClass Definition */
typedef struct 
{
    /* Interface Pointer */
    ISpeed* ISpeed;
    IBdr* IBdr;
    IRawSpeed* IRawSpeed;
    IBrakeAndDirection* IBrakeAndDirection;

    /* Attributes */
    dtMotorDriverControlManager_Speed           speed          ;
    dtMotorDriverControlManager_Bdr             bdr            ;
    dtMotorDriverControlManager_RawSpeedStatus  rawSpeedStatus ;
    dtMotorDriverControlManager_BrakeStatus     brakeStatus    ;
    dtMotorDriverControlManager_DirectionStatus directionStatus; 

/* Getter/Setter Function Pointers */
    dtMotorDriverControlManager_Speed (*getSpeed)(void);
    void (*setSpeed)(dtMotorDriverControlManager_Speed speed);

    dtMotorDriverControlManager_Bdr (*getBdr)(void);
    void (*setBdr)(dtMotorDriverControlManager_Bdr bdr);

    dtMotorDriverControlManager_RawSpeedStatus (*getRawSpeedStatus)(void);
    void (*setRawSpeedStatus)(dtMotorDriverControlManager_RawSpeedStatus status);

    dtMotorDriverControlManager_BrakeStatus (*getBrakeStatus)(void);
    void (*setBrakeStatus)(dtMotorDriverControlManager_BrakeStatus status);

    dtMotorDriverControlManager_DirectionStatus (*getDirectionStatus)(void);
    void (*setDirectionStatus)(dtMotorDriverControlManager_DirectionStatus status);

    /* toString Function Pointer */
    char* (*toString)(void);

    /* Functional Behaviours */

}dtMotorDriverControlManager;


#endif /* MOTORDRIVERCONTROLMANAGER_DEFINITION_H_ */