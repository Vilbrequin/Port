#ifndef PORT_TYPES_H_
#define PORT_TYPES_H_

#include "Std_Types.h"

typedef uint8 Port_PinType; /* SWS_Port_00229 : Data type for the symbolic name of a port pin */
typedef enum {
    PORT_PIN_IN     = 0x00,
    PORT_PIN_OUT   = 0x01
}Port_PinDirectionType;


typedef uint8 Port_PortID;
#define PORT_A_ID                   (Port_PortID)0x00                             
#define PORT_B_ID                   (Port_PortID)0x01                 
#define PORT_C_ID                   (Port_PortID)0x02                 
#define PORT_D_ID                   (Port_PortID)0x03                 
#define PORT_E_ID                   (Port_PortID)0x04

typedef uint16 Port_PinType;
#define PORT_PIN_0                  (Port_PinType)0x00                             
#define PORT_PIN_1                  (Port_PinType)0x01                 
#define PORT_PIN_2                  (Port_PinType)0x02                 
#define PORT_PIN_3                  (Port_PinType)0x03                 
#define PORT_PIN_4                  (Port_PinType)0x04                 
#define PORT_PIN_5                  (Port_PinType)0x05                 
#define PORT_PIN_6                  (Port_PinType)0x06                 
#define PORT_PIN_7                  (Port_PinType)0x07                 
#define PORT_PIN_8                  (Port_PinType)0x08                 
#define PORT_PIN_9                  (Port_PinType)0x09                 
#define PORT_PIN_10                 (Port_PinType)0x0A
#define PORT_PIN_11                 (Port_PinType)0x0B
#define PORT_PIN_12                 (Port_PinType)0x0C
#define PORT_PIN_13                 (Port_PinType)0x0D
#define PORT_PIN_14                 (Port_PinType)0x0E
#define PORT_PIN_15                 (Port_PinType)0x0F
#define PORT_PIN_16                 (Port_PinType)0x10
#define PORT_PIN_17                 (Port_PinType)0x11            

typedef enum {
    OFF,
    PULL_UP,
    PULL_DOWN
}Port_InternalResistor;

typedef uint8 Port_PinModeType;
#define PORT_PIN_MODE_ALT_0          (Port_PinModeType)0x00
#define PORT_PIN_MODE_ALT_1          (Port_PinModeType)0x01
#define PORT_PIN_MODE_ALT_2          (Port_PinModeType)0x02
#define PORT_PIN_MODE_ALT_3          (Port_PinModeType)0x03
#define PORT_PIN_MODE_ALT_4          (Port_PinModeType)0x04
#define PORT_PIN_MODE_ALT_5          (Port_PinModeType)0x05
#define PORT_PIN_MODE_ALT_6          (Port_PinModeType)0x06    
#define PORT_PIN_MODE_ALT_7          (Port_PinModeType)0x07 

typedef uint8 Port_PinInterruptConfig;
#define ISF_FLAG_DISABLED                           (Port_PinInterruptConfig)0x00 /* 0000 */
#define ISF_FLAG_ENABLED_DMA_RISING_EDGE            (Port_PinInterruptConfig)0x01 /* 0001 */
#define ISF_FLAG_ENABLED_DMA_FALLING_EDGE           (Port_PinInterruptConfig)0x02 /* 0010 */
#define ISF_FLAG_ENABLED_DMA_EITHER_EDGE            (Port_PinInterruptConfig)0x03 /* 0011 */
#define ISF_FLAG_ENABLED_INTERRUPT_LOGIC_0          (Port_PinInterruptConfig)0x08 /* 1000 */
#define ISF_FLAG_ENABLED_INTERRUPT_RISING_EDGE      (Port_PinInterruptConfig)0x09 /* 1001 */
#define ISF_FLAG_ENABLED_INTERRUPT_FALLING_EDGE     (Port_PinInterruptConfig)0x0A /* 1010 */
#define ISF_FLAG_ENABLED_INTERRUPT_EITHER_EDGE      (Port_PinInterruptConfig)0x0B /* 1011 */
#define ISF_FLAG_ENABLED_INTERRUPT_LOGIC_1          (Port_PinInterruptConfig)0x0C /* 1100 */




typedef uint8 Port_PinLevelValueType;
#define PORT_PIN_LEVEL_LOW                          (Port_PinLevelValueType)0x00
#define PORT_PIN_LEVEL_HIGH                         (Port_PinLevelValueType)0x01

typedef uint8 Port_PinDriveStrengthType;
#define PORT_PIN_LOW_DRIVE_STRENGTH                 (Port_PinDriveStrengthType)0x00
#define PORT_PIN_HIGH_DRIVE_STRENGTH                (Port_PinDriveStrengthType)0x01
typedef struct {
    Port_PortID PortID;
    Port_PinType PortPinId;
    Port_PinModeType PortPinInitialMode;
    Port_PinModeType PortPinMode;
    Port_PinLevelValueType PortPinLevelValue;
    Port_PinDirectionType PortPinDirection;
    Port_InternalResistor PortPinInternalResistor;
    Port_PinInterruptConfig PortPinInterrupt;
    Port_PinDriveStrengthType PortPinDriveStrength;
    boolean PortPinPassifFilter;
    boolean PortPinDirectionChangeable;
    boolean PortPinModeChangeable;
    /* PortPinEcucPartitionRef */
}Port_PinConfigType;

typedef struct {
    uint16 PortNumberOfPortPins;
    Port_PinConfigType *Pin;
}Port_ContainerType;

typedef struct {
    Port_ContainerType* Port_Container;
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