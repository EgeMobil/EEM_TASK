#ifndef MOTORDRIVERDCMPROXY_DEFINITION_H_
#define MOTORDRIVERDCMPROXY_DEFINITION_H_

/* ECU StateManager Global Include*/
#include "ECUStateManager_global.h"

/* Receiver Port Interface Definition Include */
#include "IMotorDriveError.h"

/* Sender Port Interface Definition Include */

/* Base Return Value Definition */
typedef enum
{
    MDP_ERR = 0,
    MDP_EOK ,
    MDP_UNKNOWN
}dtMdpReturn;

typedef enum
{
    PWM_ERR_RFU1 = 0,
    PWM_ERR_RFU2,
    PWM_ERR_RFU3,
    PWM_ERR_RFU4,
    PWM_ERR_RFU5,
    PWM_ERR_RFU6,
    PWM_ERR_UNKNOWN = 0xFF,
}dtPwmError;

typedef enum
{
    BDR_ERR_RFU1 = 0,
    BDR_ERR_RFU2,
    BDR_ERR_RFU3,
    BDR_ERR_RFU4,
    BDR_ERR_RFU5,
    BDR_ERR_RFU6,
    BDR_ERR_UNKNOWN = 0xFF,
}dtBdrError;

typedef enum
{
    IRQ_ERR_RFU1 = 0,
    IRQ_ERR_RFU2,
    IRQ_ERR_RFU3,
    IRQ_ERR_RFU4,
    IRQ_ERR_RFU5,
    IRQ_ERR_RFU6,
    IRQ_ERR_UNKNOWN = 0xFF,
}dtIrqError;

typedef enum
{
    SPEED_ERR_RFU1 = 0,
    SPEED_ERR_RFU2,
    SPEED_ERR_RFU3,
    SPEED_ERR_RFU4,
    SPEED_ERR_RFU5,
    SPEED_ERR_RFU6,
    SPEED_ERR_UNKNOWN = 0xFF,
}dtSpeedError;

typedef enum
{
    GDR_ERR_RFU1 = 0,
    GDR_ERR_RFU2,
    GDR_ERR_RFU3,
    GDR_ERR_RFU4,
    GDR_ERR_RFU5,
    GDR_ERR_RFU6,
    GDR_ERR_UNKNOWN = 0xFF,
}dtGdrError;

/* Compu Method Alias Type Definitions */
typedef dtMdpReturn dtMotorDriverControlManager_MdpReturn;

typedef dtPwmError      dtMotorDriverControlManager_pwmError   ;
typedef dtBdrError      dtMotorDriverControlManager_bdrError   ;
typedef dtIrqError      dtMotorDriverControlManager_irqError   ;
typedef dtSpeedError    dtMotorDriverControlManager_speedError ;
typedef dtGdrError      dtMotorDriverControlManager_gdrError   ;

typedef cmMotorDriveError dtMotorDriverControlManager_motorDriveError;

/* Configuration Child-Class Definition (IF NEEDED!) */

/* BaseClass Definition */
typedef struct 
{
    /* Interface Pointer */
    IMotorDriveError* IMotorDriveError;

    /* Attributes */
    dtPwmError   pwmErr;
    dtBdrError   bdrErr;
    dtIrqError   irqErr;
    dtSpeedError speedErr;
    dtGdrError   gdrErr;

    /* Getter/Setter Function Pointers */
    dtPwmError (*getPwmError)(void);
    void (*setPwmError)(dtPwmError error);

    dtBdrError (*getBdrError)(void);
    void (*setBdrError)(dtBdrError error);

    dtIrqError (*getIrqError)(void);
    void (*setIrqError)(dtIrqError error);

    dtSpeedError (*getSpeedError)(void);
    void (*setSpeedError)(dtSpeedError error);

    dtGdrError (*getGdrError)(void);
    void (*setGdrError)(dtGdrError error);

    /* toString Function Pointer */
    char* (*toString)(void);

}dtMotorDriverDcmProxy;


#endif /* MOTORDRIVERDCMPROXY_DEFINITION_H_ */