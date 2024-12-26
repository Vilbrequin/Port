#ifndef PORT_TYPES_H_
#define PORT_TYPES_H_

#include "Std_Types.h"

typedef uint8 Port_PinType; /* SWS_Port_00229 : Data type for the symbolic name of a port pin */
typedef enum {
    PORT_PIN_IN     = 0x00,
    PORT_PIN_IOUT   = 0x01
}Port_PinDirectionType;


typedef uint8 Port_PortID;

#define PORT_A_ID                   (Port_PortID)0x00;                             
#define PORT_B_ID                   (Port_PortID)0x01;                 
#define PORT_C_ID                   (Port_PortID)0x02;                 
#define PORT_D_ID                   (Port_PortID)0x03;                 
#define PORT_E_ID                   (Port_PortID)0x04;                 
#define PORT_F_ID                   (Port_PortID)0x05; 

typedef uint16 Port_PinID;

#define PORT_PIN_0                  (Port_PinID)0x00;                             
#define PORT_PIN_1                  (Port_PinID)0x01;                 
#define PORT_PIN_2                  (Port_PinID)0x02;                 
#define PORT_PIN_3                  (Port_PinID)0x03;                 
#define PORT_PIN_4                  (Port_PinID)0x04;                 
#define PORT_PIN_5                  (Port_PinID)0x05;                 
#define PORT_PIN_6                  (Port_PinID)0x06;                 
#define PORT_PIN_7                  (Port_PinID)0x07;                 
#define PORT_PIN_8                  (Port_PinID)0x08;                 
#define PORT_PIN_9                  (Port_PinID)0x09;                 
#define PORT_PIN_10                 (Port_PinID)0x0A;
#define PORT_PIN_11                 (Port_PinID)0x0B;
#define PORT_PIN_12                 (Port_PinID)0x0C;
#define PORT_PIN_13                 (Port_PinID)0x0D;
#define PORT_PIN_14                 (Port_PinID)0x0E;
#define PORT_PIN_15                 (Port_PinID)0x0F;
#define PORT_PIN_16                 (Port_PinID)0x10;
#define PORT_PIN_17                 (Port_PinID)0x11;            

typedef uint8 Port_PinModeType;

typedef enum {
    OFF,
    PULL_UP,
    PULL_DOWN
}Port_InternalResistor;

#define PORT_PIN_MODE_ALT_0          (Port_PinModeType)0x00
#define PORT_PIN_MODE_ALT_1          (Port_PinModeType)0x01
#define PORT_PIN_MODE_ALT_2          (Port_PinModeType)0x02
#define PORT_PIN_MODE_ALT_3          (Port_PinModeType)0x03
#define PORT_PIN_MODE_ALT_4          (Port_PinModeType)0x04
#define PORT_PIN_MODE_ALT_5          (Port_PinModeType)0x05
#define PORT_PIN_MODE_ALT_6          (Port_PinModeType)0x06    
#define PORT_PIN_MODE_ALT_7          (Port_PinModeType)0x07 


typedef uint8 Port_PinLevelValueType;
#define PORT_PIN_LEVEL_LOW          (Port_PinLevelValueType)0x00
#define PORT_PIN_LEVEL_HIGH         (Port_PinLevelValueType)0x01

typedef struct {
    Port_PortID portID;
    Port_PinID PortPinId;
    Port_PinModeType PortPinInitialMode;
    Port_PinModeType PortPinMode;
    Port_PinLevelValueType PortPinLevelValue;
    Port_PinDirectionType PortPinDirection;
    Port_InternalResistor PortInternalResistor;
    boolean PortPinDirectionChangeable;
    boolean PortPinModeChangeable;
    /* PortPinEcucPartitionRef */
}Port_PinConfigType;

typedef struct {
    uint16 PortNumberOfPortPins;
    Port_PinConfigType *Pin;
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