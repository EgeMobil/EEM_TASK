#ifndef ABSTRACT_MOTORDRIVER_H_
#define ABSTRACT_MOTORDRIVER_H_

#include "ECUStateManager_global.h"

/*************************************************************/
/* IBrakeAndDirection : Direction - Compu Method */
/**
 * @brief Defines the direction status for brake and direction operations.
 * - DIRECTION_BACKWARD: Indicates backward direction.
 * - DIRECTION_FORWARD: Indicates forward direction.
 * - DIRECTION_UNKNOWN: Direction is unknown.
 */
typedef enum
{
    DIRECTION_BACKWARD = 0, /**< Backward direction. */
    DIRECTION_FORWARD,      /**< Forward direction. */
    DIRECTION_UNKNOWN       /**< Unknown direction. */
} cmDirectionStatus;

/* IBrakeAndDirection : Direction - Data Constraint */
/**
 * @brief Defines the constraints for direction values.
 * - lowerLimit: Minimum valid value for direction.
 * - upperLimit: Maximum valid value for direction.
 * - monotony: Monotony constraint for direction values.
 */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for direction. */
    uint8_t upperLimit;      /**< Maximum valid value for direction. */
    MonotonyType monotony;   /**< Monotony constraint for direction values. */
} dcDirectionStatus;

/* IBrakeAndDirection : Brake - Compu Method */
/**
 * @brief Defines the brake status for brake and direction operations.
 * - BRAKE_DISABLE: Brake is disabled.
 * - BRAKE_ENABLE: Brake is enabled.
 * - BRAKE_UNKNOWN: Brake status is unknown.
 */
typedef enum
{
    BRAKE_DISABLE = 0, /**< Brake is disabled. */
    BRAKE_ENABLE,      /**< Brake is enabled. */
    BRAKE_UNKNOWN      /**< Unknown brake status. */
} cmBrakeStatus;

/* IBrakeAndDirection : Brake - Data Constraint */
/**
 * @brief Defines the constraints for brake values.
 * - lowerLimit: Minimum valid value for brake.
 * - upperLimit: Maximum valid value for brake.
 * - monotony: Monotony constraint for brake values.
 */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for brake. */
    uint8_t upperLimit;      /**< Maximum valid value for brake. */
    MonotonyType monotony;   /**< Monotony constraint for brake values. */
} dcBrakeStatus;

/*************************************************************/
/* IDirectionStatus : Compu Method */
/**
 * @brief Defines the direction status for IDirectionStatus operations.
 * - DIRECTION_STATUS_BACKWARD: Indicates backward direction.
 * - DIRECTION_STATUS_FORWARD: Indicates forward direction.
 * - DIRECTION_STATUS_UNKNOWN: Direction is unknown.
 */
typedef enum
{
    DIRECTION_STATUS_BACKWARD = 0, /**< Backward direction. */
    DIRECTION_STATUS_FORWARD,      /**< Forward direction. */
    DIRECTION_STATUS_UNKNOWN       /**< Unknown direction status. */
} cmDirectionStatusType;

/* IDirectionStatus : Data Constraint */
/**
 * @brief Defines the constraints for IDirectionStatus values.
 * - lowerLimit: Minimum valid value for direction.
 * - upperLimit: Maximum valid value for direction.
 * - monotony: Monotony constraint for direction values.
 */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for direction. */
    uint8_t upperLimit;      /**< Maximum valid value for direction. */
    MonotonyType monotony;   /**< Monotony constraint for direction values. */
} dcDirectionStatusType;

/*************************************************************/
/* IBrakeStatus : Compu Method */
/**
 * @brief Defines the brake status for IBrakeStatus operations.
 * - BRAKE_STATUS_DISABLE: Brake is disabled.
 * - BRAKE_STATUS_ENABLE: Brake is enabled.
 * - BRAKE_STATUS_UNKNOWN: Brake status is unknown.
 */
typedef enum
{
    BRAKE_STATUS_DISABLE = 0, /**< Brake is disabled. */
    BRAKE_STATUS_ENABLE,      /**< Brake is enabled. */
    BRAKE_STATUS_UNKNOWN      /**< Unknown brake status. */
} cmBrakeStatusType;

/* IBrakeStatus : Data Constraint */
/**
 * @brief Defines the constraints for IBrakeStatus values.
 * - lowerLimit: Minimum valid value for brake.
 * - upperLimit: Maximum valid value for brake.
 * - monotony: Monotony constraint for brake values.
 */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for brake. */
    uint8_t upperLimit;      /**< Maximum valid value for brake. */
    MonotonyType monotony;   /**< Monotony constraint for brake values. */
} dcBrakeStatusType;

/*************************************************************/

/*************************************************************/
/* IHALLA : State - Compu Method */
/**
 * @brief Defines the state of the Hall sensor for IHALLA operations.
 * - HALLA_STATUS_ENABLE: Hall sensor is enabled.
 * - HALLA_STATUS_DISABLE: Hall sensor is disabled.
 * - HALLA_STATUS_UNKNOWN: Hall sensor state is unknown.
 */
typedef enum
{
    HALLA_STATUS_ENABLE = 0, /**< Hall sensor is enabled. */
    HALLA_STATUS_DISABLE,    /**< Hall sensor is disabled. */
    HALLA_STATUS_UNKNOWN     /**< Hall sensor state is unknown. */
} cmHallAStateStatus;

/* IHALLA : State - Data Constraint */
/**
 * @brief Defines the constraints for Hall sensor state values.
 * - lowerLimit: Minimum valid value for Hall state.
 * - upperLimit: Maximum valid value for Hall state.
 * - monotony: Monotony constraint for Hall state values.
 */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for Hall state. */
    uint8_t upperLimit;      /**< Maximum valid value for Hall state. */
    MonotonyType monotony;   /**< Monotony constraint for Hall state values. */
} dcHallAStateStatus;

/*************************************************************/
/* IHALLA : RisingEdgeFlag - Compu Method */
/**
 * @brief Defines the rising edge flag for IHALLA operations.
 * - HALLA_RISING_EDGE_LOW: Rising edge is low.
 * - HALLA_RISING_EDGE_HIGH: Rising edge is high.
 * - HALLA_RISING_EDGE_UNKNOWN: Rising edge flag state is unknown.
 */
typedef enum
{
    HALLA_RISING_EDGE_LOW = 0, /**< Rising edge is low. */
    HALLA_RISING_EDGE_HIGH,    /**< Rising edge is high. */
    HALLA_RISING_EDGE_UNKNOWN  /**< Rising edge state is unknown. */
} cmRisingEdgeAFlag;

/* IHALLA : RisingEdgeFlag - Data Constraint */
/**
 * @brief Defines the constraints for Hall sensor rising edge flag values.
 * - lowerLimit: Minimum valid value for rising edge flag.
 * - upperLimit: Maximum valid value for rising edge flag.
 * - monotony: Monotony constraint for rising edge flag values.
 */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for rising edge flag. */
    uint8_t upperLimit;      /**< Maximum valid value for rising edge flag. */
    MonotonyType monotony;   /**< Monotony constraint for rising edge flag values. */
} dcRisingEdgeAFlag;

/*************************************************************/
/* IHALLA : FallingEdgeFlag - Compu Method */
/**
 * @brief Defines the falling edge flag for IHALLA operations.
 * - HALLA_FALLING_EDGE_LOW: Falling edge is low.
 * - HALLA_FALLING_EDGE_HIGH: Falling edge is high.
 * - HALLA_FALLING_EDGE_UNKNOWN: Falling edge flag state is unknown.
 */
typedef enum
{
    HALLA_FALLING_EDGE_LOW = 0, /**< Falling edge is low. */
    HALLA_FALLING_EDGE_HIGH,    /**< Falling edge is high. */
    HALLA_FALLING_EDGE_UNKNOWN  /**< Falling edge state is unknown. */
} cmFallingEdgeAFlag;

/* IHALLA : FallingEdgeFlag - Data Constraint */
/**
 * @brief Defines the constraints for Hall sensor falling edge flag values.
 * - lowerLimit: Minimum valid value for falling edge flag.
 * - upperLimit: Maximum valid value for falling edge flag.
 * - monotony: Monotony constraint for falling edge flag values.
 */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for falling edge flag. */
    uint8_t upperLimit;      /**< Maximum valid value for falling edge flag. */
    MonotonyType monotony;   /**< Monotony constraint for falling edge flag values. */
} dcFallingEdgeAFlag;

/*************************************************************/
/* IHALLA : RisingEdgeCount - Compu Method */
/**
 * @brief Defines the rising edge count for IHALLA operations.
 * This is a simple 32-bit unsigned integer representing the count.
 */
typedef uint32_t cmRisingEdgeACount;

/* IHALLA : RisingEdgeCount - Data Constraint */
/**
 * @brief Defines the constraints for Hall sensor rising edge count values.
 * - lowerLimit: Minimum valid value for rising edge count.
 * - upperLimit: Maximum valid value for rising edge count.
 * - monotony: Monotony constraint for rising edge count values.
 */
typedef struct
{
    uint32_t lowerLimit;      /**< Minimum valid value for rising edge count. */
    uint32_t upperLimit;      /**< Maximum valid value for rising edge count. */
    MonotonyType monotony;    /**< Monotony constraint for rising edge count values. */
} dcRisingEdgeACount;

/*************************************************************/
/* IHALLA : FallingEdgeCount - Compu Method */
/**
 * @brief Defines the falling edge count for IHALLA operations.
 * This is a simple 32-bit unsigned integer representing the count.
 */
typedef uint32_t cmFallingEdgeACount;

/* IHALLA : FallingEdgeCount - Data Constraint */
/**
 * @brief Defines the constraints for Hall sensor falling edge count values.
 * - lowerLimit: Minimum valid value for falling edge count.
 * - upperLimit: Maximum valid value for falling edge count.
 * - monotony: Monotony constraint for falling edge count values.
 */
typedef struct
{
    uint32_t lowerLimit;      /**< Minimum valid value for falling edge count. */
    uint32_t upperLimit;      /**< Maximum valid value for falling edge count. */
    MonotonyType monotony;    /**< Monotony constraint for falling edge count values. */
} dcFallingEdgeACount;

/*************************************************************/

/*************************************************************/
/* IHALLB : State - Compu Method */
/**
 * @brief Defines the state of the Hall sensor for IHALLB operations.
 * - HALLB_STATUS_ENABLE: Hall sensor is enabled.
 * - HALLB_STATUS_DISABLE: Hall sensor is disabled.
 * - HALLB_STATUS_UNKNOWN: Hall sensor state is unknown.
 */
typedef enum
{
    HALLB_STATUS_ENABLE = 0, /**< Hall sensor is enabled. */
    HALLB_STATUS_DISABLE,    /**< Hall sensor is disabled. */
    HALLB_STATUS_UNKNOWN     /**< Hall sensor state is unknown. */
} cmHallBStateStatus;

/* IHALLB : State - Data Constraint */
/**
 * @brief Defines the constraints for Hall sensor state values.
 * - lowerLimit: Minimum valid value for Hall state.
 * - upperLimit: Maximum valid value for Hall state.
 * - monotony: Monotony constraint for Hall state values.
 */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for Hall state. */
    uint8_t upperLimit;      /**< Maximum valid value for Hall state. */
    MonotonyType monotony;   /**< Monotony constraint for Hall state values. */
} dcHallBStateStatus;

/*************************************************************/
/* IHALLB : RisingEdgeFlag - Compu Method */
/**
 * @brief Defines the rising edge flag for IHALLB operations.
 * - HALLB_RISING_EDGE_LOW: Rising edge is low.
 * - HALLB_RISING_EDGE_HIGH: Rising edge is high.
 * - HALLB_RISING_EDGE_UNKNOWN: Rising edge flag state is unknown.
 */
typedef enum
{
    HALLB_RISING_EDGE_LOW = 0, /**< Rising edge is low. */
    HALLB_RISING_EDGE_HIGH,    /**< Rising edge is high. */
    HALLB_RISING_EDGE_UNKNOWN  /**< Rising edge state is unknown. */
} cmRisingEdgeBFlag;

/* IHALLB : RisingEdgeFlag - Data Constraint */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for rising edge flag. */
    uint8_t upperLimit;      /**< Maximum valid value for rising edge flag. */
    MonotonyType monotony;   /**< Monotony constraint for rising edge flag values. */
} dcRisingEdgeBFlag;

/*************************************************************/
/* IHALLB : FallingEdgeFlag - Compu Method */
typedef enum
{
    HALLB_FALLING_EDGE_LOW = 0, /**< Falling edge is low. */
    HALLB_FALLING_EDGE_HIGH,    /**< Falling edge is high. */
    HALLB_FALLING_EDGE_UNKNOWN  /**< Falling edge state is unknown. */
} cmFallingEdgeBFlag;

/* IHALLB : FallingEdgeFlag - Data Constraint */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for falling edge flag. */
    uint8_t upperLimit;      /**< Maximum valid value for falling edge flag. */
    MonotonyType monotony;   /**< Monotony constraint for falling edge flag values. */
} dcFallingEdgeBFlag;

/*************************************************************/
/* IHALLB : RisingEdgeCount - Compu Method */
typedef uint32_t cmRisingEdgeBCount;

/* IHALLB : RisingEdgeCount - Data Constraint */
typedef struct
{
    uint32_t lowerLimit;      /**< Minimum valid value for rising edge count. */
    uint32_t upperLimit;      /**< Maximum valid value for rising edge count. */
    MonotonyType monotony;    /**< Monotony constraint for rising edge count values. */
} dcRisingEdgeBCount;

/*************************************************************/
/* IHALLB : FallingEdgeCount - Compu Method */
typedef uint32_t cmFallingEdgeBCount;

/* IHALLB : FallingEdgeCount - Data Constraint */
typedef struct
{
    uint32_t lowerLimit;      /**< Minimum valid value for falling edge count. */
    uint32_t upperLimit;      /**< Maximum valid value for falling edge count. */
    MonotonyType monotony;    /**< Monotony constraint for falling edge count values. */
} dcFallingEdgeBCount;

/*************************************************************/
/* IHALLC : State - Compu Method */
typedef enum
{
    HALLC_STATUS_ENABLE = 0, /**< Hall sensor is enabled. */
    HALLC_STATUS_DISABLE,    /**< Hall sensor is disabled. */
    HALLC_STATUS_UNKNOWN     /**< Hall sensor state is unknown. */
} cmHallCStateStatus;

/* IHALLC : State - Data Constraint */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for Hall state. */
    uint8_t upperLimit;      /**< Maximum valid value for Hall state. */
    MonotonyType monotony;   /**< Monotony constraint for Hall state values. */
} dcHallCStateStatus;

/*************************************************************/
/* IHALLC : RisingEdgeFlag - Compu Method */
typedef enum
{
    HALLC_RISING_EDGE_LOW = 0, /**< Rising edge is low. */
    HALLC_RISING_EDGE_HIGH,    /**< Rising edge is high. */
    HALLC_RISING_EDGE_UNKNOWN  /**< Rising edge state is unknown. */
} cmRisingEdgeCFlag;

/* IHALLC : RisingEdgeFlag - Data Constraint */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for rising edge flag. */
    uint8_t upperLimit;      /**< Maximum valid value for rising edge flag. */
    MonotonyType monotony;   /**< Monotony constraint for rising edge flag values. */
} dcRisingEdgeCFlag;

/*************************************************************/
/* IHALLC : FallingEdgeFlag - Compu Method */
typedef enum
{
    HALLC_FALLING_EDGE_LOW = 0, /**< Falling edge is low. */
    HALLC_FALLING_EDGE_HIGH,    /**< Falling edge is high. */
    HALLC_FALLING_EDGE_UNKNOWN  /**< Falling edge state is unknown. */
} cmFallingEdgeCFlag;

/* IHALLC : FallingEdgeFlag - Data Constraint */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for falling edge flag. */
    uint8_t upperLimit;      /**< Maximum valid value for falling edge flag. */
    MonotonyType monotony;   /**< Monotony constraint for falling edge flag values. */
} dcFallingEdgeCFlag;

/*************************************************************/
/* IHALLC : RisingEdgeCount - Compu Method */
typedef uint32_t cmRisingEdgeCCount;

/* IHALLC : RisingEdgeCount - Data Constraint */
typedef struct
{
    uint32_t lowerLimit;      /**< Minimum valid value for rising edge count. */
    uint32_t upperLimit;      /**< Maximum valid value for rising edge count. */
    MonotonyType monotony;    /**< Monotony constraint for rising edge count values. */
} dcRisingEdgeCCount;

/*************************************************************/
/* IHALLC : FallingEdgeCount - Compu Method */
typedef uint32_t cmFallingEdgeCCount;

/* IHALLC : FallingEdgeCount - Data Constraint */
typedef struct
{
    uint32_t lowerLimit;      /**< Minimum valid value for falling edge count. */
    uint32_t upperLimit;      /**< Maximum valid value for falling edge count. */
    MonotonyType monotony;    /**< Monotony constraint for falling edge count values. */
} dcFallingEdgeCCount;

/*************************************************************/


#endif  /* ABSTRACT_MOTORDRIVER_H_ */