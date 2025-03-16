#include "steering_control_public.h"
#include <stdio.h>

int main()
{
	// Set the steering angle.
	Steering_setAngle(30.0);
	// Get the steering angle and print it.
	printf("Current steering angle: %.2f degrees\n", Steering_getAngle());
	// Perform calibration.
	Steering_calibrate();
	// Get the steering angle and print it.
	printf("Current steering angle: %.2f degrees\n", Steering_getAngle());

	return 0;
}