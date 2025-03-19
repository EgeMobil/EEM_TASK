#include <system_include.h>


volatile bool emergencyStop = false; 

// Interrupt service routine (ISR)
void emergencyStopISR() {
  emergencyStop = true;
}

int main() {
    hal_init();
	system_init();

    // Configure interrupt
    hal_interrupt(EMERGENCY_STOP_BUTTON_PIN, emergencyStopISR, FALLING); // Trigger on falling edge

    while (1) {
       
       if (emergencyStop) {
            currentState = EMERGENCY_STOP;
        }

        switch (currentState) {
            case MATERIAL_CHECK:
                printf("Material check in progress...\n");
                materialCheck();
                if (errorCode == NO_ERROR) {
                    qualityControl();
                    if (errorCode == NO_ERROR) {
                        currentState = START_PRODUCTION;
                    } else {
                        currentState = ERROR;
                    }
                } else {
                    currentState = ERROR;
                }
                break;
            case START_PRODUCTION:
                printf("Starting production...\n");
                startProduction();
                if (errorCode == NO_ERROR) {
                    currentState = PROCESS_CONTINUE;
                } else {
                    currentState = ERROR;
                }
                break;
            case PROCESS_CONTINUE:
                printf("Process continues...\n");
                processContinue();
                if (errorCode == NO_ERROR) {
                    qualityControl();
                    if (errorCode == NO_ERROR) {
                        currentState = PRODUCT_OUTPUT;
                    } else {
                        currentState = ERROR;
                    }
                } else {
                    currentState = ERROR;
                }
                break;
            case PRODUCT_OUTPUT:
                printf("Product output in progress...\n");
                productOutput();
                if (errorCode == NO_ERROR) {
                    currentState = MATERIAL_CHECK;
                } else {
                    currentState = ERROR;
                }
                break;
            case ERROR:
                handleError();
                break;
            case EMERGENCY_STOP:
                emergencyStopProcedure();
                break;
        }
        hal_delay(1000);
    }
    return 0;
}

