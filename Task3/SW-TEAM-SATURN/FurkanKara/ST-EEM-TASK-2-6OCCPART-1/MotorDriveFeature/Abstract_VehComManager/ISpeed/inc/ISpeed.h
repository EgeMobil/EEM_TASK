#ifndef ISPEED_H_
#define ISPEED_H_

#include "Abstract_VehComManager.h"

typedef enum
{
    ISPEED_OK = 0,
    ISPEED_NOT_OK
}ISpeed_StatusType;


typedef struct
{
    /**
     * @brief Write the speed.
     * @param speed Speed to write.
     * @return Status of the operation.
     */
    ISpeed_StatusType (*writeSpeed)(cmSpeed speed);

    /**
     * @brief Read the current speed.
     * @return Current speed.
     */
    cmSpeed (*readSpeed)(void);
} ISpeed;

/**
 * @brief Global instance of the ISpeedStatus interface.
 */
extern ISpeed SpeedInterface;

ISpeed_StatusType ISpeed_writeSpeed_Impl(cmSpeed speed);
cmSpeed ISpeed_readSpeed_Impl(void);


#endif /* ISPEED_H_ */