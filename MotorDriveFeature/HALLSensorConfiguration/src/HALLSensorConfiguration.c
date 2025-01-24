#include "HALLSensorConfiguration_private.h"

/* Static singleton instance */
static dtHALLSensorConfiguration instance;

/* Getter Setter Implementation */

/**
 * @brief Sets the configuration for Hall A.
 * @param config New configuration for Hall A.
 */
static void setHallAConfig_Impl(dtHALLAconfiguration config)
{
    instance.hall_a = config;
    printf("[HALLSensorConfiguration] Hall A configuration updated.\n");
}

/**
 * @brief Gets the current configuration for Hall A.
 * @return Current configuration for Hall A.
 */
static dtHALLAconfiguration getHallAConfig_Impl(void)
{
    return instance.hall_a;
}

/**
 * @brief Sets the configuration for Hall B.
 * @param config New configuration for Hall B.
 */
static void setHallBConfig_Impl(dtHALLBconfiguration config)
{
    instance.hall_b = config;
    printf("[HALLSensorConfiguration] Hall B configuration updated.\n");
}

/**
 * @brief Gets the current configuration for Hall B.
 * @return Current configuration for Hall B.
 */
static dtHALLBconfiguration getHallBConfig_Impl(void)
{
    return instance.hall_b;
}

/**
 * @brief Sets the configuration for Hall C.
 * @param config New configuration for Hall C.
 */
static void setHallCConfig_Impl(dtHALLCconfiguration config)
{
    instance.hall_c = config;
    printf("[HALLSensorConfiguration] Hall C configuration updated.\n");
}

/**
 * @brief Gets the current configuration for Hall C.
 * @return Current configuration for Hall C.
 */
static dtHALLCconfiguration getHallCConfig_Impl(void)
{
    return instance.hall_c;
}


/* Getter/Setter Implementations for Hall A */
static void setHallAState_Impl(dtHALLSensorConfiguration_HallAStateStatus state)
{
    instance.hall_a.status = state;
    printf("[HALLSensorConfiguration] Hall A state updated: %d\n", state);
}

static dtHALLSensorConfiguration_HallAStateStatus getHallAState_Impl(void)
{
    return instance.hall_a.status;
}

static void setHallARisingEdgeFlag_Impl(dtHALLSensorConfiguration_RisingEdgeAFlag flag)
{
    instance.hall_a.re_flag = flag;
    printf("[HALLSensorConfiguration] Hall A rising edge flag updated: %d\n", flag);
}

static dtHALLSensorConfiguration_RisingEdgeAFlag getHallARisingEdgeFlag_Impl(void)
{
    return instance.hall_a.re_flag;
}

static void setHallAFallingEdgeFlag_Impl(dtHALLSensorConfiguration_FallingEdgeAFlag flag)
{
    instance.hall_a.fe_flag = flag;
    printf("[HALLSensorConfiguration] Hall A falling edge flag updated: %d\n", flag);
}

static dtHALLSensorConfiguration_FallingEdgeAFlag getHallAFallingEdgeFlag_Impl(void)
{
    return instance.hall_a.fe_flag;
}

/* Getter/Setter Implementations for Hall B */
static void setHallBState_Impl(dtHALLSensorConfiguration_HallBStateStatus state)
{
    instance.hall_b.status = state;
    printf("[HALLSensorConfiguration] Hall B state updated: %d\n", state);
}

static dtHALLSensorConfiguration_HallBStateStatus getHallBState_Impl(void)
{
    return instance.hall_b.status;
}

static void setHallBRisingEdgeFlag_Impl(dtHALLSensorConfiguration_RisingEdgeBFlag flag)
{
    instance.hall_b.re_flag = flag;
    printf("[HALLSensorConfiguration] Hall B rising edge flag updated: %d\n", flag);
}

static dtHALLSensorConfiguration_RisingEdgeBFlag getHallBRisingEdgeFlag_Impl(void)
{
    return instance.hall_b.re_flag;
}

static void setHallBFallingEdgeFlag_Impl(dtHALLSensorConfiguration_FallingEdgeBFlag flag)
{
    instance.hall_b.fe_flag = flag;
    printf("[HALLSensorConfiguration] Hall B falling edge flag updated: %d\n", flag);
}

static dtHALLSensorConfiguration_FallingEdgeBFlag getHallBFallingEdgeFlag_Impl(void)
{
    return instance.hall_b.fe_flag;
}

/* Getter/Setter Implementations for Hall C */
static void setHallCState_Impl(dtHALLSensorConfiguration_HallCStateStatus state)
{
    instance.hall_c.status = state;
    printf("[HALLSensorConfiguration] Hall C state updated: %d\n", state);
}

static dtHALLSensorConfiguration_HallCStateStatus getHallCState_Impl(void)
{
    return instance.hall_c.status;
}

static void setHallCRisingEdgeFlag_Impl(dtHALLSensorConfiguration_RisingEdgeCFlag flag)
{
    instance.hall_c.re_flag = flag;
    printf("[HALLSensorConfiguration] Hall C rising edge flag updated: %d\n", flag);
}

static dtHALLSensorConfiguration_RisingEdgeCFlag getHallCRisingEdgeFlag_Impl(void)
{
    return instance.hall_c.re_flag;
}

static void setHallCFallingEdgeFlag_Impl(dtHALLSensorConfiguration_FallingEdgeCFlag flag)
{
    instance.hall_c.fe_flag = flag;
    printf("[HALLSensorConfiguration] Hall C falling edge flag updated: %d\n", flag);
}

static dtHALLSensorConfiguration_FallingEdgeCFlag getHallCFallingEdgeFlag_Impl(void)
{
    return instance.hall_c.fe_flag;
}



/* toString() Implementation */

static const char* HallStateToString(dtHALLSensorConfiguration_HallAStateStatus state)
{
    switch (state)
    {
        case HALLA_STATUS_LOW:
            return "Enabled";
        case HALLA_STATUS_HIGH:
            return "Disabled";
        case HALLA_STATUS_UNKNOWN:
        default:
            return "Unknown";
    }
}

static const char* RisingEdgeToString(dtHALLSensorConfiguration_RisingEdgeAFlag flag)
{
    switch (flag)
    {
        case HALLA_RISING_EDGE_RESET:
            return "Low";
        case HALLA_RISING_EDGE_SET:
            return "High";
        case HALLA_RISING_EDGE_UNKNOWN:
        default:
            return "Unknown";
    }
}

static const char* FallingEdgeToString(dtHALLSensorConfiguration_FallingEdgeAFlag flag)
{
    switch (flag)
    {
        case HALLA_FALLING_EDGE_RESET:
            return "Low";
        case HALLA_FALLING_EDGE_SET:
            return "High";
        case HALLA_FALLING_EDGE_UNKNOWN:
        default:
            return "Unknown";
    }
}

static char* toString_Impl(void)
{
    static char buffer[1024]; // Artan bilgi için daha geniş bir buffer
    snprintf(buffer, sizeof(buffer),
             "[HALLSensorConfiguration]\n"
             "Interfaces:\n"
             "  IHALLA: %s\n"
             "  IHALLB: %s\n"
             "  IHALLC: %s\n"
             "  PwmStep: %s\n"
             "Hall A:\n"
             "  State: %s\n"
             "  Rising Edge: %s \n"
             "  Falling Edge: %s \n"
             "Hall B:\n"
             "  State: %s\n"
             "  Rising Edge: %s \n"
             "  Falling Edge: %s \n"
             "Hall C:\n"
             "  State: %s\n"
             "  Rising Edge: %s \n"
             "  Falling Edge: %s \n",
             
             // Interfaces connected or not
             (instance.IHALLA != NULL) ? "Connected" : "Not Connected",
             (instance.IHALLB != NULL) ? "Connected" : "Not Connected",
             (instance.IHALLC != NULL) ? "Connected" : "Not Connected",
             (instance.IPwmStep != NULL) ? "Connected" : "Not Connected",

             // Hall A information
             HallStateToString(instance.hall_a.status),
             RisingEdgeToString(instance.hall_a.re_flag),
             FallingEdgeToString(instance.hall_a.fe_flag),

             // Hall B information
             HallStateToString(instance.hall_b.status),
             RisingEdgeToString(instance.hall_b.re_flag),
             FallingEdgeToString(instance.hall_b.fe_flag),

             // Hall C information
             HallStateToString(instance.hall_c.status),
             RisingEdgeToString(instance.hall_c.re_flag),
             FallingEdgeToString(instance.hall_c.fe_flag));

    return buffer;
}


/* Constructor Implementation */

void HALLSensorConfigurationHallA_CTOR(void)
{
    instance.hall_a.status = HALLA_STATUS_UNKNOWN;
    instance.hall_a.re_flag = HALLA_RISING_EDGE_UNKNOWN;
    instance.hall_a.fe_flag = HALLA_FALLING_EDGE_UNKNOWN;

    /* Assign function pointers */
    instance.hall_a.setStatus = setHallAState_Impl;
    instance.hall_a.getStatus = getHallAState_Impl;
    instance.hall_a.setFallingEdgeFlag = setHallAFallingEdgeFlag_Impl;
    instance.hall_a.getFallingEdgeFlag = getHallAFallingEdgeFlag_Impl;
    instance.hall_a.setRisingEdgeFlag = setHallARisingEdgeFlag_Impl;
    instance.hall_a.getRisingEdgeFlag = getHallARisingEdgeFlag_Impl;
}

void HALLSensorConfigurationHallB_CTOR(void)
{
    instance.hall_b.status = HALLB_STATUS_UNKNOWN;
    instance.hall_b.re_flag = HALLB_RISING_EDGE_UNKNOWN;
    instance.hall_b.fe_flag = HALLB_FALLING_EDGE_UNKNOWN;

    /* Assign function pointers */
    instance.hall_b.setStatus = setHallBState_Impl;
    instance.hall_b.getStatus = getHallBState_Impl;
    instance.hall_b.setFallingEdgeFlag = setHallBFallingEdgeFlag_Impl;
    instance.hall_b.getFallingEdgeFlag = getHallBFallingEdgeFlag_Impl;
    instance.hall_b.setRisingEdgeFlag = setHallBRisingEdgeFlag_Impl;
    instance.hall_b.getRisingEdgeFlag = getHallBRisingEdgeFlag_Impl;
}

void HALLSensorConfigurationHallC_CTOR(void)
{
    instance.hall_c.status = HALLC_STATUS_UNKNOWN;
    instance.hall_c.re_flag = HALLC_RISING_EDGE_UNKNOWN;
    instance.hall_c.fe_flag = HALLC_FALLING_EDGE_UNKNOWN;

    /* Assign function pointers */
    instance.hall_c.setStatus = setHallCState_Impl;
    instance.hall_c.getStatus = getHallCState_Impl;
    instance.hall_c.setFallingEdgeFlag = setHallCFallingEdgeFlag_Impl;
    instance.hall_c.getFallingEdgeFlag = getHallCFallingEdgeFlag_Impl;
    instance.hall_c.setRisingEdgeFlag = setHallCRisingEdgeFlag_Impl;
    instance.hall_c.getRisingEdgeFlag = getHallCRisingEdgeFlag_Impl;
}


/**
 * @brief Constructor for the Hall Sensor Configuration.
 */
void HALLSensorConfiguration_CTOR(void)
{
    /* Initialize interfaces */
    instance.IHALLA = &HALLAInterface;
    instance.IHALLB = &HALLBInterface;
    instance.IHALLC = &HALLCInterface;
    instance.IPwmStep = &PwmStepInterface;

    /* Initialize attributes */
    HALLSensorConfigurationHallA_CTOR();
    HALLSensorConfigurationHallB_CTOR();
    HALLSensorConfigurationHallC_CTOR();

    /* Assign implementations */
    instance.setHallAConfig = setHallAConfig_Impl;
    instance.getHallAConfig = getHallAConfig_Impl;
    instance.setHallBConfig = setHallBConfig_Impl;
    instance.getHallBConfig = getHallBConfig_Impl;
    instance.setHallCConfig = setHallCConfig_Impl;
    instance.getHallCConfig = getHallCConfig_Impl;
    instance.toString = toString_Impl;
}

/* Singleton Instance Getter */

/**
 * @brief Retrieves the singleton instance of the Hall Sensor Configuration.
 * @return Pointer to the singleton instance.
 */
dtHALLSensorConfiguration* HALLSensorConfiguration_GetInstance(void)
{
    return &instance;
}