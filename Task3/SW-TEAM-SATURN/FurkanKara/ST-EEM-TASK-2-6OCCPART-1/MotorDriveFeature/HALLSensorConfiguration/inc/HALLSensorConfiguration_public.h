#ifndef HALLSENSORCONFIGURATION_PUBLIC_H_
#define HALLSENSORCONFIGURATION_PUBLIC_H_

/* Include the public definition header */
#include "HALLSensorConfiguration_definition.h"

extern void HALLSensorConfiguration_CTOR(void);

extern dtHALLSensorConfiguration* HALLSensorConfiguration_GetInstance(void);

extern FUNC(void, HALLSensorConfiguration_ruInitialisation)(void);

extern FUNC(void, HALLSensorConfiguration_ruUpdateA)(void);
extern FUNC(void, HALLSensorConfiguration_ruUpdateB)(void);
extern FUNC(void, HALLSensorConfiguration_ruUpdateC)(void);

#endif /* HALLSENSORCONFIGURATION_PUBLIC_H_ */