/**
 * @brief Sensor Data Processing System with Callback Architecture
 *
 * This system implements a flexible sensor data processing framework using callback functions
 * and enumerated states for sensor selection.
 *
 * Components:
 * - Sensor Types:
 *   - Temperature: Measures temperature in °C (0-100°C range)
 *   - Humidity: Measures relative humidity in % (0-100% range)
 *   - Light: Measures ambient light in lux (0-1000 lux range)
 *
 * Architecture:
 * - Uses callback functions for modular sensor handling
 * - Implements state-based sensor selection
 * - Provides structured data storage using sensor_data struct
 *
 * States:
 * - waiting: Initial state, waiting for user input
 * - temp: Temperature measurement active
 * - humidity: Humidity measurement active
 * - light: Light measurement active
 *
 * Description:
 * The system allows users to select different sensor types through a menu interface.
 * Each sensor implements a callback function that generates simulated sensor data
 * using random values within appropriate ranges for each measurement type.
 * The system maintains extensibility for adding new sensor types.
 *
 * @author Furkan Türker Akşit
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    waiting,
    temp,
    humidity,
    light

} sensor_callback_flags_t;

typedef struct
{
    float value;
    char *unit;
} sensor_data;

int temperature_callback(sensor_data *data)
{
    data->value = ((float)rand() / (float)(RAND_MAX)) * 100.0f;
    data->unit = "°C";
    printf("Temperature: %.1f%s\n", data->value, data->unit);
    return 0;
}

int humidity_callback(sensor_data *data)
{
    data->value = ((float)rand() / (float)(RAND_MAX)) * 100.0f;
    data->unit = "%";
    printf("Humidity: %s%.1f\n", data->unit, data->value);
}

int light_callback(sensor_data *data)
{
    data->value = ((float)rand() / (float)(RAND_MAX)) * 1000.0f;
    data->unit = "lux";
    printf("Light Level: %.1f%s\n", data->value, data->unit);
}

int sensor_runner(sensor_callback_flags_t sensor)
{
    if (sensor == temp)
    {
        sensor_data data = {0.0f, NULL};
        temperature_callback(&data);
    }

    else if (sensor == humidity)
    {
        sensor_data data = {0.0f, NULL};
        humidity_callback(&data);
    }

    else if (sensor == light)
    {
        sensor_data data = {0.0f, NULL};
        light_callback(&data);
    }

    else
    {
        printf("Invalid sensor type\n");
    }
}
int sensor_chooser()
{
    int choice;
    sensor_callback_flags_t sensor;
    sensor = waiting;
    while (1)
    {
        printf("\nSelect Sensor Type:\n");
        printf("1. Temperature Sensor\n");
        printf("2. Humidity Sensor\n");
        printf("3. Light Sensor\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            sensor = temp;
            sensor_runner(sensor);
            break;
        case 2:
            sensor = humidity;
            sensor_runner(sensor);
            break;
        case 3:
            sensor = light;
            sensor_runner(sensor);
            break;
        case 4:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}

void main()
{
    sensor_chooser();
}