#include "ECUStateManager_private.h"

// Helper functions for state names
const char* GetStartupStateName(dtECUStateManager_startUp state)
{
    switch (state)
    {
        case STARTUP_UNKNOWN: return "UNKNOWN";
        case STARTUP_PRE_INIT: return "PRE_INIT";
        case STARTUP_INIT: return "INIT";
        case STARTUP_POST_INIT: return "POST_INIT";
        default: return "INVALID";
    }
}

const char* GetEcuStateName(dtECUStateManager_ecuState state)
{
    switch (state)
    {
        case ECUSTATE_UNKNOWN: return "UNKNOWN";
        case ECUSTATE_INIT: return "INIT";
        case ECUSTATE_ROUTINE: return "ROUTINE";
        case ECUSTATE_PROCESS: return "PROCESS";
        case ECUSTATE_SUSPEND: return "SUSPEND";
        case ECUSTATE_DEFAULT: return "DEFAULT";
        default: return "INVALID";
    }
}

const char* GetRefreshStateName(dtECUStateManager_refreshState state)
{
    switch (state)
    {
        case REFRESHSTATE_UNKNOWN: return "UNKNOWN";
        case REFRESHSTATE_ANALOGREAD: return "ANALOGREAD";
        case REFRESHSTATE_COMMUNICATION: return "COMMUNICATION";
        case REFRESHSTATE_GATEDRIVER_FAULTREAD: return "FAULTREAD";
        case REFRESHSTATE_RFU01: return "RFU01";
        case REFRESHSTATE_RFU02: return "RFU02";
        case REFRESHSTATE_SUSPEND: return "SUSPEND";
        case REFRESHSTATE_DEFAULT: return "DEFAULT";
        default: return "INVALID";
    }
}

const char* GetProcessStateName(dtECUStateManager_processState state)
{
    switch (state)
    {
        case PROCESSSTATE_UNKNOWN: return "UNKNOWN";
        case PROCESSSTATE_ANALOGDATAWRAPPER: return "ANALOGDATAWRAPPER";
        case PROCESSSTATE_TXSIGNALADAPTER: return "TXSIGNALADAPTER";
        case PROCESSSTATE_SUSPEND: return "SUSPEND";
        case PROCESSSTATE_DEFAULT: return "DEFAULT";
        default: return "INVALID";
    }
    
}

const char* GetExecutionStateName(dtProcessExecutionState state)
{
    switch (state)
    {
        case PROCESS_EXECUTION_UNKNOWN: return "UNKNOWN";
        case PROCESS_EXECUTION_START: return "START";
        case PROCESS_EXECUTION_RUNNING: return "RUNNING";
        case PROCESS_EXECUTION_FINISHED: return "FINISHED";
        default: return "INVALID";
    }
}

const char* GetExecutionStateCount(dtECUStateManager_processRunningCounter count)
{
    static char buffer[3]; // Buffer to store the formatted string
    
    if (count > 0)
    {
        snprintf(buffer, sizeof(buffer), "%d", count); // Format the number as a string
    }
    else
    {
        snprintf(buffer, sizeof(buffer), "X"); // Return "X" if count is 0 or less
    }

    return buffer;
        
}

FUNC(void, ECUStateManager)(void)
{
	for(int i=0; i<500 ; i++)
	{
		/* Infinite loop */
		ECU_StateMachine();
	}
}

void ECU_StateMachine(void)
{
    /* Start up count local variable */
    static uint32_t systemStartupStateCount = 0;
    /* Sequence Count */
    systemStartupStateCount++;
    
    /* @Delete: Test senaryosu State count = 20 olunca analog data wrapper process(pending içermeyen bir) geldiğini varsayalım */
    /*****************/
    static int processQueueIdx = 0;
    if(( systemStartupStateCount % 30) == 0 )
    {       

        if( ECUSTATE_ROUTINE == ECU_STATE)
        {
            ECU_STATE = ECUSTATE_PROCESS;
            PROCESS_STATE = PROCESSSTATE_ANALOGDATAWRAPPER;
            AnalogDataWrapper_processExecutionState = PROCESS_EXECUTION_START;
        }
        else if( ECUSTATE_PROCESS == ECU_STATE )
        {
            processQueue[processQueueIdx] = PROCESSSTATE_ANALOGDATAWRAPPER;
            processQueueIdx++;

            if(processQueueIdx > 5)
            {
                 processQueueIdx = 0;
            }
        }
        
    }
    /* @Delete: Test senaryosu State count = 30 olunca analog data wrapper process(pending içeren bir) geldiğini varsayalım */
    if(( systemStartupStateCount % 20 ) == 0 )
    {
        if(ECUSTATE_ROUTINE == ECU_STATE)
        {
            ECU_STATE = ECUSTATE_PROCESS;
            PROCESS_STATE = PROCESSSTATE_TXSIGNALADAPTER;
            TxSignalAdapter_processExecutionState = PROCESS_EXECUTION_START;
        }
        else if( ECUSTATE_PROCESS == ECU_STATE )
        {
            processQueue[processQueueIdx] = PROCESSSTATE_TXSIGNALADAPTER;
            processQueueIdx++;

            if(processQueueIdx > 5)
            {
                 processQueueIdx = 0;
            }
        }
    }
    /*****************/
    
    if( ECUSTATE_UNKNOWN == ECU_STATE )
    {
        if( STARTUP_PRE_INIT == systemStartUp )
        {
            /* Component constructor call 
            - AnalogConfigurationCTOR(); -  Singelton pattern 
            - MotorDriveControllerCTOR(); - Singelton pattern 
            */
            
            /* Pre-init condition */
            // timeVal = 10; 
        
            systemStartUp = STARTUP_INIT;
        }
        else
        {
            if( STARTUP_INIT == systemStartUp )
            {
                
                /* Start-Up Initialised Ecu can init */
                ECU_STATE = ECUSTATE_INIT;
            }
            else
            {
                /* State başlangıç dışında unknown olursa state hatası var demektir. */
                printf("ERR! \n"); return;
            
			    /* Error Handling here */
            }
             
        }
        
    }
    else
    {
        if( systemStartUp == STARTUP_INIT )
		{
		     /* ... */
		     
		     systemStartUp = STARTUP_POST_INIT;
		}
        else
		{
		    if( systemStartUp == STARTUP_POST_INIT)
		    {
		        
		        switch(ECU_STATE)
		        {
		            case ECUSTATE_INIT: /* Init Runnables are handle here */
		             
		            /*
		            retVal = AnalogConfiguration_ruInit();
		            if(retVal != EOK)
                    {
                     AnalogConfiguration_ruInit not successed, Error Handle here 
                    }
		            ...
		            ...
		            */
		        
		            /* init finished ecu go routine */
		            ECU_STATE = ECUSTATE_ROUTINE;
		            break;
		            
		            case ECUSTATE_ROUTINE: /* Routine Runnables are handle here */

                        //ruRefresh(); // Perform ECU base refresh operation

                        //Check processQueue
                        for(int checkProcessQueueIdx = 0 ; checkProcessQueueIdx < 5 ; checkProcessQueueIdx++)
                        {
                            if( PROCESSSTATE_DEFAULT != processQueue[checkProcessQueueIdx] )
                            {
                                 ECU_STATE = ECUSTATE_PROCESS;
                                 PROCESS_STATE = processQueue[checkProcessQueueIdx];
                                 if(processQueue[checkProcessQueueIdx] == PROCESSSTATE_TXSIGNALADAPTER)
                                 {
                                    TxSignalAdapter_processExecutionState = PROCESS_EXECUTION_START;
                                 }
                                 else if(processQueue[checkProcessQueueIdx] == PROCESSSTATE_ANALOGDATAWRAPPER)
                                 {
                                    AnalogDataWrapper_processExecutionState = PROCESS_EXECUTION_START;
                                 }
                                 else
                                 {
                                    /* Defensive Coding */
                                 }                               

                                 processQueue[checkProcessQueueIdx] = PROCESSSTATE_DEFAULT;
                                 break;
                            }
                        }

                        // Handle pending TxSignalAdapter process
                         if (PROCESS_STATE == PROCESSSTATE_TXSIGNALADAPTER && TxSignalAdapter_processExecutionState == PROCESS_EXECUTION_RUNNING)
                         {
                             // Increment the counter for the pending process
                             TxSignalAdapter_processRunningCounter++;           

                             if (TxSignalAdapter_processRunningCounter >= TxSignalAdapter_PROCESS_RUNNING_DURATION)
                             {
                                 ECU_STATE = ECUSTATE_PROCESS; // Return to PROCESS state
                             }
                         }


		       	         switch(REFRESH_STATE)
		       	         {
		       	             case REFRESHSTATE_ANALOGREAD : /* Analog Read ruRefresh */
		       	              
		       	                 
		       	                 REFRESH_STATE = REFRESHSTATE_COMMUNICATION;
		       	             
		       	             break;
		       	             
		       	             case REFRESHSTATE_COMMUNICATION: /* Communication ruRefresh */
		       	             
		       	                 
		       	                 REFRESH_STATE = REFRESHSTATE_ANALOGREAD;
		       	             break;
		       	             
		       	             /*******************************************************/
		       	             case REFRESHSTATE_SUSPEND: /* If Any Refresh state fails */
		       	             
		       	             
		       	                 REFRESH_STATE = REFRESHSTATE_DEFAULT;
		       	             break;
		       	             
		       	             default:  /* Error Handling here */
		       	             
		       	                /* Default State Schedules State Machine based on priority */
		       	                REFRESH_STATE = REFRESHSTATE_ANALOGREAD; //@LATER: Scheduling algorithm
		       	             break;
		       	            
		       	         }
		       	         
		       	         
		       	    
		       	    break;
		       	    
		       	    case ECUSTATE_PROCESS: /* Process Runnables are handle here */
                        
                        REFRESH_STATE = REFRESHSTATE_DEFAULT;

		       	        switch(PROCESS_STATE)
                        {
                            case PROCESSSTATE_ANALOGDATAWRAPPER:
                            
                                switch(AnalogDataWrapper_processExecutionState)
                                {
                                    case PROCESS_EXECUTION_UNKNOWN: 
                                        printf("ERR! \n"); return;
                                    break;
                                    
                                    case PROCESS_EXECUTION_START:
                                        AnalogDataWrapper_processExecutionState = PROCESS_EXECUTION_RUNNING; 
                                    break;
                                    
                                    case PROCESS_EXECUTION_RUNNING:
                                        // Single Call process ise, execution operasyonu gerçekleştikten sonra sonlacak 
                                        // AnalogDataWrapper_ruUpdateAnalogData();
                                    
                                        // Mark the process as finished
                                        AnalogDataWrapper_processExecutionState = PROCESS_EXECUTION_FINISHED;
                                    break;
                                        
                                    case PROCESS_EXECUTION_FINISHED:
                                    
                                        // Transition PROCESS_STATE to DEFAULT and ECU_STATE back to ROUTINE
                                        PROCESS_STATE = PROCESSSTATE_DEFAULT;
                                        AnalogDataWrapper_processExecutionState = PROCESS_EXECUTION_UNKNOWN;
                                    break;
                                }
                                
                            break;
                            
                            case PROCESSSTATE_TXSIGNALADAPTER:
                            
                                switch(TxSignalAdapter_processExecutionState)
                                {
                                    case PROCESS_EXECUTION_UNKNOWN: 
                                        printf("ERR! \n"); return;
                                    break;
                                    
                                    case PROCESS_EXECUTION_START:
                                        TxSignalAdapter_processRunningCounter = 1; // Reset counter
                                        TxSignalAdapter_processExecutionState = PROCESS_EXECUTION_RUNNING;
                                    break;
                                    
                                    case PROCESS_EXECUTION_RUNNING:
                                        // Single Call process değil, routine donecek bu process zamani geldiginde
                                        // kaldigi yerden calismaya devam edecek.
                                        // TxSignalAdapter_processExecutionState = PROCESS_EXECUTION_FINISHED; tamamlandiginda degisecek.
                                        
                                        if (TxSignalAdapter_processRunningCounter >= TxSignalAdapter_PROCESS_RUNNING_DURATION)
                                        {
                                            /* Second Call here */
                                            //TxSignalAdapter_ruPrepareAndSendData();
                                            
                                            TxSignalAdapter_processRunningCounter = 0;
                                            TxSignalAdapter_processExecutionState = PROCESS_EXECUTION_FINISHED;
                                        }
                                        else
                                        {
                                            /* First Call here */
                                            //TxSignalAdapter_ruPrepareAndSendData();
                                            
                                            // Return to ROUTINE to allow refresh cycles
                                            ECU_STATE = ECUSTATE_ROUTINE;
                                        }
                                        
                                        // TxSignalAdapter_ruSendSignal(&TxSignalAdapter_processExecutionState /*OpStatus*/ );
                                        
                                    break;
                                        
                                    case PROCESS_EXECUTION_FINISHED:
                                        // Transition PROCESS_STATE to DEFAULT and ECU_STATE back to ROUTINE
                                        PROCESS_STATE = PROCESSSTATE_DEFAULT;
                                        TxSignalAdapter_processExecutionState = PROCESS_EXECUTION_UNKNOWN;
                                    break;
                                }
                            
                            break;
                            
                            default:
                                /* Bu aşamada devam eden bir process yada beklemeye ihtiyacı olan bir
                                   process varsa, ecu state routine dönüp, process tamamlandığında ona geri gelen
                                   yapı kurulması gerekmektedir.
                                */
                                // Su anki örnek process single-call tarzında olduğu için process doğrudan bitirilmektedir.
                                ECU_STATE = ECUSTATE_ROUTINE;
		                        PROCESS_STATE = PROCESSSTATE_UNKNOWN;
                            break;
                        }
		       	    
		       	    break;
		       	    
		       	    case ECUSTATE_SUSPEND: /* Suspend State handle here */

		         
		                ECU_STATE = ECUSTATE_DEFAULT;
		            break;
		            
		            default: /* Error Handling and routine back control here here */
		            
		                ECU_STATE = ECUSTATE_ROUTINE;
		            break;
		        
		        }
		    }
		    else
		    {
		        printf("ERR! \n"); return;
		    }
		}
		
    }     
    
    // Print system state in one line
    printf("SysCount: %2d | Startup: %-10s | ECU_STATE: %-8s | REFRESH_STATE: %-13s | PROCESS_STATE: %-18s | ANALOG-DATA-PRG: %-8s | TX-SIGNAL: %-10s : %-5s \n",
       systemStartupStateCount,
       GetStartupStateName(systemStartUp),
       GetEcuStateName(ECU_STATE),
       GetRefreshStateName(REFRESH_STATE),
       GetProcessStateName(PROCESS_STATE),
       GetExecutionStateName(AnalogDataWrapper_processExecutionState),
       GetExecutionStateName(TxSignalAdapter_processExecutionState)  , GetExecutionStateCount(TxSignalAdapter_processRunningCounter) );
}     










