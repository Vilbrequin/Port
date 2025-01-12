#include "Port.h"
#include "Det.h"

static uint8 Port_Status = PORT_NOT_INITIALIZED;
static Port_ContainerType *container = NULL_PTR;

static Port_PortID get_portId(Port_PinType pin)
{
    Port_PortID port_id;
    port_id = (Port_PortID)(pin / PINS_PER_PORT);

    return port_id;
}

static Port_PinType get_pinId(Port_PinType pin)
{
    Port_PinType pin_id;
    pin_id = (Port_PinType)(pin % PINS_PER_PORT);

    return pin_id;
}

void Port_Init(const Port_ConfigType *ConfigPtr)
{
    #if( STD_ON == PORT_DEV_ERROR_DETECT)
        if( (NULL_PTR == ConfigPtr) || (NULL_PTR == ConfigPtr->Port_Container)){
            Det_ReportError(PORT_MODULE_ID, PORT_MODULE_INSTANCE_ID, PORT_INIT_SID, PORT_E_INIT_FAILED);
            return;
        }
    #endif

    container = ConfigPtr->Port_Container;

    for (uint16 i = 0; i < container->PortNumberOfPortPins; i++)
    {

        Port_PinConfigType *pin_config = &container->Pin[i];

        volatile uint32 *pcc_address = NULL_PTR;          /* peripheral clock controller register address */
        volatile uint32 *port_x_pcr_n_address = NULL_PTR; /* holds the pin control register address, where x : [A-E] and n : [0-17] */
        volatile uint32 *gpio_pddr_address = NULL_PTR; /* holds port data direction register */
        volatile uint32 *gpio_pdor_address = NULL_PTR;

        Port_PortID port_id = get_portId(pin_config->PortPinId);
        Port_PinType local_pin_id = get_pinId(pin_config->PortPinId);

        switch (port_id)
        {
        case PORT_A_ID:
            pcc_address = (volatile uint32 *)PCC_PORT_A;
            port_x_pcr_n_address = (volatile uint32 *)(PORT_A_BASE_ADDRESS + (4 * local_pin_id));
            gpio_pddr_address = (volatile uint32 *)GPIO_A_PDDR;
            gpio_pdor_address = (volatile uint32*)GPIO_A_PDOR;
            break;
        case PORT_B_ID:
            pcc_address = (volatile uint32 *)PCC_PORT_B;
            port_x_pcr_n_address = (volatile uint32 *)(PORT_B_BASE_ADDRESS + (4 * local_pin_id));
            gpio_pddr_address = (volatile uint32 *)GPIO_B_PDDR;
            gpio_pdor_address = (volatile uint32*)GPIO_B_PDOR;
            break;
        case PORT_C_ID:
            pcc_address = (volatile uint32 *)PCC_PORT_C;
            port_x_pcr_n_address = (volatile uint32 *)(PORT_C_BASE_ADDRESS + (4 * local_pin_id));
            gpio_pddr_address = (volatile uint32 *)GPIO_C_PDDR;
            gpio_pdor_address = (volatile uint32*)GPIO_C_PDOR;
            break;
        case PORT_D_ID:
            pcc_address = (volatile uint32 *)PCC_PORT_D;
            port_x_pcr_n_address = (volatile uint32 *)(PORT_D_BASE_ADDRESS + (4 * local_pin_id));
            gpio_pddr_address = (volatile uint32 *)GPIO_D_PDDR;
            gpio_pdor_address = (volatile uint32*)GPIO_D_PDOR;
            break;
        case PORT_E_ID:
            pcc_address = (volatile uint32 *)PCC_PORT_E;
            port_x_pcr_n_address = (volatile uint32 *)(PORT_E_BASE_ADDRESS + (4 * local_pin_id));
            gpio_pddr_address = (volatile uint32 *)GPIO_E_PDDR;
            gpio_pdor_address = (volatile uint32*)GPIO_E_PDOR;
            break;
        default:
            // Do Nothing
            break;
        }

        // Enable Clock Gate Control bit of the corresponding PCC Regester
        SET_BIT(*(volatile uint32 *)pcc_address, PCC_CGC_BIT);

        
        // PCR[MUX]
        switch (pin_config->PortPinMode)
        {
        case PORT_PIN_MODE_ALT_0:
            /*Before entering Analog mode PUE and PUS should be configured as 0 in corresponding PCR register */
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_PE_BIT);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_PS_BIT);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_0);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_2);
            break;
        case PORT_PIN_MODE_ALT_1:
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_0);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_2);
            break;
        case PORT_PIN_MODE_ALT_2:
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_0);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_2);
            break;
        case PORT_PIN_MODE_ALT_3:
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_0);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_2);
            break;
        case PORT_PIN_MODE_ALT_4:
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_0);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_1);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_2);
            break;
        case PORT_PIN_MODE_ALT_5:
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_0);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_1);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_2);
            break;
        case PORT_PIN_MODE_ALT_6:
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_0);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_1);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_2);
            break;
        case PORT_PIN_MODE_ALT_7:
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_0);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_1);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_MUX_BIT_2);
            break;
        default:
            // Do Nothing
            break;
        }

        // Set Direction
        if (PORT_PIN_MODE_ALT_0 != pin_config->PortPinMode)
        {
            if (PORT_PIN_IN == pin_config->PortPinDirection)
            {
                CLEAR_BIT(*(volatile uint32 *)gpio_pddr_address, local_pin_id);
            }
            else if (PORT_PIN_OUT == pin_config->PortPinDirection)
            {
                SET_BIT(*(volatile uint32 *)gpio_pddr_address, local_pin_id);
                if (PORT_PIN_LEVEL_HIGH == pin_config->PortPinLevelValue)
                {
                    SET_BIT(*(volatile uint32 *)gpio_pdor_address, local_pin_id);
                }
                else if (PORT_PIN_LEVEL_LOW == pin_config->PortPinLevelValue)
                {
                    CLEAR_BIT(*(volatile uint32 *)gpio_pdor_address, local_pin_id);
                }
                else
                {
                    /* Do Nothing */
                }
            }
            else
            {
                /* Do Nothing */
            }
        }
        else
        {
            /* Do Nothing */
        }
    }
    
    Port_Status = PORT_INITIALIZED;
}


#if(STD_ON == PORT_SET_PIN_DIRECTION_API)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction){
    #if (STD_ON == PORT_DEV_ERROR_DETECT)
        if (PORT_NOT_INITIALIZED == Port_Status)
        {
            Det_ReportError(PORT_MODULE_ID, PORT_MODULE_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
            return;
        }
        if (STD_OFF == container->Pin[Pin].PortPinDirectionChangeable)
        {
            Det_ReportError(PORT_MODULE_ID, PORT_MODULE_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
            return;
        }
        if ((Pin < 0) || (Pin >= PORT_NUMBER_OF_CONFIGURED_PINS))
        {
            Det_ReportError(PORT_MODULE_ID, PORT_MODULE_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
            return;
        }
    #endif

    volatile uint32* gpio_pddr = NULL_PTR;
    volatile uint32* gpio_pdor = NULL_PTR;

    Port_PinConfigType *pin_config = &container->Pin[Pin];

    Port_PortID port_id = get_portId(Pin);
    Port_PinType local_pin = get_pinId(Pin);

    switch (port_id)
    {
    case PORT_A_ID:
        gpio_pddr = (volatile uint32 *)GPIO_A_PDDR;
        gpio_pdor = (volatile uint32 *)GPIO_A_PDOR;
        break;
    case PORT_B_ID:
        gpio_pddr = (volatile uint32 *)GPIO_B_PDDR;
        gpio_pdor = (volatile uint32 *)GPIO_B_PDOR;
        break;
    case PORT_C_ID:
        gpio_pddr = (volatile uint32 *)GPIO_C_PDDR;
        gpio_pdor = (volatile uint32 *)GPIO_C_PDOR;
        break;
    case PORT_D_ID:
        gpio_pddr = (volatile uint32 *)GPIO_D_PDDR;
        gpio_pdor = (volatile uint32 *)GPIO_D_PDOR;
        break;
    case PORT_E_ID:
        gpio_pddr = (volatile uint32 *)GPIO_E_PDDR;
        gpio_pdor = (volatile uint32 *)GPIO_E_PDOR;
        break;
    default:
        /* Do Nothing */
        break;
    }
    
    if (PORT_PIN_IN == Direction)
    {
        CLEAR_BIT(*(volatile uint32 *)gpio_pddr, local_pin);
    }
    else if (PORT_PIN_OUT == Direction)
    {
        SET_BIT(*(volatile uint32 *)gpio_pddr, local_pin);
        if (PORT_PIN_LEVEL_HIGH == pin_config->PortPinLevelValue)
        {
            SET_BIT(*(volatile uint32 *)gpio_pdor, local_pin);
        }
        else if (PORT_PIN_LEVEL_LOW == pin_config->PortPinLevelValue)
        {
            CLEAR_BIT(*(volatile uint32 *)gpio_pdor, local_pin);
        }
        else
        {
            /* Do Nothing */
        }
    }
    else
    {
        /* Do Nothing */
    }
}
#endif

void Port_RefreshPortDirection(void){
    #if( STD_ON == PORT_DEV_ERROR_DETECT)
        if (PORT_NOT_INITIALIZED == Port_Status)
        {
            Det_ReportError(PORT_MODULE_ID, PORT_MODULE_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
            return;
        }
    #endif

    volatile uint32* gpio_pddr = NULL_PTR;
    volatile uint32* gpio_pdor = NULL_PTR;

    Port_PinConfigType * Pin = NULL_PTR;
    Port_PortID port_id;
    Port_PinType local_pin;

    for(uint16 i = 0; i < container->PortNumberOfPortPins; i++){
        Pin = &container->Pin[i];
        port_id = get_portId(Pin->PortPinId);
        local_pin = get_pinId(Pin->PortPinId);

        switch (port_id)
        {
        case PORT_A_ID:
            gpio_pddr = (volatile uint32 *)GPIO_A_PDDR;
            gpio_pdor = (volatile uint32 *)GPIO_A_PDOR;
            break;
        case PORT_B_ID:
            gpio_pddr = (volatile uint32 *)GPIO_B_PDDR;
            gpio_pdor = (volatile uint32 *)GPIO_B_PDOR;
            break;
        case PORT_C_ID:
            gpio_pddr = (volatile uint32 *)GPIO_C_PDDR;
            gpio_pdor = (volatile uint32 *)GPIO_C_PDOR;
            break;
        case PORT_D_ID:
            gpio_pddr = (volatile uint32 *)GPIO_D_PDDR;
            gpio_pdor = (volatile uint32 *)GPIO_D_PDOR;
            break;
        case PORT_E_ID:
            gpio_pddr = (volatile uint32 *)GPIO_E_PDDR;
            gpio_pdor = (volatile uint32 *)GPIO_E_PDOR;
            break;
        default:
            /* Do Nothing */
            break;
        }
    /* exclude port pins from refreshing that are configured as "pin direction changeable during runtime" */
        if (STD_OFF == Pin->PortPinDirectionChangeable)
        {
            if (PORT_PIN_IN == Pin->PortPinDirection)
            {
                CLEAR_BIT(*(volatile uint32 *)gpio_pddr, local_pin);
            }
            else if (PORT_PIN_OUT == Pin->PortPinDirection)
            {
                SET_BIT(*(volatile uint32 *)gpio_pddr, local_pin);

                if (PORT_PIN_LEVEL_HIGH == Pin->PortPinLevelValue)
                {
                    SET_BIT(*(volatile uint32 *)gpio_pdor, local_pin);
                }
                else if (PORT_PIN_LEVEL_LOW == Pin->PortPinLevelValue)
                {
                    CLEAR_BIT(*(volatile uint32 *)gpio_pdor, local_pin);
                }
                else
                {
                    /* Do Nothing */
                }
            }
            else
            {
                /* Do Nothing */
            }
        }
    }
}
#if(STD_ON == PORT_VERSION_INFO_API)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo){
    #if( STD_ON == PORT_DEV_ERROR_DETECT)
        if (NULL_PTR == versioninfo)
        {
            Det_ReportError(PORT_MODULE_ID, PORT_MODULE_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_UNINIT);
            return;
        }
    #endif
    versioninfo->moduleID = (uint16)PORT_MODULE_ID;
    versioninfo->sw_major_version = (uint8)PORT_MODULE_MAJOR_VERSION;
    versioninfo->sw_minor_version = (uint8)PORT_MODULE_MINOR_VERSION;
    versioninfo->sw_patch_version = (uint8)PORT_MODULE_PATCH_VERSION;
    versioninfo->vendorID = (uint16)PORT_MODULE_VENDOR_ID;
}
#endif

#if(STD_ON == PORT_SET_PIN_MODE_API)
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode){
    #if( STD_ON == PORT_DEV_ERROR_DETECT)
        if (PORT_NOT_INITIALIZED == Port_Status)
        {
            Det_ReportError(PORT_MODULE_ID, PORT_MODULE_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
            return;
        }
        if (STD_OFF == container->Pin[Pin].PortPinModeChangeable)
        {
            Det_ReportError(PORT_MODULE_ID, PORT_MODULE_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_MODE_UNCHANGEABLE);
            return;
        }
        if ((Pin < 0) || (Pin >= PORT_NUMBER_OF_CONFIGURED_PINS))
        {
            Det_ReportError(PORT_MODULE_ID, PORT_MODULE_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
            return;
        }
        if ((Mode < 0) || (PORT_PIN_MODES < Mode))
        {
            Det_ReportError(PORT_MODULE_ID, PORT_MODULE_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_INVALID_MODE);
            return;
        }
    #endif

    volatile uint32* port_x_pcr_n = NULL_PTR;

    Port_PinConfigType *pin_config = &container->Pin[Pin];

    Port_PortID port_id = get_portId(Pin);
    Port_PinType local_pin = get_pinId(Pin);

    switch (port_id)
    {
    case PORT_A_ID:
        port_x_pcr_n = (volatile uint32 *)(PORT_A_BASE_ADDRESS + (4 * local_pin));
        break;
    case PORT_B_ID:
        port_x_pcr_n = (volatile uint32 *)(PORT_B_BASE_ADDRESS + (4 * local_pin));
        break;
    case PORT_C_ID:
        port_x_pcr_n = (volatile uint32 *)(PORT_C_BASE_ADDRESS + (4 * local_pin));
        break;
    case PORT_D_ID:
        port_x_pcr_n = (volatile uint32 *)(PORT_D_BASE_ADDRESS + (4 * local_pin));
        break;
    case PORT_E_ID:
        port_x_pcr_n = (volatile uint32 *)(PORT_E_BASE_ADDRESS + (4 * local_pin));
        break;
    default:
        /* Do Nothing */
        break;
    }
    switch (pin_config->PortPinMode)
        {
        case PORT_PIN_MODE_ALT_0:
            /*Before entering Analog mode PE and PS should be configured as 0 in corresponding PCR register */
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_PE_BIT);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_PS_BIT);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_0);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_2);
            break;
        case PORT_PIN_MODE_ALT_1:
            SET_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_0);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_2);
            break;
        case PORT_PIN_MODE_ALT_2:
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_0);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_2);
            break;
        case PORT_PIN_MODE_ALT_3:
            SET_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_0);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_2);
            break;
        case PORT_PIN_MODE_ALT_4:
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_0);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_1);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_2);
            break;
        case PORT_PIN_MODE_ALT_5:
            SET_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_0);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_1);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_2);
            break;
        case PORT_PIN_MODE_ALT_6:
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_0);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_1);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_2);
            break;
        case PORT_PIN_MODE_ALT_7:
            SET_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_0);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_1);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n, PCR_MUX_BIT_2);
            break;
        default:
            // Do Nothing
            break;
        }
}
#endif