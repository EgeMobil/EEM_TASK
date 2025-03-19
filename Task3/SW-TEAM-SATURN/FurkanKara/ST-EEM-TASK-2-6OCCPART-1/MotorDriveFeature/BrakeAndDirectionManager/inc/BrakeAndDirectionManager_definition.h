/**
 * @file BrakeAndDirectionManager_definition.h
 * @brief Definition header file for the Brake and Direction Manager.
 * 
 * This file contains the definitions, data types, and structure declarations 
 * for the Brake and Direction Manager. It includes the necessary interfaces 
 * and dependencies for managing brake and direction functionalities in the 
 * MotorDriverControlManager.
 * 
 * @author atakan.ertekin
 * @date 07.01.2025
 */

#ifndef BRAKEANDDIRECTIONMANAGER_INC_BRAKEANDDIRECTIONMANAGER_DEFINITION_H_
#define BRAKEANDDIRECTIONMANAGER_INC_BRAKEANDDIRECTIONMANAGER_DEFINITION_H_

#include "ECUStateManager_global.h"

/* Include interface headers */
#include "IBrakeAndDirection.h"
#include "IBrakeStatus.h"
#include "IDirectionStatus.h"

/**
 * @brief Enum for Brake and Direction Manager return values.
 */
typedef enum
{
	BDR_ERR = 0,     /**< Error occurred. */
	BDR_EOK,         /**< Operation successful. */
	BDR_UNKNOWN      /**< Unknown state. */
} dtBdrReturn;

/**
 * @brief Return type for Brake and Direction Manager.
 */
typedef dtBdrReturn dtBrakeAndDirectionManager_bdrReturn;

/**
 * @brief Direction type for Brake and Direction Manager.
 */
typedef cmDirectionStatus dtBrakeAndDirectionManager_bdrDirection;

/**
 * @brief Brake type for Brake and Direction Manager.
 */
typedef cmBrakeStatus dtBrakeAndDirectionManager_bdrBrake;

/**
 * @brief Configuration structure for Brake and Direction Manager.
 */
typedef struct
{
	/* Configuration attributes */
	dtBrakeAndDirectionManager_bdrDirection    direction; /**< Current direction configuration. */
	dtBrakeAndDirectionManager_bdrBrake	  	   brake;     /**< Current brake configuration. */

	/* Getter/Setter for configuration */
	/**
	 * @brief Gets the current direction configuration.
	 * @return Current direction configuration.
	 */
	dtBrakeAndDirectionManager_bdrDirection (*getDirection)(void);

	/**
	 * @brief Sets the direction configuration.
	 * @param direction Direction configuration to set.
	 */
    void (*setDirection)(dtBrakeAndDirectionManager_bdrDirection direction);

	/**
	 * @brief Gets the current brake configuration.
	 * @return Current brake configuration.
	 */
    dtBrakeAndDirectionManager_bdrBrake (*getBrake)(void);

	/**
	 * @brief Sets the brake configuration.
	 * @param brake Brake configuration to set.
	 */
    void (*setBrake)(dtBrakeAndDirectionManager_bdrBrake brake);

} dtBdrConfiguration;

/**
 * @brief Alias for Brake and Direction Manager configuration.
 */
typedef dtBdrConfiguration dtBrakeAndDirectionManager_bdrConfiguration;

/**
 * @brief Component base class for Brake and Direction Manager.
 * 
 * This structure provides the main attributes, interface pointers, getter/setter functions, 
 * and functional behaviors for managing brake and direction functionalities.
 */
typedef struct 
{
	/* Interface Pointer */
	IBrakeAndDirection* IBrakeAndDirection; /**< Pointer to Brake and Direction interface. */
	IBrakeStatus* IBrakeStatus;             /**< Pointer to Brake Status interface. */
	IDirectionStatus* IDirectionStatus;     /**< Pointer to Direction Status interface. */

	/* Attributes */
	dtBrakeAndDirectionManager_bdrReturn 		retVal; /**< Return value of the manager. */
	dtBrakeAndDirectionManager_bdrConfiguration config; /**< Configuration structure for the manager. */

	/* Getter/Setter */
	/**
	 * @brief Gets the return value of the manager.
	 * @return Current return value.
	 */
    dtBrakeAndDirectionManager_bdrReturn (*getRetVal)(void);

	/**
	 * @brief Sets the return value of the manager.
	 * @param value Return value to set.
	 */
    void (*setRetVal)(dtBrakeAndDirectionManager_bdrReturn value);

	/**
	 * @brief Gets the current configuration of the manager.
	 * @return Current configuration structure.
	 */
    dtBrakeAndDirectionManager_bdrConfiguration (*getConfig)(void);

	/**
	 * @brief Sets the configuration of the manager.
	 * @param value Configuration structure to set.
	 */
    void (*setConfig)(dtBrakeAndDirectionManager_bdrConfiguration value);

	/* toString */
	/**
	 * @brief Converts the current configuration to a string representation.
	 * @return A string representation of the manager configuration.
	 */
	char* (*toString)(void);

	/* Functional Behaviours */

} dtBrakeAndDirectionManager;

#endif /* BRAKEANDDIRECTIONMANAGER_INC_BRAKEANDDIRECTIONMANAGER_DEFINITION_H_ */
