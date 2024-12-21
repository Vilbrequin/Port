#ifndef PORT_TYPES_H_
#define PORT_TYPES_H_

#include "Std_Types.h"

typedef enum {
    PORT_PIN_IN     = 0x00,
    PORT_PIN_IOUT   = 0x01
}Port_PinDirectionType;

typedef uint8 Port_PinModeType;

#define PORT_PIN_MODE_ADC           (Port_PinModeType)0x00
#define PORT_PIN_MODE_CAN           (Port_PinModeType)0x01
#define PORT_PIN_MODE_DIO           (Port_PinModeType)0x02
#define PORT_PIN_MODE_DIO_GPT       (Port_PinModeType)0x03
#define PORT_PIN_MODE_DIO_WDG       (Port_PinModeType)0x04
#define PORT_PIN_MODE_FLEXRAY       (Port_PinModeType)0x05
#define PORT_PIN_MODE_ICU           (Port_PinModeType)0x06    
#define PORT_PIN_MODE_LIN           (Port_PinModeType)0x07 
#define PORT_PIN_MODE_MEM           (Port_PinModeType)0x08
#define PORT_PIN_MODE_PWM           (Port_PinModeType)0x09
#define PORT_PIN_MODE_SPI           (Port_PinModeType)0x0A


typedef uint8 Port_PinLevelValueType;
#define PORT_PIN_LEVEL_LOW          (Port_PinLevelValueType)0x00
#define PORT_PIN_LEVEL_HIGH         (Port_PinLevelValueType)0x01

typedef struct {
    Port_PinDirectionType PortPinDirection;
    boolean PortPinDirectionChangeable;
    uint16 PortPinId;
    Port_PinModeType PortPinInitialMode;
    Port_PinLevelValueType PortPinLevelValue;
    Port_PinModeType PortPinMode;
    boolean PortPinModeChangeable;
    /* PortPinEcucPartitionRef */
}Port_PinType;

typedef struct {
    uint16 PortNumberOfPortPins;
    Port_PinType *Pin;
}Port_ContainerType;

typedef struct {
    Port_ContainerType* Port_ContainerType;
}Port_ConfigType;

typedef struct {
    boolean PortDevErrorDetect;
    boolean PortSetPinDirectionApi;
    boolean PortSetPinModeApi;
    boolean PortVersionInfoApi;
    /* PortEcucPartitionRef */
}Port_GeneralType;

typedef struct{
    Port_ConfigType PortConfigSet;
    Port_GeneralType PortGeneral;
}Port_Type;

#endif /* PORT_TYPES_H_ */