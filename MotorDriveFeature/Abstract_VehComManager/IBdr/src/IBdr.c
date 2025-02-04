#include "IBdr.h"

IBdr BdrInterface = {
    .writeBdr = IBdr_writeBdr_Impl,
    .readBdr = IBdr_readBdr_Impl,
};

static cmBdr currentBdr = 0;

/**
 * @brief Implementation for writing the bdr.
 * @param speed bdr to write.
 * @return Status of the operation.
 */
IBdr_StatusType IBdr_writeBdr_Impl(cmBdr bdr)
{
    // bdr constraints are assumed to be globally handled in the system.
    currentBdr = bdr;
#ifndef STM32G431xx

    printf("[IBdr] bdr written: %u\n", bdr);
#endif    
    return IBDR_OK;
}

/**
 * @brief Implementation for reading the bdr.
 * @return Current bdr status.
 */
cmBdr IBdr_readBdr_Impl(void)
{
#ifndef STM32G431xx
    printf("[IBdr] bdr  read: %u\n", currentBdr);
    #endif    
    return currentBdr;
}
