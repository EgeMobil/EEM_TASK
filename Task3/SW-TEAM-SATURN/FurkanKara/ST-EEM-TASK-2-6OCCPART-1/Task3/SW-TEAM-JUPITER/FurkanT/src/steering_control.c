/**
 * @brief Steering Control System
 *
 * Components:
 * - Public Interface:
 *   - Steering_setAngle(): Sets the steering angle within defined vehicle limits.
 *   - Steering_getAngle(): Returns the current steering angle.
 *   - Steering_calibrate(): Executes sensor-based calibration.
 * - Private Structures:
 *   - Contains hidden variables for steering angle calculations and calibration data,
 *     ensuring encapsulation of internal logic.
 * - Vehicle Limits:
 *   - Predefined maximum and minimum steering angles ensure safe and accurate control.
 *
 * Architecture:
 * - Encapsulation: Internal calculation algorithms and data are hidden in private modules,
 *   inaccessible from external code.
 * - Functional Separation: The public API handles user interactions, while private modules manage
 *   the underlying processing and calibration tasks.
 * - OOP Approach: A modular and flexible design is achieved using object-oriented programming concepts in C.
 *
 * Description:
 * The system processes sensor data to adjust the steering angle in a precise and safe manner,
 * applying necessary calibration and exposing a user-friendly interface. Its extensible design allows for
 * the addition of new sensor types or advanced control algorithms in the future.
 *
 *
 * @author Furkan Türker Akşit
 */
#include "steering_control_public.h"
#include "steering_control_private.h"

#include <stdio.h>

// This static variable is only accessible within this file (encapsulation)
static SteeringControl steeringControl = {0.0, 0.0, 0.0};

// Private helper function: calculates the steering angle from sensor data.
static double calculateSteeringAngle(double sensorInput)
{
	// Example calculation: add calibration offset to sensor input.
	return sensorInput + steeringControl.calibrationOffset;
}

// Implementations of public functions:

// Sets the steering angle to the specified value.
void Steering_setAngle(double angle)
{
	// The angle is kept within vehicle limits.
	if (angle > MAX_STEERING_ANGLE)
		angle = MAX_STEERING_ANGLE;
	else if (angle < MIN_STEERING_ANGLE)
		angle = MIN_STEERING_ANGLE;

	// Use the angle as the raw value from sensor data.
	steeringControl.sensorValue = angle;
	// The calculated angle is determined including the calibration effect.
	steeringControl.currentAngle = calculateSteeringAngle(steeringControl.sensorValue);
	printf("Steering angle set: %.2f degrees\n", steeringControl.currentAngle);
}

// Returns the current steering angle.
double Steering_getAngle(void)
{
	return steeringControl.currentAngle;
}

// The calibration process sets the offset for correct sensor readings.
void Steering_calibrate(void)
{
	// For example, take the current sensor value as the zeroing offset.
	steeringControl.calibrationOffset = -steeringControl.sensorValue;
	// Recalculate the angle after calibration.
	steeringControl.currentAngle = calculateSteeringAngle(steeringControl.sensorValue);
	printf("Calibration completed. New offset: %.2f\n", steeringControl.calibrationOffset);
}
