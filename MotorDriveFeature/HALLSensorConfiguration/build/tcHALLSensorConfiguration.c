#include "tcHALLSensorConfiguration.h"

#include <time.h>

/* Binary formatlama fonksiyonu */
void printBinary(uint8_t value)
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (value >> i) & 1);
    }
}

void tcHALLSensorConfiguration(void)
{
#ifndef defined(STM32G431xx)
    printf("HALLSensorConfiguration \n");
#endif

    /* CTOR */
    HALLSensorConfiguration_CTOR();

    /* Get Singleton Instance For Test */
    dtHALLSensorConfiguration* manager = HALLSensorConfiguration_GetInstance();

    /* Read HALLSensorConfiguration Status before Initialisation */
#ifndef defined(STM32G431xx)
    printf("[PRE-INIT] %s \n", manager->toString());
#endif

    /* 100 step test for initial condition */
    HALLAInterface.writeStatus(HALLA_STATUS_HIGH);
    HALLBInterface.writeStatus(HALLA_STATUS_LOW);
    HALLCInterface.writeStatus(HALLA_STATUS_LOW);

    /* Initalize HALLSensorConfiguration */
    HALLSensorConfiguration_ruInitialisation();

    /* Read HALLSensorConfiguration Status after Initialisation */
#ifndef defined(STM32G431xx)
    printf("[POST-INIT] %s \n", manager->toString());
#endif

    // Hall Step 1: Hall Code = 100
#ifndef defined(STM32G431xx)
    printf("\nStep 1: Hall Code = 100\n");
#endif
    // Hall A = High, Hall B = Low, Hall C = Low
    HALLAInterface.writeRisingEdgeAFlag(HALLA_RISING_EDGE_SET);
    HALLAInterface.writeFallingEdgeAFlag(HALLA_FALLING_EDGE_RESET);
    HALLBInterface.writeRisingEdgeBFlag(HALLB_RISING_EDGE_UNKNOWN);
    HALLBInterface.writeFallingEdgeBFlag(HALLB_FALLING_EDGE_UNKNOWN);
    HALLCInterface.writeRisingEdgeCFlag(HALLC_RISING_EDGE_UNKNOWN);
    HALLCInterface.writeFallingEdgeCFlag(HALLC_FALLING_EDGE_UNKNOWN);
    // Update Hall Sensor Configuration
    HALLSensorConfiguration_ruUpdateA();
#ifndef defined(STM32G431xx)
    printf("%s \n", manager->toString());
    printf("PWMSTEP_A = %d \n",PwmStepInterface.readPwmStepA());
    printf("PWMSTEP_B = %d \n",PwmStepInterface.readPwmStepB());
    printf("PWMSTEP_C = %d \n",PwmStepInterface.readPwmStepC());
#endif
    
    // Hall Step 2: Hall Code = 110
#ifndef defined(STM32G431xx)
    printf("\nStep 2: Hall Code = 110\n");
#endif
    // Hall A = High, Hall B = High, Hall C = Low
    HALLAInterface.writeRisingEdgeAFlag(HALLA_RISING_EDGE_UNKNOWN);
    HALLAInterface.writeFallingEdgeAFlag(HALLA_FALLING_EDGE_UNKNOWN);
    HALLBInterface.writeRisingEdgeBFlag(HALLB_RISING_EDGE_SET);
    HALLBInterface.writeFallingEdgeBFlag(HALLB_FALLING_EDGE_RESET);
    HALLCInterface.writeRisingEdgeCFlag(HALLC_RISING_EDGE_UNKNOWN);
    HALLCInterface.writeFallingEdgeCFlag(HALLC_FALLING_EDGE_UNKNOWN);
    // Update Hall Sensor Configuration
    HALLSensorConfiguration_ruUpdateB();
#ifndef defined(STM32G431xx)
    printf("%s \n", manager->toString());
    printf("PWMSTEP_A = %d \n",PwmStepInterface.readPwmStepA());
    printf("PWMSTEP_B = %d \n",PwmStepInterface.readPwmStepB());
    printf("PWMSTEP_C = %d \n",PwmStepInterface.readPwmStepC());
#endif
    
    // Hall Step 3: Hall Code = 010
#ifndef defined(STM32G431xx)
    printf("\nStep 3: Hall Code = 010\n");
#endif
    // Hall A = Low, Hall B = High, Hall C = Low
    HALLAInterface.writeRisingEdgeAFlag(HALLA_RISING_EDGE_RESET);
    HALLAInterface.writeFallingEdgeAFlag(HALLA_FALLING_EDGE_SET);
    HALLBInterface.writeRisingEdgeBFlag(HALLB_RISING_EDGE_UNKNOWN);
    HALLBInterface.writeFallingEdgeBFlag(HALLB_FALLING_EDGE_UNKNOWN);
    HALLCInterface.writeRisingEdgeCFlag(HALLC_RISING_EDGE_UNKNOWN);
    HALLCInterface.writeFallingEdgeCFlag(HALLC_FALLING_EDGE_UNKNOWN);
    
    // Update Hall Sensor Configuration
    HALLSensorConfiguration_ruUpdateA();
#ifndef defined(STM32G431xx)
    printf("%s \n", manager->toString());
    printf("PWMSTEP_A = %d \n",PwmStepInterface.readPwmStepA());
    printf("PWMSTEP_B = %d \n",PwmStepInterface.readPwmStepB());
    printf("PWMSTEP_C = %d \n",PwmStepInterface.readPwmStepC());
#endif
    
    // Hall Step 4: Hall Code = 011
#ifndef defined(STM32G431xx)
    printf("\nStep 4: Hall Code = 011\n");
#endif
    // Hall A = Low, Hall B = High, Hall C = High
    HALLAInterface.writeRisingEdgeAFlag(HALLA_RISING_EDGE_UNKNOWN);
    HALLAInterface.writeFallingEdgeAFlag(HALLA_FALLING_EDGE_UNKNOWN);
    HALLBInterface.writeRisingEdgeBFlag(HALLB_RISING_EDGE_UNKNOWN);
    HALLBInterface.writeFallingEdgeBFlag(HALLB_FALLING_EDGE_UNKNOWN);
    HALLCInterface.writeRisingEdgeCFlag(HALLC_RISING_EDGE_SET);
    HALLCInterface.writeFallingEdgeCFlag(HALLC_FALLING_EDGE_RESET);
    // Update Hall Sensor Configuration
    HALLSensorConfiguration_ruUpdateC();
#ifndef defined(STM32G431xx)
    printf("%s \n", manager->toString());
    printf("PWMSTEP_A = %d \n",PwmStepInterface.readPwmStepA());
    printf("PWMSTEP_B = %d \n",PwmStepInterface.readPwmStepB());
    printf("PWMSTEP_C = %d \n",PwmStepInterface.readPwmStepC());
#endif

    // Hall Step 5: Hall Code = 001
#ifndef defined(STM32G431xx)
    printf("\nStep 5: Hall Code = 001\n");
#endif
    // Hall A = Low, Hall B = Low, Hall C = High
    HALLAInterface.writeRisingEdgeAFlag(HALLA_RISING_EDGE_UNKNOWN);
    HALLAInterface.writeFallingEdgeAFlag(HALLA_FALLING_EDGE_UNKNOWN);
    HALLBInterface.writeRisingEdgeBFlag(HALLB_RISING_EDGE_RESET);
    HALLBInterface.writeFallingEdgeBFlag(HALLB_FALLING_EDGE_SET);
    HALLCInterface.writeRisingEdgeCFlag(HALLC_RISING_EDGE_UNKNOWN);
    HALLCInterface.writeFallingEdgeCFlag(HALLC_FALLING_EDGE_UNKNOWN);
    // Update Hall Sensor Configuration
    HALLSensorConfiguration_ruUpdateB();
#ifndef defined(STM32G431xx)
    printf("%s \n", manager->toString());
    printf("PWMSTEP_A = %d \n",PwmStepInterface.readPwmStepA());
    printf("PWMSTEP_B = %d \n",PwmStepInterface.readPwmStepB());
    printf("PWMSTEP_C = %d \n",PwmStepInterface.readPwmStepC());
#endif
    
    // Hall Step 6: Hall Code = 101
#ifndef defined(STM32G431xx)
    printf("\nStep 6: Hall Code = 101\n");
#endif
    // Hall A = High, Hall B = Low, Hall C = High
    HALLAInterface.writeRisingEdgeAFlag(HALLA_RISING_EDGE_SET);
    HALLAInterface.writeFallingEdgeAFlag(HALLA_FALLING_EDGE_RESET);
    HALLBInterface.writeRisingEdgeBFlag(HALLB_RISING_EDGE_UNKNOWN);
    HALLBInterface.writeFallingEdgeBFlag(HALLB_FALLING_EDGE_UNKNOWN);
    HALLCInterface.writeRisingEdgeCFlag(HALLC_RISING_EDGE_UNKNOWN);
    HALLCInterface.writeFallingEdgeCFlag(HALLC_FALLING_EDGE_UNKNOWN);
    // Update Hall Sensor Configuration
    HALLSensorConfiguration_ruUpdateA();
#ifndef defined(STM32G431xx)
    printf("%s \n", manager->toString());
    printf("PWMSTEP_A = %d \n",PwmStepInterface.readPwmStepA());
    printf("PWMSTEP_B = %d \n",PwmStepInterface.readPwmStepB());
    printf("PWMSTEP_C = %d \n",PwmStepInterface.readPwmStepC());
#endif

}
