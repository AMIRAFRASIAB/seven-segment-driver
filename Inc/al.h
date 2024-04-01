
#ifndef __AL_H_INCLUDED__
#define __AL_H_INCLUDED__

#include "stm32f4xx.h"
#include "core_cm4.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct {
  GPIO_TypeDef*  port;
  uint32_t       pin;
  uint32_t       mode;
  uint32_t       af;
  uint32_t       speed;
  uint32_t       pull;
  uint32_t       outType;
} vio_t;

#define  NO            LL_GPIO_AF_0,
#define  PIN(pin)      LL_GPIO_PIN_##pin,
#define  PORT(port)    GPIO##port,
#define  AF(af)        LL_GPIO_AF_##af,
#define  MODE(mode)    LL_GPIO_MODE_##mode,
#define  SPEED(speed)  LL_GPIO_SPEED_FREQ_##speed,
#define  TYPE(type)    LL_GPIO_OUTPUT_##type,
#define  PULL(pull)    LL_GPIO_PULL_##pull,
#define  LL_VIO(vio)   vio.port, vio.pin

#endif //__AL_H_INCLUDED__






