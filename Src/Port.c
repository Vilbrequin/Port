#include "Port.h"

void Port_Init(const Port_ConfigType *ConfigPtr)
{
    #if( STD_ON == PORT_DEV_ERROR_DETECT)
        if( (NULL_PTR == ConfigPtr) || (NULL_PTR == ConfigPtr->Port_Container)){
            Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_INIT_FAILED);
            return;
        }
    #endif
    Port_ContainerType *container = ConfigPtr->Port_Container;

    for (uint16 i = 0; i < container->PortNumberOfPortPins; i++)
    {

        Port_PinConfigType *pin_config = &container->Pin[i];

        volatile uint32 *port_base_address = NULL_PTR;
        volatile uint32 *pcc_address = NULL_PTR;          /* peripheral clock controller register address */
        volatile uint32 *port_x_pcr_n_address = NULL_PTR; /* holds the pin control register address, where x : [A-E] and n : [0-17] */
        volatile uint32 *gpio_pddr_address = NULL_PTR; /* holds port data direction register */

        switch (pin_config->PortID)
        {
        case PORT_A_ID:
            port_base_address = (volatile uint32 *)PORT_A_BASE_ADDRESS;
            pcc_address = (volatile uint32 *)PCC_PORT_A;
            port_x_pcr_n_address = (volatile uint32 *)((uint32)port_base_address + (4 * pin_config->PortPinId));
            gpio_pddr_address = (volatile uint32 *)GPIO_A_PDDR;
            break;
        case PORT_B_ID:
            port_base_address = (volatile uint32 *)PORT_B_BASE_ADDRESS;
            pcc_address = (volatile uint32 *)PCC_PORT_B;
            port_x_pcr_n_address = (volatile uint32 *)((uint32)port_base_address + (4 * pin_config->PortPinId));
            gpio_pddr_address = (volatile uint32 *)GPIO_B_PDDR;
            break;
        case PORT_C_ID:
            port_base_address = (volatile uint32 *)PORT_C_BASE_ADDRESS;
            pcc_address = (volatile uint32 *)PCC_PORT_C;
            port_x_pcr_n_address = (volatile uint32 *)((uint32)port_base_address + (4 * pin_config->PortPinId));
            gpio_pddr_address = (volatile uint32 *)GPIO_C_PDDR;
            break;
        case PORT_D_ID:
            port_base_address = (volatile uint32 *)PORT_D_BASE_ADDRESS;
            pcc_address = (volatile uint32 *)PCC_PORT_D;
            port_x_pcr_n_address = (volatile uint32 *)((uint32)port_base_address + (4 * pin_config->PortPinId));
            gpio_pddr_address = (volatile uint32 *)GPIO_D_PDDR;
            break;
        case PORT_E_ID:
            port_base_address = (volatile uint32 *)PORT_E_BASE_ADDRESS;
            pcc_address = (volatile uint32 *)PCC_PORT_E;
            port_x_pcr_n_address = (volatile uint32 *)((uint32)port_base_address + (4 * pin_config->PortPinId));
            gpio_pddr_address = (volatile uint32 *)GPIO_E_PDDR;
            break;
        default:
            // Do Nothing
            break;
        }

        // Enable Clock Gate Control bit of the corresponding PCC Regester
        SET_BIT(*(volatile uint32 *)pcc_address, PCC_CGC_BIT);

        // Set fields of PCC Register
        
        //PCR[PS-PE]
        if (OFF == pin_config->PortPinInternalResistor)
        {
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_PE_BIT);
        }
        else if (PULL_UP == pin_config->PortPinInternalResistor)
        {
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_PS_BIT);
        }
        else if (PULL_DOWN == pin_config->PortPinInternalResistor)
        {
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_PS_BIT);
        }
        else
        {
            // Do Nothing
        }

        // PORT_PCRn[PFE] is configurable for only PTA5 and PTD3 PFE for these should be configured in ALT7 mode only. For other modes, PFE should be kept 0
        if (((PORT_A_ID == pin_config->PortID) && (PORT_PIN_5 == pin_config->PortPinId)) ||
            ((PORT_A_ID == pin_config->PortID) && (PORT_PIN_5 == pin_config->PortPinId))) // PTA5 or PTD3
        {
            if (PORT_PIN_MODE_ALT_7 == pin_config->PortPinMode)
            {
                if (1 == pin_config->PortPinPassifFilter)
                {
                    SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_PFE_BIT);
                }
                else
                {
                    CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_PFE_BIT);
                }
            }
            else
            {
                CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_PFE_BIT);
            }
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_PFE_BIT);
        }

        // PCR[DSE]
        /* DSE is Configurable only for PTA10 - PTB{4, 5, 6} - PTD{0, 1, 15, 16} - PTE{0, 1, 4} */
        if (((PORT_A_ID == pin_config->PortID) && (PORT_PIN_10 == pin_config->PortPinId)) ||
            ((PORT_B_ID == pin_config->PortID) && ((PORT_PIN_4 == pin_config->PortPinId) || (PORT_PIN_5 == pin_config->PortPinId) || (PORT_PIN_6 == pin_config->PortPinId))) ||
            ((PORT_D_ID == pin_config->PortID) && ((PORT_PIN_0 == pin_config->PortPinId) || (PORT_PIN_1 == pin_config->PortPinId) || (PORT_PIN_15 == pin_config->PortPinId) || (PORT_PIN_16 == pin_config->PortPinId))) ||
            ((PORT_E_ID == pin_config->PortID) && ((PORT_PIN_0 == pin_config->PortPinId) || (PORT_PIN_1 == pin_config->PortPinId) || (PORT_PIN_4 == pin_config->PortPinId))))
        {
            if (PORT_PIN_LOW_DRIVE_STRENGTH == pin_config->PortPinDriveStrength)
            {
                CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_DSE_BIT);
            }
            else if (PORT_PIN_HIGH_DRIVE_STRENGTH == pin_config->PortPinDriveStrength)
            {
                SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_DSE_BIT);
            }
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_DSE_BIT);
        }

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
            if(PORT_PIN_IN == pin_config->PortPinDirection){
                CLEAR_BIT(*(volatile uint32*)gpio_pddr_address, pin_config->PortPinId);
            }
            else if(PORT_PIN_OUT == pin_config->PortPinDirection){
                SET_BIT(*(volatile uint32*)gpio_pddr_address, pin_config->PortPinId);
            }
            else{
                /* No action required for invalid direction */
            }
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

        //PCR[IRQC]
        switch (pin_config->PortPinInterrupt)
        {
        case ISF_FLAG_DISABLED:
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_0);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_2);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_3);
            break;
        case ISF_FLAG_ENABLED_DMA_RISING_EDGE:
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_0);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_2);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_3);
            break;
        case ISF_FLAG_ENABLED_DMA_FALLING_EDGE:
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_0);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_2);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_3);
            break;
        case ISF_FLAG_ENABLED_DMA_EITHER_EDGE:
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_0);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_2);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_3);
            break;
        case ISF_FLAG_ENABLED_INTERRUPT_LOGIC_0:
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_0);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_2);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_3);
            break;
        case ISF_FLAG_ENABLED_INTERRUPT_RISING_EDGE:
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_0);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_2);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_3);
            break;
        case ISF_FLAG_ENABLED_INTERRUPT_FALLING_EDGE:
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_0);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_2);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_3);
            break;
        case ISF_FLAG_ENABLED_INTERRUPT_EITHER_EDGE:
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_0);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_1);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_2);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_3);
            break;
        case ISF_FLAG_ENABLED_INTERRUPT_LOGIC_1:
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_0);
            CLEAR_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_1);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_2);
            SET_BIT(*(volatile uint32 *)port_x_pcr_n_address, PCR_IRQC_BIT_3);
            break;
        default:
            break;
        }

        // RESET Pin Configuration PTA5
        // if ((PORT_A_ID == pin_config->PortID) && (PORT_PIN_5 == pin_config->PortPinId))
        // {
        //     if (PORT_PIN_MODE_ALT_7 != pin_config->PortPinMode)
        //     {
        //     }
        // }


    }
}