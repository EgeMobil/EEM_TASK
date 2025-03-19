/**
 * @brief Automatic Irrigation System States
 *
 * This state machine manages the irrigation system based on data from the soil moisture sensor.
 *
 * States:
 * - Moisture Measurement: Data is collected from the soil moisture sensor.
 * - Water Level Control: Checks the water level.
 * - Irrigation On/Off: Turns the irrigation system on or off based on the moisture level.
 * - Waiting: Waits for the next measurement.
 *
 * Description:
 * The irrigation system is turned on or off based on data from the soil moisture sensor.
 *
 * @author Furkan Türker Akşit
 */

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int ITERATION = 5;

typedef enum
{
    MOISTURE_MEASUREMENT,
    WATER_LEVEL_CONTROL,
    IRRIGATION_ON_OFF,
    WAITING
} irrigation_system_state_t;

typedef enum
{
    MEASUREMENT,
    LOW,
    MEDIUM,
    HIGH
} moisture_level_t;

moisture_level_t get_random_moisture_level()
{
    srand(time(NULL));
    return (moisture_level_t)(rand() % 3 + 1);
}

typedef enum
{
    WATER_MEASUREMENT,
    EMPTY,
    LOW_WATER,
    ENOUGH_WATER
} water_level_t;

water_level_t get_random_water_level()
{
    srand(time(NULL));
    return (water_level_t)(rand() % 3 + 1);
}

const char *moisture_level_strings[] = {
    "MEASUREMENT",
    "LOW",
    "MEDIUM",
    "HIGH"};

const char *water_level_strings[] = {
    "WATER_MEASUREMENT",
    "EMPTY",
    "LOW_WATER",
    "ENOUGH_WATER"};

void irrigation_on_off(moisture_level_t *moisture_level, water_level_t *water_level)
{
    if (*water_level == WATER_MEASUREMENT || *moisture_level == MEASUREMENT)
    {
        printf("Moisture Measuring...\n");
        sleep(1);                                      // Wait for 1 second
        *moisture_level = get_random_moisture_level(); // Get random moisture level
        printf("Water Level Measuring...\n");
        sleep(1);                                // Wait for 1 second
        *water_level = get_random_water_level(); // Get random water level
    }
    else if (*water_level == ENOUGH_WATER && *moisture_level == LOW)
    {
        printf("Water Level = %s\n", water_level_strings[*water_level]);
        printf("Moisture Level = %s\n", moisture_level_strings[*moisture_level]);
        printf("Irrigation System is ON\n");
        sleep(1); // Wait for 1 second
        *water_level = WATER_MEASUREMENT;
        *moisture_level = MEASUREMENT;
        printf("Irrigation System is OFF\n");
    }
    else if (*water_level == ENOUGH_WATER && *moisture_level == MEDIUM)
    {
        printf("Water Level = %s\n", water_level_strings[*water_level]);
        printf("Moisture Level = %s\n", moisture_level_strings[*moisture_level]);
        printf("System conditions are at appropriate level\n");
        printf("There is no need to run irrigation\n");
        sleep(1); // Wait for 1 second
        *water_level = WATER_MEASUREMENT;
        *moisture_level = MEASUREMENT;
    }
    else if (*water_level == ENOUGH_WATER && *moisture_level == HIGH)
    {
        printf("Water Level = %s\n", water_level_strings[*water_level]);
        printf("Moisture Level = %s\n", moisture_level_strings[*moisture_level]);
        printf("System moisture level already high\n");
        printf("There is no need to run irrigation\n");
        sleep(1); // Wait for 1 second
        *water_level = WATER_MEASUREMENT;
        *moisture_level = MEASUREMENT;
    }
    else if (*water_level == LOW_WATER && *moisture_level == LOW)
    {
        printf("Water Level = %s\n", water_level_strings[*water_level]);
        printf("Moisture Level = %s\n", moisture_level_strings[*moisture_level]);
        printf("Water levet at critic level be careful\n");
        printf("Irrigation System is ON\n");
        sleep(1); // Wait for 1 second
        *water_level = WATER_MEASUREMENT;
        *moisture_level = MEASUREMENT;
        printf("Irrigation System is OFF\n");
    }
    else if (*water_level == LOW_WATER && *moisture_level == MEDIUM)
    {
        printf("Water Level = %s\n", water_level_strings[*water_level]);
        printf("Moisture Level = %s\n", moisture_level_strings[*moisture_level]);
        printf("System conditions are at appropriate level\n");
        printf("There is no need to run irrigation\n");
        sleep(1); // Wait for 1 second
        *water_level = WATER_MEASUREMENT;
        *moisture_level = MEASUREMENT;
    }
    else if (*water_level == LOW_WATER && *moisture_level == HIGH)
    {
        printf("Water Level = %s\n", water_level_strings[*water_level]);
        printf("Moisture Level = %s\n", moisture_level_strings[*moisture_level]);
        printf("System moisture level already high\n");
        printf("There is no need to run irrigation\n");
        sleep(1); // Wait for 1 second
        *water_level = WATER_MEASUREMENT;
        *moisture_level = MEASUREMENT;
    }
    else if (*water_level == EMPTY && *moisture_level == LOW)
    {
        printf("Water Level = %s\n", water_level_strings[*water_level]);
        printf("Moisture Level = %s\n", moisture_level_strings[*moisture_level]);
        printf("Irrigation System doesn't have water\n");
        printf("System can't work\n");
        sleep(1); // Wait for 1 second
        *water_level = WATER_MEASUREMENT;
        *moisture_level = MEASUREMENT;
    }
    else if (*water_level == EMPTY && *moisture_level == MEDIUM)
    {
        printf("Water Level = %s\n", water_level_strings[*water_level]);
        printf("Moisture Level = %s\n", moisture_level_strings[*moisture_level]);
        printf("Irrigation System doesn't have water\n");
        printf("System can't work\n");
        sleep(1); // Wait for 1 second
        *water_level = WATER_MEASUREMENT;
        *moisture_level = MEASUREMENT;
    }
    else if (*water_level == EMPTY && *moisture_level == HIGH)
    {
        printf("Water Level = %s\n", water_level_strings[*water_level]);
        printf("Moisture Level = %s\n", moisture_level_strings[*moisture_level]);
        printf("System moisture level already high\n");
        printf("There is no need to run irrigation\n");
        sleep(1); // Wait for 1 second
        *water_level = WATER_MEASUREMENT;
        *moisture_level = MEASUREMENT;
    }
}

int main()
{
    irrigation_system_state_t state = MOISTURE_MEASUREMENT;
    moisture_level_t moisture_level = MEASUREMENT;
    water_level_t water_level = WATER_MEASUREMENT;

    printf("Irrigation System State Machine\n");
    printf("System Starting...\n");

    for (int i = 0; i < ITERATION;)
    {
        srand(time(NULL));
        switch (state)
        {
        case MOISTURE_MEASUREMENT:
            printf("Moisture Measuring...\n");
            sleep(1);                                     // Wait for 1 second
            moisture_level = get_random_moisture_level(); // Get random moisture level
            state = WATER_LEVEL_CONTROL;
            break;
        case WATER_LEVEL_CONTROL:
            printf("Water Level Measuring...\n");
            sleep(1);                               // Wait for 1 second
            water_level = get_random_water_level(); // Get random water level
            state = IRRIGATION_ON_OFF;
            break;
        case IRRIGATION_ON_OFF:
            irrigation_on_off(&moisture_level, &water_level);
            state = WAITING;
            break;
        case WAITING:
            printf("Waiting...\n");
            printf("----------------------------------------------------------------\n");
            sleep(2); // Wait for 2 second
            state = MOISTURE_MEASUREMENT;
            i++;
            break;
        }
    }
    printf("System Closing...\n");
    printf("****************************************\n");
    return 0;
}