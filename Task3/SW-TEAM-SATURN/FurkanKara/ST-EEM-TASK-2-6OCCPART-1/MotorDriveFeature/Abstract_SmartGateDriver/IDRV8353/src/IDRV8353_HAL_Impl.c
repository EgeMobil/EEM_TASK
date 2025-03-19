#include "IDRV8353.h"
#include "drv8353.h"
#include "stm32g4xx_hal.h"

/* SPI Handle */
extern SPI_HandleTypeDef hspi1; /**< SPI handle used for DRV8353 communication */

/**
 * @brief Initializes the DRV8353 motor driver via SPI communication.
 * @retval IDRV8353_StatusType (IDRV8353_OK or IDRV8353_NOT_OK)
 */
IDRV8353_StatusType IDRV8353_Init_HAL(void)
{
    /* Initialize DRV8353 driver */
    DRV8353_Init();
    HAL_Delay(100);

    /* Verify the connection by reading a register */
    uint16_t testRead = DRV8353_Read(DRVREG_CTRL);
    if (testRead == 0xFFFF) // Invalid response
    {
        return IDRV8353_NOT_OK;
    }

    return IDRV8353_OK;
}

/**
 * @brief Reads a register from the DRV8353 chip.
 * @param reg_addr Register address to read.
 * @return The 16-bit register value.
 */
uint16_t IDRV8353_ReadRegister_HAL(uint8_t reg_addr)
{
    return DRV8353_Read(reg_addr);
}

/**
 * @brief Writes a value to a register in the DRV8353 chip.
 * @param reg_addr Register address to write.
 * @param reg_value 11-bit register value.
 * @retval IDRV8353_StatusType (IDRV8353_OK or IDRV8353_NOT_OK)
 */
IDRV8353_StatusType IDRV8353_WriteRegister_HAL(uint8_t reg_addr, uint16_t reg_value)
{
    uint16_t response = DRV8353_Write(reg_addr, reg_value);

    /* Validate if the write was successful */
    if ((response & DRV_DATA) != (reg_value & DRV_DATA))
    {
        return IDRV8353_NOT_OK;
    }

    return IDRV8353_OK;
}

/**
 * @brief Sets the Current Sense Amplifier (CSA) gain.
 * @param gain Gain value (5V/V, 10V/V, 20V/V, 40V/V).
 * @retval IDRV8353_StatusType (IDRV8353_OK or IDRV8353_NOT_OK)
 */
IDRV8353_StatusType IDRV8353_SetGain_HAL(DRV_Gain gain)
{
    if (DRV8353_SetGain(gain) == RETVAL_OK)
    {
        return IDRV8353_OK;
    }
    return IDRV8353_NOT_OK;
}

/**
 * @brief Retrieves the currently set Current Sense Amplifier gain.
 * @return DRV_Gain (5V/V, 10V/V, 20V/V, 40V/V).
 */
DRV_Gain IDRV8353_GetGain_HAL(void)
{
    return DRV8353_GetGain();
}

/**
 * @brief Sets the VDS overcurrent protection (OCP) limit.
 * @param limit Overcurrent protection limit voltage.
 * @retval IDRV8353_StatusType (IDRV8353_OK or IDRV8353_NOT_OK)
 */
IDRV8353_StatusType IDRV8353_SetVDSLimit_HAL(DRV_VDS_Limit limit)
{
    if (DRV8353_SetVDSLimit(limit) == RETVAL_OK)
    {
        return IDRV8353_OK;
    }
    return IDRV8353_NOT_OK;
}

/**
 * @brief Retrieves the currently set VDS overcurrent protection limit.
 * @return DRV_VDS_Limit (VDS fault limit setting).
 */
DRV_VDS_Limit IDRV8353_GetVDSLimit_HAL(void)
{
    return DRV8353_GetVDSLimit();
}

/**
 * @brief Sets the gate drive strength.
 * @param strength Bitmapped field for max gate drive current.
 * @retval IDRV8353_StatusType (IDRV8353_OK or IDRV8353_NOT_OK)
 */
IDRV8353_StatusType IDRV8353_SetGateStrength_HAL(uint32_t strength)
{
    if (DRV8353_SetGateStrength(strength) == RETVAL_OK)
    {
        return IDRV8353_OK;
    }
    return IDRV8353_NOT_OK;
}

/**
 * @brief Retrieves the current gate drive strength.
 * @return uint32_t (Bitmapped field for gate drive current).
 */
uint32_t IDRV8353_GetGateStrength_HAL(void)
{
    return DRV8353_GetGateStrength();
}

/**
 * @brief Enables shunt amplifier calibration for a specific channel.
 * @param channel Channel selection for calibration.
 */
void IDRV8353_SetCalibration_HAL(uint8_t channel)
{
    DRV8353_SetCalibration(channel);
}
