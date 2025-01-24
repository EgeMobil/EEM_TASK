#include "ECUStateManager_private.h"

dtECUStateManager_ecuState  ECU_STATE = ECUSTATE_STARTUP;
uint32_t systemStateCount = 0;  /* Start up count local variable */

dtECUStateManager_startUp  		systemStartUp = STARTUP_PRE_INIT;
dtECUStateManager_refreshState	REFRESH_STATE = REFRESHSTATE_UNKNOWN;
dtECUStateManager_processState  PROCESS_STATE = PROCESSSTATE_UNKNOWN; 

void HandleStartupState(void)
{
    // Handling STARTUP state

    // Başlangıç aşamalarını kontrol et
    switch (systemStartUp) {
        case STARTUP_PRE_INIT:
            // System in PRE_INIT stage
            // Constructor of class
            BrakeAndDirectionManager_CTOR();
            GateDriverController_CTOR();

            InterruptHandlerManager_CTOR();
            HALLSensorConfiguration_CTOR();
            
            MotorDriverCommProxy_CTOR();
            MotorDriverControlManager_CTOR();
            MotorDriverDcmProxy_CTOR();
            PWMConfiguration_CTOR();
            SpeedControlManager_CTOR();

            // Bir sonraki aşamaya geç
            systemStartUp = STARTUP_INIT;
            break;

        case STARTUP_INIT:
            // System in INIT stage
            // ECU başlangıç işlemleri
            ECU_STATE = ECUSTATE_INIT;
            break;

        case STARTUP_POST_INIT:
            // System in POST_INIT stage
            // Başlangıç sonrası rutinler
            ECU_STATE = ECUSTATE_ROUTINE;
            break;

        default:
            // Invalid STARTUP state detected
            systemStartUp = STARTUP_PRE_INIT; // Varsayılan olarak başlangıç öncesine dön
            break;
    }
}

void HandleInitState(void)
{
    // Handling INIT state
    GateDriverController_ruInitialisation();
    InterruptHandlerMAnager_ruInitialisation();
    HALLSensorConfiguration_ruInitialisation();
    MotorDriverControlManager_ruInitialisation();
    BrakeAndDirectionManager_ruInitialistaion();
    SpeedControlManager_ruInitialisation();
    PWMConfiguration_ruInitialisation();

    // Başarılı init sonrası bir sonraki duruma geç
    systemStartUp = STARTUP_POST_INIT;
    ECU_STATE = ECUSTATE_STARTUP;
}

void HandleRoutineState(void)
{
    // Handling ROUTINE state

    switch (REFRESH_STATE) 
    {
        case REFRESHSTATE_GATEDRIVERCONTROLLER:
            // Refreshing Gate Driver Controller
            GateDriverController_ruRefresh();
            break;

        case REFRESHSTATE_MOTORDRIVERCONTROLMANAGER:
            // Refreshing Motor Driver Control Manager
            MotorDriverControlManager_ruRefresh();
            break;

        case REFRESHSTATE_BRAKEANDDIRECTIONMANAGER:
            // Refreshing Speed Control Manager
            BrakeAndDirectionManager_ruRefresh();
            break; 

        case REFRESHSTATE_SPEEDCONTROLMANAGER:
            // Refreshing Speed Control Manager
            SpeedControlManager_ruRefresh();
            break;  

        case REFRESHSTATE_PWMCONFIGURATION:
            // Refreshing PWM Configuration
            PWMConfiguration_ruRefresh();
            break;

        case REFRESHSTATE_MOTORDRIVERCOMMPROXY:
            // Refreshing Motor Driver Communication Proxy
            MotorDriverCommProxy_ruRefresh();
            break;

        case REFRESHSTATE_MOTORDRIVERDCMPROXY:
            // Refreshing Motor Driver DCM Proxy
            MotorDriverDcmProxy_ruRefresh();
            break;

        case REFRESHSTATE_ANALOGREAD:
            // Performing Analog Read
            
            break;

        case REFRESHSTATE_COMMUNICATION:
            // Performing Communication Refresh

            break;

        case REFRESHSTATE_SUSPEND:
            // System is in SUSPEND state
            // Suspend işlemleri
            
            break;

        case REFRESHSTATE_DEFAULT:
            // Resetting REFRESH_STATE to REFRESHSTATE_MOTORDRIVERCONTROLMANAGER
            REFRESH_STATE = REFRESHSTATE_MOTORDRIVERCONTROLMANAGER;
            break;

        default:
            // Invalid REFRESH_STATE detected
            // Varsayılan olarak ilk rutin analog okuma
            REFRESH_STATE = REFRESHSTATE_DEFAULT; 
            break;
    }

    // Bir sonraki state geç,
    REFRESH_STATE++;
    if (REFRESH_STATE > REFRESHSTATE_COMMUNICATION) {
        REFRESH_STATE = REFRESHSTATE_MOTORDRIVERCONTROLMANAGER; // Döngüyü tamamla ve başa dön
    }


}

void HandleProcessState(void)
{
    // Handling PROCESS state
    dtECUStateManager_processState PREV_PROCESS_STATE = PROCESS_STATE;
    dtECUStateManager_processState PREV_REFRESH_STATE = REFRESH_STATE;
    REFRESH_STATE = REFRESHSTATE_SUSPEND;

    switch (PROCESS_STATE) {
        case PROCESSSTATE_INTERRUPTHANDLERMANAGER_EXTERNALTRIGGER:
            // Handling External Interrupt Trigger
            InterruptHandlerManager_ruExternalTrigger();
            ECUStateManager_RunProcess(PROCESSSTATE_HALLSENSORCONFIGURATION_UPDATE);
            break;

        case PROCESSSTATE_INTERRUPTHANDLERMANAGER_TIMERTRIGGER:
            // Handling Timer Interrupt Trigger
            InterruptHandlerManager_ruTimerTrigger();
            
            break;

        case PROCESSSTATE_HALLSENSORCONFIGURATION_UPDATE:
            // Updating Hall Sensor Configuration
            // Hall Sensor Update işlemleri
            HALLSensorConfiguration_ruUpdateA();
            HALLSensorConfiguration_ruUpdateB();
            HALLSensorConfiguration_ruUpdateC();

            break;

        case PROCESSSTATE_HALLSENSORCONFIGURATION_CALCULATEWHEELSPEED:
            // Calculating Wheel Speed from Hall Sensor
            // Wheel Speed Calculation işlemleri
            
            break;

        case PROCESSSTATE_PWMCONFIGURATION_UPDATE:
            // Updating PWM Configuration
            PWMConfiguration_ruUpdate();
            
            break;

        case PROCESSSTATE_DIRECTIONANDBRAKEMANAGER_UPDATE:
            // Updating Direction and Brake Manager
            // Direction and Brake Update işlemleri
            
            break;

        case PROCESSSTATE_SPEEDCONTROLMANAGER_UPDATE:
            // Updating Speed Control Manager
            // Speed Control Update işlemleri
            
            break;

        case PROCESSSTATE_MOTORDRIVEDCMPROXY_COLLECT:
            // Collecting Data for Motor Driver DCM Proxy
            // DCM Proxy Data Collection işlemleri
            
            break;

        case PROCESSSTATE_MOTORDRIVECOMMPROXY_UPDATEDIRECTION:
            // Updating Direction in Motor Driver Communication Proxy
            // Direction Update işlemleri
            
            break;

        case PROCESSSTATE_MOTORDRIVECOMMPROXY_UPDATESPEED:
            // Updating Speed in Motor Driver Communication Proxy
            // Speed Update işlemleri
            
            break;

        case PROCESSSTATE_MOTORDRIVECOMMPROXY_UPDATEWHEELSPEED:
            // Updating Wheel Speed in Motor Driver Communication Proxy
            // Wheel Speed Update işlemleri
            
            break;

        case PROCESSSTATE_TXSIGNALADAPTER:
            // Handling Tx Signal Adapter
            //@LATER TxSignal Islemleri          
            
            break;

        case PROCESSSTATE_ANALOGDATAWRAPPER:
            // Handling Analog Data Wrapper
            //@LATER Analog Data Islemleri
            ECUStateManager_RunProcess(PROCESSSTATE_TXSIGNALADAPTER);
            break;

        case PROCESSSTATE_FINISHED:
            // System is in SUSPEND state
            // Suspend işlemleri
            PROCESS_STATE = PROCESSSTATE_DEFAULT;
            break;

        case PROCESSSTATE_DEFAULT:
            // Resetting PROCESS_STATE to UNKNOWN
            /* Go back routine state when process finished */
            REFRESH_STATE = PREV_REFRESH_STATE + 1 ;
            ECU_STATE = ECUSTATE_ROUTINE;
            break;

        default:
            // Invalid PROCESS_STATE detected
            PROCESS_STATE = PROCESSSTATE_DEFAULT; // Varsayılan duruma dön      
            break;
    }

    if( PREV_PROCESS_STATE == PROCESS_STATE && PROCESSSTATE_DEFAULT != PROCESS_STATE )
    {
        PROCESS_STATE = PROCESSSTATE_FINISHED;
    }
    else
    {
        /* Defensive Coding */
    }

}

void HandleSuspendState(void)
{
    // Handling SUSPEND state
    // Suspend işlemleri burada ele alınır
    ECU_STATE = ECUSTATE_DEFAULT;
}


