#include <cstdint>

#define PEDAL_BUFER_SIZE 10
typedef enum {
    PEDAL_BUSY,
    PEDAL_IDLE,
    PEDAL_ADC_READ_DONE,
	PEDAL_READY_TO_READ,
	PEDAL_READY_FOR_COMM,
	PEDAL_ERROR_LOG,
	PEDAL_ERROR
    
}state_t;
typedef enum{
	PEDAL_OK = 0,
	PEDAL_DATA_OUT_OF_RANGE,
}error_t;
typedef struct  {
    uint8_t  HighValue;
    uint8_t  LowValue;
    uint16_t Position;
    uint16_t PrevPosition;
    state_t  state;
    error_t  error;
    uint32_t Counter_error;
    uint8_t  Warning;
}Pedal_t;


typedef struct{
	uint16_t Position;
	uint8_t  Warning;
}CAN_Message_t;
uint8_t adc1,adc2,EngineRPM;
extern  Pedal_t Pedal;
extern  CAN_Message_t Message;
