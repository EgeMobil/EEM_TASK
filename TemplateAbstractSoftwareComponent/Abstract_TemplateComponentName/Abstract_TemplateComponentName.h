#ifndef ABSTRACT_TEMPLATECOMPONENTNAME_H_
#define ABSTRACT_TEMPLATECOMPONENTNAME_H_

#include "ECUStateManager_global.h"

/**
 * @file Abstract_TemplateComponentName.h
 * @brief Template header for abstract register-based components.
 *
 * This structure is designed to support generalized processing of numeric or binary values,
 * bounded output control, and validation under constraints.
 */

/*=========================================*/
/* ENUM – Generic Status Flags */
/*=========================================*/
typedef enum {
    TEMPLATE_STATUS_OK = 0,          /**< Valid result */
    TEMPLATE_STATUS_OVERFLOW = 1,    /**< Exceeded numerical range */
    TEMPLATE_STATUS_INVALID = 2      /**< Invalid input domain or error */
} TEMPLATE_ResultStatus;

/*=========================================*/
/* COMPU METHOD – General Result Structure */
/*=========================================*/
typedef union {
    float value; /**< Computed or measured value */
    struct {
        uint32_t rawBits; /**< Optional bitwise view */
    } asBits;
} cmTemplateResult;

/*=========================================*/
/* DATA CONSTRAINT – Range and Monotony */
/*=========================================*/
typedef struct {
    float lowerLimit;        /**< Minimum valid output */
    float upperLimit;        /**< Maximum valid output */
    MonotonyType monotony;   /**< Expected behavior: increasing, decreasing, etc. */
} dcTemplateResult;

#endif /* ABSTRACT_TEMPLATECOMPONENTNAME_H_ */