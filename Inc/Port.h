#ifndef PORT_H_
#define PORT_H_

#include "Port_Types.h"
/*********************************************************************************************************
 *                                 Definiton of development errors in module Port                        *
 *********************************************************************************************************/

/* Function: Port_SetPinDirection
 * Error Condition: Incorrect Port Pin ID passed
 * Realted error value: PORT_E_PARAM_PIN 
 * */
#define PORT_E_PARAM_PIN                            (uint8)0x0A

/* Function: Port_SetPinDirection
 * Error Condition: Port Pin not configured as changeable
 * Realted error value: PORT_E_DIRECTION_UNCHANGEABLE 
 * */
#define PORT_E_DIRECTION_UNCHANGEABLE


/* Function: Port_Init
 * Error Condition: Port_Init service called with wrong parameter.
 * Realted error value: PORT_E_INIT_FAILED 
 * */
#define PORT_E_INIT_FAILED                          (uint8)0x0B 

/* Function: Port_SetPinMode
 * Error Condition: Incorrect Port Pin ID passed
 * Realted error value: PORT_E_PARAM_PIN 
 * */
#define PORT_E_PARAM_PIN                            (uint8)0x0C

/* Function: Port_SetPinMode
 * Error Condition: Port Pin Mode passed not valid
 * Realted error value: PORT_E_PARAM_INVALID_MODE 
 * */
#define PORT_E_PARAM_INVALID_MODE                   (uint8)0x0D

/* Function: Port_SetPinMode
 * Error Condition: Port_SetPinMode service called when the mode is unchangeable
 * Realted error value: PORT_E_MODE_UNCHANGEABLE 
 * */
#define PORT_E_MODE_UNCHANGEABLE                   (uint8)0x0E

/* Function: Port_SetPinDirection, Port_SetPinMode, Port_RefreshPortDirection
 * Error Condition: API service called prior to module initialization
 * Realted error value: PORT_E_UNINIT
 * */
#define PORT_E_UNINIT                               (uint8)0x0F

/* Function: Port_GetVersionInfo
 * Error Condition: Api called with a NULL Pointer Parameter
 * Realted error value: PORT_E_PARAM_POINTER 
 * */
#define PORT_E_PARAM_POINTER                        (uint8)0x10

/*********************************************************************************************************
 *                                              API Service Id Macros                                    *
 *********************************************************************************************************/
#define PORT_INIT_SID                               (uint8)0x00

#define PORT_SET_PIN_DIRECTION_SID                  (uint8)0x01

#define PORT_REFRESH_PORT_DIRECTION_SID             (uint8)0x02

#define PORT_GET_VERSION_INFO_SID                   (uint8)0x03

#define PORT_SET_PiN_MODE                           (uint8)0x04

/*********************************************************************************************************
 *                                               Function Prototypes                                     *
 *********************************************************************************************************/

/*********************************************************************************************************
 * Service Name: Port_Init
 * Service ID[hex]:0x00
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): ConfigPtr - Pointer to post-build configuration data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Initializes the Port Driver module:
 *              - Setup the Pin mode (e.g. DIO, ADC, SPI, PWM, ...)
 *              - Setup the  Pin direction (input, output)
 *              - Provide Pin level initial value for o/p pin
 *              - Setup the internal resistor for i/p pin
 *********************************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr);

/*********************************************************************************************************
 * Service Name: Port_SetpinDirection
 * Service ID[hex]:0x01
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): Pin: Port Pin ID number, Direction: Port Pin Direction
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Sets the port pin direction
 *********************************************************************************************************/
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);

/*********************************************************************************************************
 * Service Name: Port_RefreshPortDirection
 * Service ID[hex]:0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Refreshes port direction
 *********************************************************************************************************/
void Port_RefreshPortDirection(void);

/*********************************************************************************************************
 * Service Name: Port_GetVersionInfo
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
 * Return value: None
 * Description: Function to get the version information of this module.
 *********************************************************************************************************/
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);

/*********************************************************************************************************
 * Service Name: Port_SetPinMode
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Pin: Port Pin ID number, Mode: New Port Pin mode to be set on port pin
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Sets the port pin mode
 *********************************************************************************************************/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);


#endif /* PORT_H_ */