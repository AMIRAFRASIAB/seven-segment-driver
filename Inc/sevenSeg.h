
#ifndef __7SEG_H_INCLUDED__
#define __7SEG_H_INCLUDED__

#ifdef __cplusplus
  extern "C"{
#endif


#include <stdint.h>
#include <stdbool.h>
#include "al.h"
#include "bsp.h"

typedef enum {
  pinActiveType_High    = 0x00,
  pinActiveType_Low     = 0x01,
} pinActiveType_e;


typedef struct {
  const vio_t**     SIGNALS;
  const vio_t**     COMMONS;
  char*             ram;
  pinActiveType_e   signalType;
  pinActiveType_e   commonType;
  const uint8_t     NUM_OF_DIGITS;
  const uint8_t     NUM_OF_LEDS;
  uint8_t           refreshCounter;
  uint8_t           ramSize;
  bool              initFlag;
} sevenSeg_t;




#ifdef __cplusplus
  };
#endif
#endif //__7SEG_H_INCLUDED__