#ifndef IBDR_H_
#define IBDR_H_

#include "Abstract_VehComManager.h"

typedef enum
{
    IBDR_OK = 0,
    IBDR_NOT_OK
}IBdr_StatusType;


typedef struct
{
    /**
     * @brief Write the speed.
     * @param speed Speed to write.
     * @return Status of the operation.
     */
    IBdr_StatusType (*writeBdr)(cmSpeed bdr);

    /**
     * @brief Read the current speed.
     * @return Current speed.
     */
    cmBdr (*readBdr)(void);
} IBdr;

/**
 * @brief Global instance of the ISpeedStatus interface.
 */
extern IBdr BdrInterface;

IBdr_StatusType IBdr_writeBdr_Impl(cmSpeed speed);
cmBdr IBdr_readBdr_Impl(void);


#endif /* IBDR_H_ */