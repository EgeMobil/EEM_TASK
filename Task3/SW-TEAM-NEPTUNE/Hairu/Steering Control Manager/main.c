#include <stdio.h>
#include <stdlib.h>
#include "steering_control_public.h"

int main(void) {
    // Creating a SteeringControl object
    SteeringControl steering = Steering_create();

    // ornek steering offset
    steering.calibrate(&steering, 2);

    // Set angle to 10 degrees
    steering.setAngle(&steering, 10);
    printf("Steering angle after set: %d\n", steering.getAngle(&steering));

    // Trying to set angle beyond the maximum limit
    steering.setAngle(&steering, 50);
    printf("Steering angle after out-of-range set: %d\n", steering.getAngle(&steering));

    // Clean up (free memory)
    free(steering.data); 

    return 0;
}
