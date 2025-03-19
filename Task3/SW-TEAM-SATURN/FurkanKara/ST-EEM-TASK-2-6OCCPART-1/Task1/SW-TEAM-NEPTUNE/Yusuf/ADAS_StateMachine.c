#include <stdio.h>
#include <stdbool.h>

// Define the possible states
typedef enum
{
	STATE_WAITING,
	STATE_CAMERA_CHECK,
	STATE_LANE_KEEP,
	STATE_LANE_ADJUSTMENT,
	STATE_EMERGENCY
} State;

// Define the possible events
typedef enum
{
	EVT_NONE,
	EVT_SYSTEM_START,
	EVT_CAMERA_OK,
	EVT_CAMERA_FAIL,
	EVT_LANE_DEPARTURE,
	EVT_ADJUSTMENT_COMPLETE,
	EVT_EMERGENCY_CONDITION,
	EVT_RESET
} Event;

// Current state of the system
State currentState = STATE_WAITING;

// Function prototypes for actions
void initSensors();
void beginLaneMonitoring();
void engageLaneAdjustment();
void resumeLaneKeeping();
void handleEmergency();
void resetSystem();

// State machine transition function
void handleEvent(Event evt)
{
	switch (currentState)
	{
	case STATE_WAITING:
		if (evt == EVT_SYSTEM_START)
		{
			// Action: Initialize sensors and camera
			initSensors();
			currentState = STATE_CAMERA_CHECK;
			printf("Transition: WAITING -> CAMERA_CHECK\n");
		}
		break;

	case STATE_CAMERA_CHECK:
		if (evt == EVT_CAMERA_OK)
		{
			// Action: Begin lane monitoring
			beginLaneMonitoring();
			currentState = STATE_LANE_KEEP;
			printf("Transition: CAMERA_CHECK -> LANE_KEEP\n");
		}
		else if (evt == EVT_CAMERA_FAIL)
		{
			// Action: Raise emergency
			handleEmergency();
			currentState = STATE_EMERGENCY;
			printf("Transition: CAMERA_CHECK -> EMERGENCY\n");
		}
		break;

	case STATE_LANE_KEEP:
		if (evt == EVT_LANE_DEPARTURE)
		{
			// Action: Engage lane adjustment
			engageLaneAdjustment();
			currentState = STATE_LANE_ADJUSTMENT;
			printf("Transition: LANE_KEEP -> LANE_ADJUSTMENT\n");
		}
		else if (evt == EVT_EMERGENCY_CONDITION)
		{
			// Action: Handle emergency condition
			handleEmergency();
			currentState = STATE_EMERGENCY;
			printf("Transition: LANE_KEEP -> EMERGENCY\n");
		}
		break;

	case STATE_LANE_ADJUSTMENT:
		if (evt == EVT_ADJUSTMENT_COMPLETE)
		{
			// Action: Resume normal lane keeping
			resumeLaneKeeping();
			currentState = STATE_LANE_KEEP;
			printf("Transition: LANE_ADJUSTMENT -> LANE_KEEP\n");
		}
		else if (evt == EVT_EMERGENCY_CONDITION)
		{
			// Action: Handle emergency condition
			handleEmergency();
			currentState = STATE_EMERGENCY;
			printf("Transition: LANE_ADJUSTMENT -> EMERGENCY\n");
		}
		break;

	case STATE_EMERGENCY:
		if (evt == EVT_RESET)
		{
			// Action: Reset system and clear errors
			resetSystem();
			currentState = STATE_WAITING;
			printf("Transition: EMERGENCY -> WAITING\n");
		}
		break;

	default:
		break;
	}
}

// Action function implementations
void initSensors()
{
	// Initialization code for sensors and camera
	printf("Initializing sensors and camera...\n");
}

void beginLaneMonitoring()
{
	// Code to start lane monitoring
	printf("Camera OK. Starting lane monitoring...\n");
}

void engageLaneAdjustment()
{
	// Code to adjust vehicle position (e.g., control steering)
	printf("Lane departure detected. Adjusting lane position...\n");
}

void resumeLaneKeeping()
{
	// Code to resume normal lane keeping operation
	printf("Lane adjustment complete. Resuming lane keeping...\n");
}

void handleEmergency()
{
	// Code to handle emergency (e.g., alert driver, decelerate)
	printf("Emergency condition detected! Engaging emergency protocols...\n");
}

void resetSystem()
{
	// Code to reset system and clear errors
	printf("Resetting system to initial state...\n");
}

// Example of simulating events
int main()
{

	// Since there is no live data to feed the system, for testing purposes, I will handle each event in series

	// Simulate system start event
	handleEvent(EVT_SYSTEM_START);

	// Simulate a successful camera check
	handleEvent(EVT_CAMERA_OK);

	// Simulate lane departure event triggering lane adjustment
	handleEvent(EVT_LANE_DEPARTURE);

	// Simulate adjustment completion event
	handleEvent(EVT_ADJUSTMENT_COMPLETE);

	// Simulate an emergency condition in lane keep state
	handleEvent(EVT_EMERGENCY_CONDITION);

	// Reset the system from emergency state
	handleEvent(EVT_RESET);

	return 0;
}
