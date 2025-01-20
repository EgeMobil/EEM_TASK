#ifndef ABSTRACT_SMARTGATEDRIVER_H_
#define ABSTRACT_SMARTGATEDRIVER_H_

#include "ECUStateManager_global.h"

/*************************************************************/
/* IDRV8353 : FaultReg1 : Enumaration  */
typedef enum {
    FAULT_INACTIVE = 0, // No fault
    FAULT_ACTIVE   = 1  // Fault present
} FAULT_STATUS;

typedef enum {
    VDS_OCP_INACTIVE = 0, // No overcurrent protection fault
    VDS_OCP_ACTIVE   = 1  // Overcurrent protection fault active
} VDS_OCP_STATUS;

typedef enum {
    GDF_INACTIVE = 0, // No gate drive fault
    GDF_ACTIVE   = 1  // Gate drive fault active
} GDF_STATUS;

typedef enum {
    UVLO_INACTIVE = 0, // No undervoltage lockout fault
    UVLO_ACTIVE   = 1  // Undervoltage lockout fault active
} UVLO_STATUS;

typedef enum {
    OTSD_INACTIVE = 0, // No overtemperature shutdown fault
    OTSD_ACTIVE   = 1  // Overtemperature shutdown fault active
} OTSD_STATUS;

typedef enum {
    VDS_HA_INACTIVE = 0, // No VDS fault in phase HA
    VDS_HA_ACTIVE   = 1  // VDS fault active in phase HA
} VDS_HA_STATUS;

typedef enum {
    VDS_LA_INACTIVE = 0, // No VDS fault in phase LA
    VDS_LA_ACTIVE   = 1  // VDS fault active in phase LA
} VDS_LA_STATUS;

typedef enum {
    VDS_HB_INACTIVE = 0, // No VDS fault in phase HB
    VDS_HB_ACTIVE   = 1  // VDS fault active in phase HB
} VDS_HB_STATUS;

typedef enum {
    VDS_LB_INACTIVE = 0, // No VDS fault in phase LB
    VDS_LB_ACTIVE   = 1  // VDS fault active in phase LB
} VDS_LB_STATUS;

typedef enum {
    VDS_HC_INACTIVE = 0, // No VDS fault in phase HC
    VDS_HC_ACTIVE   = 1  // VDS fault active in phase HC
} VDS_HC_STATUS;

typedef enum {
    VDS_LC_INACTIVE = 0, // No VDS fault in phase LC
    VDS_LC_ACTIVE   = 1  // VDS fault active in phase LC
} VDS_LC_STATUS;


/* IDRV8353 : FaultReg1 : Compu Method */
typedef union {
    uint16_t word; // 16 bit'lik register
    struct {
        uint8_t dontCareBits    : 5;
        FAULT_STATUS FAULT      : 1;
        VDS_OCP_STATUS VDS_OCP  : 1;
        GDF_STATUS GDF          : 1;
        UVLO_STATUS UVLO        : 1;
        OTSD_STATUS OTSD        : 1;
        VDS_HA_STATUS VDS_HA    : 1;
        VDS_LA_STATUS VDS_LA    : 1;
        VDS_HB_STATUS VDS_HB    : 1;
        VDS_LB_STATUS VDS_LB    : 1;
        VDS_HC_STATUS VDS_HC    : 1;
        VDS_LC_STATUS VDS_LC    : 1;
    } status_bits;
} cmFaultReg1;
/* IDRV8353 : FaultReg1 : Data Constraint  */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for brake. */
    uint8_t upperLimit;      /**< Maximum valid value for brake. */
    MonotonyType monotony;   /**< Monotony constraint for brake values. */
} dcFaultReg1;
/*************************************************************/


/*************************************************************/
/* IDRV8353 : VgsStatus : Enumaration */
typedef enum {
    SA_OC_INACTIVE = 0, // No overcurrent fault in phase SA
    SA_OC_ACTIVE   = 1  // Overcurrent fault active in phase SA
} SA_OC_STATUS;

typedef enum {
    SB_OC_INACTIVE = 0, // No overcurrent fault in phase SB
    SB_OC_ACTIVE   = 1  // Overcurrent fault active in phase SB
} SB_OC_STATUS;

typedef enum {
    SC_OC_INACTIVE = 0, // No overcurrent fault in phase SC
    SC_OC_ACTIVE   = 1  // Overcurrent fault active in phase SC
} SC_OC_STATUS;

typedef enum {
    OTW_INACTIVE = 0, // No overtemperature warning
    OTW_ACTIVE   = 1  // Overtemperature warning active
} OTW_STATUS;

typedef enum {
    GDUV_INACTIVE = 0, // No gate driver undervoltage fault
    GDUV_ACTIVE   = 1  // Gate driver undervoltage fault active
} GDUV_STATUS;

typedef enum {
    VGS_HA_INACTIVE = 0, // No gate-source voltage fault in phase HA
    VGS_HA_ACTIVE   = 1  // Gate-source voltage fault active in phase HA
} VGS_HA_STATUS;

typedef enum {
    VGS_LA_INACTIVE = 0, // No gate-source voltage fault in phase LA
    VGS_LA_ACTIVE   = 1  // Gate-source voltage fault active in phase LA
} VGS_LA_STATUS;

typedef enum {
    VGS_HB_INACTIVE = 0, // No gate-source voltage fault in phase HB
    VGS_HB_ACTIVE   = 1  // Gate-source voltage fault active in phase HB
} VGS_HB_STATUS;

typedef enum {
    VGS_LB_INACTIVE = 0, // No gate-source voltage fault in phase LB
    VGS_LB_ACTIVE   = 1  // Gate-source voltage fault active in phase LB
} VGS_LB_STATUS;

typedef enum {
    VGS_HC_INACTIVE = 0, // No gate-source voltage fault in phase HC
    VGS_HC_ACTIVE   = 1  // Gate-source voltage fault active in phase HC
} VGS_HC_STATUS;

typedef enum {
    VGS_LC_INACTIVE = 0, // No gate-source voltage fault in phase LC
    VGS_LC_ACTIVE   = 1  // Gate-source voltage fault active in phase LC
} VGS_LC_STATUS;

/* IDRV8353 : VgsStatus : Compu Method */
typedef union
{
	uint16_t word; // 2-byte field
	struct {
	    uint8_t dontCareBits : 5; // Unused bits
	    SA_OC_STATUS SA_OC   : 1;
	    SB_OC_STATUS SB_OC   : 1;
	    SC_OC_STATUS SC_OC   : 1;
	    OTW_STATUS OTW       : 1;
	    GDUV_STATUS GDUV     : 1;
	    VGS_HA_STATUS VGS_HA : 1;
	    VGS_LA_STATUS VGS_LA : 1;
	    VGS_HB_STATUS VGS_HB : 1;
	    VGS_LB_STATUS VGS_LB : 1;
	    VGS_HC_STATUS VGS_HC : 1;
	    VGS_LC_STATUS VGS_LC : 1;
	} status_bits;
} cmVgsStatus;

/* IDRV8353 : VgsStatus : Data Constraint */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for brake. */
    uint8_t upperLimit;      /**< Maximum valid value for brake. */
    MonotonyType monotony;   /**< Monotony constraint for brake values. */
} dcVgsStatus;
/*************************************************************/


/*************************************************************/
/* IDRV8353 : DriverControl : Enumaration */
/*************************************************************/
/* IDRV8353 : DriverControl : Enumaration */
typedef enum {
    OCP_ACT_DISABLED = 0, // Overcurrent protection disabled
    OCP_ACT_ENABLED  = 1  // Overcurrent protection enabled
} OCP_ACT_STATUS;

typedef enum {
    DIS_GDUV_INACTIVE = 0, // Gate Driver Undervoltage not disabled
    DIS_GDUV_ACTIVE   = 1  // Gate Driver Undervoltage disabled
} DIS_GDUV_STATUS;

typedef enum {
    DIS_GDF_INACTIVE = 0, // Gate Drive Fault detection not disabled
    DIS_GDF_ACTIVE   = 1  // Gate Drive Fault detection disabled
} DIS_GDF_STATUS;

typedef enum {
    OTW_REP_DISABLED = 0, // Overtemperature warning reporting disabled
    OTW_REP_ENABLED  = 1  // Overtemperature warning reporting enabled
} OTW_REP_STATUS;

typedef enum {
    PWM_MODE_6_INPUTS = 0b00, // 6 independent PWM inputs
    PWM_MODE_3_INPUTS = 0b01, // 3 independent PWM inputs
    PWM_MODE_1_INPUT  = 0b10, // 1 PWM input
    PWM_MODE_RESERVED = 0b11  // Reserved
} PWM_MODE_TYPE;

typedef enum {
    PWM_COM_DISABLED = 0, // PWM comparator disabled
    PWM_COM_ENABLED  = 1  // PWM comparator enabled
} PWM_COM_STATUS;

typedef enum {
    PWM_DIR_FORWARD = 0, // PWM direction set to forward
    PWM_DIR_REVERSE = 1  // PWM direction set to reverse
} PWM_DIR_STATUS;

typedef enum {
    COAST_DISABLED = 0, // Coast mode disabled
    COAST_ENABLED  = 1  // Coast mode enabled
} COAST_STATUS;

typedef enum {
    BRAKE_DISABLED = 0, // Brake disabled
    BRAKE_ENABLED  = 1  // Brake enabled
} BRAKE_STATUS;

typedef enum {
    CLR_FLT_NO_ACTION = 0, // Clear fault inactive
    CLR_FLT_ACTIVE    = 1  // Clear fault active
} CLR_FLT_STATUS;

/* IDRV8353 : DriverControl : Compu Method */
typedef union
{
	uint16_t word; // 2-byte field
	struct {
	    OCP_ACT_STATUS OCP_ACT   : 1; // Bit 0
	    DIS_GDUV_STATUS DIS_GDUV : 1; // Bit 1
	    DIS_GDF_STATUS DIS_GDF   : 1; // Bit 2
	    OTW_REP_STATUS OTW_REP   : 1; // Bit 3
	    PWM_MODE_TYPE PWM_MODE   : 2; // Bits 4-5
	    PWM_COM_STATUS PWM_COM   : 1; // Bit 6
	    PWM_DIR_STATUS PWM_DIR   : 1; // Bit 7
	    COAST_STATUS COAST       : 1; // Bit 8
	    BRAKE_STATUS BRAKE       : 1; // Bit 9
	    CLR_FLT_STATUS CLR_FLT   : 1; // Bit 10
	    uint8_t reservedBits     : 5; // Reserved bits (11-15)
	} control_bits;
} cmDriverControl;

/* IDRV8353 : DriverControl : Data Constraint */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for DriverControl. */
    uint8_t upperLimit;      /**< Maximum valid value for DriverControl. */
    MonotonyType monotony;   /**< Monotony constraint for DriverControl values. */
} dcDriverControl;
/*************************************************************/

/*************************************************************/
/* IDRV8353 : GateDriveHS : Enumeration */

typedef enum {
    LOCK_UNLOCKED = 0b011, // Unlock all registers
    LOCK_LOCKED   = 0b110  // Lock all registers except these bits and address 0x02h bits 0-2
} LOCK_STATUS;

typedef enum {
    IDRIVEP_HS_50MA   = 0b0000, // 50 mA
    IDRIVEP_HS_100MA  = 0b0001, // 100 mA
    IDRIVEP_HS_150MA  = 0b0010, // 150 mA
    IDRIVEP_HS_300MA  = 0b0011, // 300 mA
    IDRIVEP_HS_350MA  = 0b0100, // 350 mA
    IDRIVEP_HS_400MA  = 0b0101, // 400 mA
    IDRIVEP_HS_450MA  = 0b0110, // 450 mA
    IDRIVEP_HS_550MA  = 0b0111, // 550 mA
    IDRIVEP_HS_600MA  = 0b1000, // 600 mA
    IDRIVEP_HS_650MA  = 0b1001, // 650 mA
    IDRIVEP_HS_700MA  = 0b1010, // 700 mA
    IDRIVEP_HS_850MA  = 0b1011, // 850 mA
    IDRIVEP_HS_900MA  = 0b1100, // 900 mA
    IDRIVEP_HS_950MA  = 0b1101, // 950 mA
    IDRIVEP_HS_1000MA = 0b1110  // 1000 mA
} IDRIVEP_HS_STATUS;

typedef enum {
    IDRIVEN_HS_100MA   = 0b0000, // 100 mA
    IDRIVEN_HS_200MA   = 0b0001, // 200 mA
    IDRIVEN_HS_300MA   = 0b0010, // 300 mA
    IDRIVEN_HS_400MA   = 0b0011, // 400 mA
    IDRIVEN_HS_500MA   = 0b0100, // 500 mA
    IDRIVEN_HS_600MA   = 0b0101, // 600 mA
    IDRIVEN_HS_700MA   = 0b0110, // 700 mA
    IDRIVEN_HS_800MA   = 0b0111, // 800 mA
    IDRIVEN_HS_900MA   = 0b1000, // 900 mA
    IDRIVEN_HS_1000MA  = 0b1001, // 1000 mA
    IDRIVEN_HS_1100MA  = 0b1010, // 1100 mA
    IDRIVEN_HS_1200MA  = 0b1011, // 1200 mA
    IDRIVEN_HS_1300MA  = 0b1100, // 1300 mA
    IDRIVEN_HS_1400MA  = 0b1101, // 1400 mA
    IDRIVEN_HS_1500MA  = 0b1110, // 1500 mA
    IDRIVEN_HS_2000MA  = 0b1111  // 2000 mA
} IDRIVEN_HS_STATUS;

/* IDRV8353 : GateDriveHS : Compu Method */
typedef union
{
    uint16_t word; // 2-byte field
    struct {
        LOCK_STATUS LOCK         : 3; // Bits 10-8
        IDRIVEP_HS_STATUS IDRIVEP_HS : 4; // Bits 7-4
        IDRIVEN_HS_STATUS IDRIVEN_HS : 4; // Bits 3-0
        uint8_t reservedBits     : 5; // Reserved bits
    } control_bits;
} cmGateDriveHS;

/* IDRV8353 : GateDriveHS : Data Constraint */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for GateDriveHS. */
    uint8_t upperLimit;      /**< Maximum valid value for GateDriveHS. */
    MonotonyType monotony;   /**< Monotony constraint for GateDriveHS values. */
} dcGateDriveHS;
/*************************************************************/

/*************************************************************/
/* IDRV8353 : GateDriveLS : Enumeration */

typedef enum {
    CBC_DISABLED = 0b0, // For VDS_OCP and SEN_OCP, the fault is cleared after tRETRY
    CBC_ENABLED  = 0b1  // For VDS_OCP and SEN_OCP, the fault is cleared when a new PWM input is given or after tRETRY
} CBC_STATUS;

typedef enum {
    TDRIVE_500NS  = 0b00, // 500-ns peak gate-current drive time
    TDRIVE_1000NS = 0b01, // 1000-ns peak gate-current drive time
    TDRIVE_2000NS = 0b10, // 2000-ns peak gate-current drive time
    TDRIVE_4000NS = 0b11  // 4000-ns peak gate-current drive time
} TDRIVE_STATUS;

typedef enum {
    IDRIVEP_LS_50MA   = 0b0000, // 50 mA
    IDRIVEP_LS_100MA  = 0b0001, // 100 mA
    IDRIVEP_LS_150MA  = 0b0010, // 150 mA
    IDRIVEP_LS_300MA  = 0b0011, // 300 mA
    IDRIVEP_LS_350MA  = 0b0100, // 350 mA
    IDRIVEP_LS_400MA  = 0b0101, // 400 mA
    IDRIVEP_LS_450MA  = 0b0110, // 450 mA
    IDRIVEP_LS_550MA  = 0b0111, // 550 mA
    IDRIVEP_LS_600MA  = 0b1000, // 600 mA
    IDRIVEP_LS_650MA  = 0b1001, // 650 mA
    IDRIVEP_LS_700MA  = 0b1010, // 700 mA
    IDRIVEP_LS_850MA  = 0b1011, // 850 mA
    IDRIVEP_LS_900MA  = 0b1100, // 900 mA
    IDRIVEP_LS_950MA  = 0b1101, // 950 mA
    IDRIVEP_LS_1000MA = 0b1110  // 1000 mA
} IDRIVEP_LS_STATUS;

typedef enum {
    IDRIVEN_LS_100MA   = 0b0000, // 100 mA
    IDRIVEN_LS_200MA   = 0b0001, // 200 mA
    IDRIVEN_LS_300MA   = 0b0010, // 300 mA
    IDRIVEN_LS_400MA   = 0b0011, // 400 mA
    IDRIVEN_LS_500MA   = 0b0100, // 500 mA
    IDRIVEN_LS_600MA   = 0b0101, // 600 mA
    IDRIVEN_LS_700MA   = 0b0110, // 700 mA
    IDRIVEN_LS_800MA   = 0b0111, // 800 mA
    IDRIVEN_LS_900MA   = 0b1000, // 900 mA
    IDRIVEN_LS_1000MA  = 0b1001, // 1000 mA
    IDRIVEN_LS_1100MA  = 0b1010, // 1100 mA
    IDRIVEN_LS_1200MA  = 0b1011, // 1200 mA
    IDRIVEN_LS_1300MA  = 0b1100, // 1300 mA
    IDRIVEN_LS_1400MA  = 0b1101, // 1400 mA
    IDRIVEN_LS_1500MA  = 0b1110, // 1500 mA
    IDRIVEN_LS_2000MA  = 0b1111  // 2000 mA
} IDRIVEN_LS_STATUS;

/* IDRV8353 : GateDriveLS : Compu Method */
typedef union
{
    uint16_t word; // 2-byte field
    struct {
        CBC_STATUS CBC               : 1; // Bit 10
        TDRIVE_STATUS TDRIVE         : 2; // Bits 9-8
        IDRIVEP_LS_STATUS IDRIVEP_LS : 4; // Bits 7-4
        IDRIVEN_LS_STATUS IDRIVEN_LS : 4; // Bits 3-0
        uint8_t reservedBits         : 5; // Reserved bits
    } control_bits;
} cmGateDriveLS;

/* IDRV8353 : GateDriveLS : Data Constraint */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for GateDriveLS. */
    uint8_t upperLimit;      /**< Maximum valid value for GateDriveLS. */
    MonotonyType monotony;   /**< Monotony constraint for GateDriveLS values. */
} dcGateDriveLS;
/*************************************************************/

/*************************************************************/
/* IDRV8353 : OCPControl : Enumeration */

typedef enum {
    TRETRY_8MS  = 0b0, // VDS_OCP and SEN_OCP retry time is 8 ms
    TRETRY_50US = 0b1  // VDS_OCP and SEN_OCP retry time is 50 μs
} TRETRY_STATUS;

typedef enum {
    DEAD_TIME_50NS  = 0b00, // 50-ns dead time
    DEAD_TIME_100NS = 0b01, // 100-ns dead time
    DEAD_TIME_200NS = 0b10, // 200-ns dead time
    DEAD_TIME_400NS = 0b11  // 400-ns dead time
} DEAD_TIME_STATUS;

typedef enum {
    OCP_MODE_LATCHED_FAULT = 0b00, // Overcurrent causes a latched fault
    OCP_MODE_AUTORETRY     = 0b01, // Overcurrent causes an automatic retrying fault
    OCP_MODE_REPORT_ONLY   = 0b10, // Overcurrent is reported but no action is taken
    OCP_MODE_NOT_REPORTED  = 0b11  // Overcurrent is not reported and no action is taken
} OCP_MODE_STATUS;

typedef enum {
    OCP_DEG_1US = 0b00, // Overcurrent deglitch of 1 μs
    OCP_DEG_2US = 0b01, // Overcurrent deglitch of 2 μs
    OCP_DEG_4US = 0b10, // Overcurrent deglitch of 4 μs
    OCP_DEG_8US = 0b11  // Overcurrent deglitch of 8 μs
} OCP_DEG_STATUS;

typedef enum {
    VDS_LVL_0_06V = 0b0000, // 0.06 V
    VDS_LVL_0_07V = 0b0001, // 0.07 V
    VDS_LVL_0_09V = 0b0010, // 0.09 V
    VDS_LVL_0_12V = 0b0011, // 0.12 V
    VDS_LVL_0_20V = 0b0100, // 0.20 V
    VDS_LVL_0_30V = 0b0101, // 0.30 V
    VDS_LVL_0_40V = 0b0110, // 0.40 V
    VDS_LVL_0_50V = 0b0111, // 0.50 V
    VDS_LVL_0_60V = 0b1000, // 0.60 V
    VDS_LVL_0_70V = 0b1001, // 0.70 V
    VDS_LVL_0_80V = 0b1010, // 0.80 V
    VDS_LVL_0_90V = 0b1011, // 0.90 V
    VDS_LVL_1_00V = 0b1100, // 1.00 V
    VDS_LVL_1_50V = 0b1101, // 1.50 V
    VDS_LVL_2_00V = 0b1110  // 2.00 V
} VDS_LVL_STATUS;

/* IDRV8353 : OCPControl : Compu Method */
typedef union
{
    uint16_t word; // 2-byte field
    struct {
        TRETRY_STATUS TRETRY       : 1; // Bit 10
        DEAD_TIME_STATUS DEAD_TIME : 2; // Bits 9-8
        OCP_MODE_STATUS OCP_MODE   : 2; // Bits 7-6
        OCP_DEG_STATUS OCP_DEG     : 2; // Bits 5-4
        VDS_LVL_STATUS VDS_LVL     : 4; // Bits 3-0
        uint8_t reservedBits       : 5; // Reserved bits
    } control_bits;
} cmOCPControl;

/* IDRV8353 : OCPControl : Data Constraint */
typedef struct
{
    uint8_t lowerLimit;      /**< Minimum valid value for OCPControl. */
    uint8_t upperLimit;      /**< Maximum valid value for OCPControl. */
    MonotonyType monotony;   /**< Monotony constraint for OCPControl values. */
} dcOCPControl;
/*************************************************************/


/*************************************************************/

#endif /* ABSTRACT_SMARTGATEDRIVER_H_ */