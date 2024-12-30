#ifndef COMPILER_H_
#define COMPILER_H_

/* The memory class AUTOMATIC shall be provided as empty definition, used for the declaration of local pointers. */
#define AUTOMATIC

/* The memory class TYPEDEF shall be provided as empty definition. This memory class shall be used within type definitions, where no memory qualifier can be specified. */
#define TYPEDEF

/* The compiler abstraction shall provide the NULL_PTR define with a void pointer to zero definition. */
#define NULL_PTR            ((void *)0)

/* The compiler abstraction shall provide the INLINE define for abstraction of the keyword inline. */
#define INLINE              inline

/* The compiler abstraction shall provide the LOCAL_INLINE define for abstraction of the keyword inline in functions with “static” scope. */
#define LOCAL_INLINE        static inline
#endif /* COMPILER_H_ */