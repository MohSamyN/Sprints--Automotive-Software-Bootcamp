#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Boolean Standard Values */
#define FALSE                               0u
#define TRUE								1u

/* Unsigned Integer Standard Types */
typedef unsigned char						uint8_t;
typedef unsigned short						uint16_t;
typedef unsigned long						uint32_t;
typedef unsigned long long					uint64_t;

/* Signed Integer Standard Types */
typedef signed char							sint8;
typedef signed short						sint16;
typedef signed long							sint32;
typedef signed long long					sint64;

/* Float Standard Types */
typedef float								float32;
typedef double								float64;

typedef enum {E_ERROR, E_OK}				enuErrorStatus_t;
typedef enum {LOW, HIGH}                    enuDigitalStates_t;

#endif /* STD_TYPES_H_ */