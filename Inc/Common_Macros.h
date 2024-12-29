#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/* Macro to set a certain bit in a given regiter */
#define SET_BIT(REG, BIT) (REG |= (1 << BIT))

/* Macro to clear a certain bit in a given register */
#define CLEAR_BIT(REG, BIT) (REG &= (~(1 << BIT)))

#endif /* COMMON_MACROS_H_ */
