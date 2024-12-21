#ifndef PORT_H_
#define PORT_H_

#include "Port_Types.h"



void Port_Init(const Port_ConfigType* ConfigPtr);

#if(PORT_SET_PIN_DIRECTION_API == STD_ON)
    void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif

#if(PORT_SET_PIN_MODE_API == STD_ON)
    void Port_RefreshPortDirection(void);
#endif

#if(STD_ON == PORT_VERSION_INFO_API)
    void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif

void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);


#endif /* PORT_H_ */