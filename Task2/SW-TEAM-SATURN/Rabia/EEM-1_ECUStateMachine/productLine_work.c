#include <stdio.h>
#include <stdlib.h>
#include <productLine_work.h>

void materialCheck() {
    // Read material check data from sensors
   
    if (sensor_error()) {
        errorCode = SENSOR_ERROR;
    } else {
        errorCode = NO_ERROR;
    }
}

void startProduction() {
    // Start production using actuators
    
    if (actuator_error()) {
        errorCode = ACTUATOR_ERROR;
    } else {
        errorCode = NO_ERROR;
    }
}

void processContinue() {
    // Continue production process
    
    if (process_error()) {
        errorCode = PROCESS_ERROR;
    } else {
        errorCode = NO_ERROR;
    }
}

void productOutput() {
    // Output the product
    
    if (actuator_error()) {
        errorCode = ACTUATOR_ERROR;
    } else {
        errorCode = NO_ERROR;
    }
}

void handleError() {
    // Handle error state
    printf("Error State: %d\n", errorCode);
    // Error handling procedures ...
  
    errorCode = NO_ERROR;
    currentState = MATERIAL_CHECK;
}

void emergencyStopProcedure() {
    // Handle emergency stop procedure
    printf("Emergency Stop Procedure\n");
    // Emergency stop actions ...
   
    emergencyStop = false; // Reset flag
    currentState = MATERIAL_CHECK;
}

void qualityControl(){
    //Perform quality control...
   
    if(quality_control_result_read()){
        errorCode = NO_ERROR;
    } else {
        errorCode = MATERIAL_ERROR;
    }
}