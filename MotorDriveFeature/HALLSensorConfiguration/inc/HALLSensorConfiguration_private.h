#ifndef HALLSENSORCONFIGURATION_PRIVATE_H_
#define HALLSENSORCONFIGURATION_PRIVATE_H_

#include "HALLSensorConfiguration_definition.h"

/**
 * @brief Constructor function for Hall Sensor Configuration.
 */
void HALLSensorConfiguration_CTOR(void);

/**
 * @brief Getter for the singleton instance of Hall Sensor Configuration.
 * @return Pointer to the singleton instance of the configuration.
 */
dtHALLSensorConfiguration* HALLSensorConfiguration_GetInstance(void);

FUNC(void, HALLSensorConfiguration_ruInitialisation)(void);

FUNC(void, HALLSensorConfiguration_ruUpdateA)(void);
FUNC(void, HALLSensorConfiguration_ruUpdateB)(void);
FUNC(void, HALLSensorConfiguration_ruUpdateC)(void);


#endif /* HALLSENSORCONFIGURATION_PRIVATE_H_ */