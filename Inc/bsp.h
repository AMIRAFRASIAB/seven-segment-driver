
#ifndef __BSP_H_INCLUDED__
#define __BSP_H_INCLUDED__
#ifdef __cplusplus 
  extern "C"{
#endif  

#include "al.h"

/* Public APIs */
bool vio_init (const vio_t* const PVIO, bool lock/*?*/);

/* Exported Virtual I/Os */
extern const vio_t VIO_7SEG_A;
extern const vio_t VIO_7SEG_B;
extern const vio_t VIO_7SEG_C;
extern const vio_t VIO_7SEG_D;
extern const vio_t VIO_7SEG_E;
extern const vio_t VIO_7SEG_F;
extern const vio_t VIO_7SEG_G;
extern const vio_t VIO_7SEG_H;

extern const vio_t VIO_7SEG_C0;
extern const vio_t VIO_7SEG_C1;
extern const vio_t VIO_7SEG_C2;
extern const vio_t VIO_7SEG_C3;



#ifdef __cplusplus 
  };
#endif  

#endif //__BSP_H_INCLUDED__