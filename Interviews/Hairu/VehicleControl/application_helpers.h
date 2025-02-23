#ifndef APPLICATION_HELPERS_H
#define APPLICATION_HELPERS_H


#define MAX_RPM     5000   // maximum RPM of the motor
#define MAX_TORQUE  300    // maximum torque (in Nm)


/**
 * @brief a structure to hold a motor command
 * 
 */
typedef struct {
    int speed;   // Motor speed in RPM
    int torque;  // Motor torque in Nm
} MotorCommand;

int Calculate_Speed_From_Gas(int gasPercentage);

int Calculate_Torque_From_Gas(int gasPercentage);

MotorCommand Create_Motor_Command(int speed, int torque);

#endif // APPLICATION_HELPERS_H
