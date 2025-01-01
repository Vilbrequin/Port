#ifndef PORT_REGS_H_
#define PORT_REGS_H_
// Port instances base addresses
#define PORT_A_BASE_ADDRESS             0x40049000         
#define PORT_B_BASE_ADDRESS             0x4004A000
#define PORT_C_BASE_ADDRESS             0x4004B000
#define PORT_D_BASE_ADDRESS             0x4004C000
#define PORT_E_BASE_ADDRESS             0x4004D000

#define PCR_PS_BIT                      0
#define PCR_PE_BIT                      1
#define PCR_PFE_BIT                     4
#define PCR_DSE_BIT                     6
#define PCR_MUX_BIT_0                   8
#define PCR_MUX_BIT_1                   9
#define PCR_MUX_BIT_2                   10
#define PCR_LK_BIT                      15
#define PCR_IRQC_BIT_0                  16
#define PCR_IRQC_BIT_1                  17
#define PCR_IRQC_BIT_2                  18
#define PCR_IRQC_BIT_3                  19
#define PCR_ISF_BIT                     24



// Global Pin Control Low Register
#define GPCLR_OFFSET                    0x80
#define PORT_A_GPCLR                    (PORT_A_BASE_ADDRESS + GPCLR_OFFSET)
#define PORT_B_GPCLR                    (PORT_B_BASE_ADDRESS + GPCLR_OFFSET)
#define PORT_C_GPCLR                    (PORT_C_BASE_ADDRESS + GPCLR_OFFSET)
#define PORT_D_GPCLR                    (PORT_D_BASE_ADDRESS + GPCLR_OFFSET)
#define PORT_E_GPCLR                    (PORT_E_BASE_ADDRESS + GPCLR_OFFSET)


// Global Pin Control High Register
#define GPCHR_OFFSET                    0x84
#define PORT_A_GPCHR                    (PORT_A_BASE_ADDRESS + GPCHR_OFFSET)
#define PORT_B_GPCHR                    (PORT_B_BASE_ADDRESS + GPCHR_OFFSET)
#define PORT_C_GPCHR                    (PORT_C_BASE_ADDRESS + GPCHR_OFFSET)
#define PORT_D_GPCHR                    (PORT_D_BASE_ADDRESS + GPCHR_OFFSET)
#define PORT_E_GPCHR                    (PORT_E_BASE_ADDRESS + GPCHR_OFFSET)

// Global Interrupt Control Low Register
#define GICLR_OFFSET                    0x88
#define PORT_A_GICLR                    (PORT_A_BASE_ADDRESS + GICLR_OFFSET)
#define PORT_B_GICLR                    (PORT_B_BASE_ADDRESS + GICLR_OFFSET)
#define PORT_C_GICLR                    (PORT_C_BASE_ADDRESS + GICLR_OFFSET)
#define PORT_D_GICLR                    (PORT_D_BASE_ADDRESS + GICLR_OFFSET)
#define PORT_E_GICLR                    (PORT_E_BASE_ADDRESS + GICLR_OFFSET)

// Global Interrupt Control High Register
#define GICHR_OFFSET                    0x8C
#define PORT_A_GICHR                    (PORT_A_BASE_ADDRESS + GICHR_OFFSET)
#define PORT_B_GICHR                    (PORT_B_BASE_ADDRESS + GICHR_OFFSET)
#define PORT_C_GICHR                    (PORT_C_BASE_ADDRESS + GICHR_OFFSET)
#define PORT_D_GICHR                    (PORT_D_BASE_ADDRESS + GICHR_OFFSET)
#define PORT_E_GICHR                    (PORT_E_BASE_ADDRESS + GICHR_OFFSET)

// Interrupt Status Flag Register
#define ISFR_OFFSET                     0xA0
#define PORT_A_ISFR                     (PORT_A_BASE_ADDRESS + GICLR_OFFSET)
#define PORT_B_ISFR                     (PORT_B_BASE_ADDRESS + GICLR_OFFSET)
#define PORT_C_ISFR                     (PORT_C_BASE_ADDRESS + GICLR_OFFSET)
#define PORT_D_ISFR                     (PORT_D_BASE_ADDRESS + GICLR_OFFSET)
#define PORT_E_ISFR                     (PORT_E_BASE_ADDRESS + GICLR_OFFSET)

// Digital Filter Enable Register
#define DFER_OFFSET                     0xC0
#define PORT_A_DFER                     (PORT_A_BASE_ADDRESS + DFER_OFFSET)
#define PORT_B_DFER                     (PORT_B_BASE_ADDRESS + DFER_OFFSET)
#define PORT_C_DFER                     (PORT_C_BASE_ADDRESS + DFER_OFFSET)
#define PORT_D_DFER                     (PORT_D_BASE_ADDRESS + DFER_OFFSET)
#define PORT_E_DFER                     (PORT_E_BASE_ADDRESS + DFER_OFFSET)

// Digital Filter Clock Register
#define DFCR_OFFSET                     0xC4
#define PORT_A_DFCR                     (PORT_A_BASE_ADDRESS + DFCR_OFFSET)
#define PORT_B_DFCR                     (PORT_B_BASE_ADDRESS + DFCR_OFFSET)
#define PORT_C_DFCR                     (PORT_C_BASE_ADDRESS + DFCR_OFFSET)
#define PORT_D_DFCR                     (PORT_D_BASE_ADDRESS + DFCR_OFFSET)
#define PORT_E_DFCR                     (PORT_E_BASE_ADDRESS + DFCR_OFFSET)

// Digital Filter Width Register
#define DFWR_OFFSET                     0xC8
#define PORT_A_DFWR                     (PORT_A_BASE_ADDRESS + DFWR_OFFSET)
#define PORT_B_DFWR                     (PORT_B_BASE_ADDRESS + DFWR_OFFSET)
#define PORT_C_DFWR                     (PORT_C_BASE_ADDRESS + DFWR_OFFSET)
#define PORT_D_DFWR                     (PORT_D_BASE_ADDRESS + DFWR_OFFSET)
#define PORT_E_DFWR                     (PORT_E_BASE_ADDRESS + DFWR_OFFSET)

// GPIO instances base address
#define GPIO_A_BASE_ADDRESS             0x400FF000
#define GPIO_B_BASE_ADDRESS             0x400FF040
#define GPIO_C_BASE_ADDRESS             0x400FF080
#define GPIO_D_BASE_ADDRESS             0x400FF0C0
#define GPIO_E_BASE_ADDRESS             0x400FF100

// Port Data Output Register (PDOR)
#define PDOR_OFFSET                     0x00

#define GPIO_A_PDOR                     (GPIO_A_BASE_ADDRESS + PDOR_OFFSET)
#define GPIO_B_PDOR                     (GPIO_B_BASE_ADDRESS + PDOR_OFFSET)
#define GPIO_C_PDOR                     (GPIO_C_BASE_ADDRESS + PDOR_OFFSET)
#define GPIO_D_PDOR                     (GPIO_D_BASE_ADDRESS + PDOR_OFFSET)
#define GPIO_E_PDOR                     (GPIO_E_BASE_ADDRESS + PDOR_OFFSET)

// Port Data Direction Register (PDDR)
#define PDDR_OFFSET                     0x14

#define GPIO_A_PDDR                     (GPIO_A_BASE_ADDRESS + PDDR_OFFSET)
#define GPIO_B_PDDR                     (GPIO_B_BASE_ADDRESS + PDDR_OFFSET)
#define GPIO_C_PDDR                     (GPIO_C_BASE_ADDRESS + PDDR_OFFSET)
#define GPIO_D_PDDR                     (GPIO_D_BASE_ADDRESS + PDDR_OFFSET)
#define GPIO_E_PDDR                     (GPIO_E_BASE_ADDRESS + PDDR_OFFSET)





#define PCC_BASE_ADDRESS                0x40065000
#define PCC_CGC_BIT                     30U /* Clock Gate Control: enables the clock for the peripheral */

#define PCC_PORT_A_OFFSET               0x124
#define PCC_PORT_A                      (PCC_BASE_ADDRESS + PCC_PORT_A_OFFSET)

#define PCC_PORT_B_OFFSET               0x128
#define PCC_PORT_B                      (PCC_BASE_ADDRESS + PCC_PORT_B_OFFSET)

#define PCC_PORT_C_OFFSET               0x12C
#define PCC_PORT_C                      (PCC_BASE_ADDRESS + PCC_PORT_C_OFFSET)

#define PCC_PORT_D_OFFSET               0x130
#define PCC_PORT_D                      (PCC_BASE_ADDRESS + PCC_PORT_D_OFFSET)

#define PCC_PORT_E_OFFSET               0x134
#define PCC_PORT_E                      (PCC_BASE_ADDRESS + PCC_PORT_E_OFFSET)

#endif /* PORT_REGS_H_*/