#ifndef PORT_TYPES_H_
#define PORT_TYPES_H_

#include "Std_Types.h"

typedef uint8 Port_PinType; /* SWS_Port_00229 : Data type for the symbolic name of a port pin */
typedef enum {
    PORT_PIN_IN     = 0x00,
    PORT_PIN_OUT   = 0x01
}Port_PinDirectionType;


typedef uint8 Port_PortID;
#define PORT_A_ID                       (Port_PortID)0x00                             
#define PORT_B_ID                       (Port_PortID)0x01                 
#define PORT_C_ID                       (Port_PortID)0x02                 
#define PORT_D_ID                       (Port_PortID)0x03                 
#define PORT_E_ID                       (Port_PortID)0x04

typedef uint16 Port_PinType;

/* Symbolic names for the individual port pins */
/*********************** PORTA *************************/
#define PORT_A_PIN_0                    (Port_PinType)0x00                             
#define PORT_A_PIN_1                    (Port_PinType)0x01                 
#define PORT_A_PIN_2                    (Port_PinType)0x02                 
#define PORT_A_PIN_3                    (Port_PinType)0x03                 
#define PORT_A_PIN_4                    (Port_PinType)0x04                 
#define PORT_A_PIN_5                    (Port_PinType)0x05                 
#define PORT_A_PIN_6                    (Port_PinType)0x06                 
#define PORT_A_PIN_7                    (Port_PinType)0x07                 
#define PORT_A_PIN_8                    (Port_PinType)0x08                 
#define PORT_A_PIN_9                    (Port_PinType)0x09                 
#define PORT_A_PIN_10                   (Port_PinType)0x0A
#define PORT_A_PIN_11                   (Port_PinType)0x0B
#define PORT_A_PIN_12                   (Port_PinType)0x0C
#define PORT_A_PIN_13                   (Port_PinType)0x0D
#define PORT_A_PIN_14                   (Port_PinType)0x0E
#define PORT_A_PIN_15                   (Port_PinType)0x0F
#define PORT_A_PIN_16                   (Port_PinType)0x10
#define PORT_A_PIN_17                   (Port_PinType)0x11            

/*********************** PORTA *************************/
#define PORT_B_PIN_0                    (Port_PinType)0x12                             
#define PORT_B_PIN_1                    (Port_PinType)0x13                 
#define PORT_B_PIN_2                    (Port_PinType)0x14                 
#define PORT_B_PIN_3                    (Port_PinType)0x15                 
#define PORT_B_PIN_4                    (Port_PinType)0x16                 
#define PORT_B_PIN_5                    (Port_PinType)0x17                 
#define PORT_B_PIN_6                    (Port_PinType)0x18                 
#define PORT_B_PIN_7                    (Port_PinType)0x19                 
#define PORT_B_PIN_8                    (Port_PinType)0x1A                 
#define PORT_B_PIN_9                    (Port_PinType)0x1B                 
#define PORT_B_PIN_10                   (Port_PinType)0x1C
#define PORT_B_PIN_11                   (Port_PinType)0x1D
#define PORT_B_PIN_12                   (Port_PinType)0x1E
#define PORT_B_PIN_13                   (Port_PinType)0x1F
#define PORT_B_PIN_14                   (Port_PinType)0x20
#define PORT_B_PIN_15                   (Port_PinType)0x21
#define PORT_B_PIN_16                   (Port_PinType)0x22
#define PORT_B_PIN_17                   (Port_PinType)0x23  

/*********************** PORTC *************************/
#define PORT_C_PIN_0                    (Port_PinType)0x24                             
#define PORT_C_PIN_1                    (Port_PinType)0x25                 
#define PORT_C_PIN_2                    (Port_PinType)0x26                 
#define PORT_C_PIN_3                    (Port_PinType)0x27                 
#define PORT_C_PIN_4                    (Port_PinType)0x28                 
#define PORT_C_PIN_5                    (Port_PinType)0x29                 
#define PORT_C_PIN_6                    (Port_PinType)0x2A                 
#define PORT_C_PIN_7                    (Port_PinType)0x2B                 
#define PORT_C_PIN_8                    (Port_PinType)0x2C                 
#define PORT_C_PIN_9                    (Port_PinType)0x2D                 
#define PORT_C_PIN_10                   (Port_PinType)0x2E
#define PORT_C_PIN_11                   (Port_PinType)0x2F
#define PORT_C_PIN_12                   (Port_PinType)0x30
#define PORT_C_PIN_13                   (Port_PinType)0x31
#define PORT_C_PIN_14                   (Port_PinType)0x32
#define PORT_C_PIN_15                   (Port_PinType)0x33
#define PORT_C_PIN_16                   (Port_PinType)0x34
#define PORT_C_PIN_17                   (Port_PinType)0x35

/*********************** PORTD *************************/
#define PORT_D_PIN_0                    (Port_PinType)0x36                             
#define PORT_D_PIN_1                    (Port_PinType)0x37                 
#define PORT_D_PIN_2                    (Port_PinType)0x38                 
#define PORT_D_PIN_3                    (Port_PinType)0x39                 
#define PORT_D_PIN_4                    (Port_PinType)0x3A                 
#define PORT_D_PIN_5                    (Port_PinType)0x3B                 
#define PORT_D_PIN_6                    (Port_PinType)0x3C                 
#define PORT_D_PIN_7                    (Port_PinType)0x3D                 
#define PORT_D_PIN_8                    (Port_PinType)0x3E                 
#define PORT_D_PIN_9                    (Port_PinType)0x3F                 
#define PORT_D_PIN_10                   (Port_PinType)0x40
#define PORT_D_PIN_11                   (Port_PinType)0x41
#define PORT_D_PIN_12                   (Port_PinType)0x42
#define PORT_D_PIN_13                   (Port_PinType)0x43
#define PORT_D_PIN_14                   (Port_PinType)0x44
#define PORT_D_PIN_15                   (Port_PinType)0x45
#define PORT_D_PIN_16                   (Port_PinType)0x46
#define PORT_D_PIN_17                   (Port_PinType)0x47

/*********************** PORTE *************************/
#define PORT_E_PIN_0                    (Port_PinType)0x48                             
#define PORT_E_PIN_1                    (Port_PinType)0x49                 
#define PORT_E_PIN_2                    (Port_PinType)0x4A                 
#define PORT_E_PIN_3                    (Port_PinType)0x4B                 
#define PORT_E_PIN_4                    (Port_PinType)0x4C                 
#define PORT_E_PIN_5                    (Port_PinType)0x4D                 
#define PORT_E_PIN_6                    (Port_PinType)0x4E                 
#define PORT_E_PIN_7                    (Port_PinType)0x4F                 
#define PORT_E_PIN_8                    (Port_PinType)0x50                 
#define PORT_E_PIN_9                    (Port_PinType)0x51                 
#define PORT_E_PIN_10                   (Port_PinType)0x52
#define PORT_E_PIN_11                   (Port_PinType)0x53
#define PORT_E_PIN_12                   (Port_PinType)0x54
#define PORT_E_PIN_13                   (Port_PinType)0x55
#define PORT_E_PIN_14                   (Port_PinType)0x56
#define PORT_E_PIN_15                   (Port_PinType)0x57
#define PORT_E_PIN_16                   (Port_PinType)0x58

#define PINS_PER_PORT                   (uint8)18                    
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
    Port_PinType PortPinId;
    boolean PortPinDirectionChangeable;
    Port_PinLevelValueType PortPinLevelValue;
    Port_PinDirectionType PortPinDirection;
    Port_PinModeType PortPinMode;
    Port_PinModeType PortPinInitialMode;
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