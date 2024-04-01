
#include "sevenSeg.h"
#include "stm32f4xx_ll_gpio.h"

static const vio_t* _7SEG_SIGNAL_PINS[] = {
  &VIO_7SEG_A,
  &VIO_7SEG_B,
  &VIO_7SEG_C,
  &VIO_7SEG_D,
  &VIO_7SEG_E,
  &VIO_7SEG_F,
  &VIO_7SEG_G,
  &VIO_7SEG_H, // For Dot
};
static const vio_t* _7SEG_COMMON_PINS[] = {
  &VIO_7SEG_C0,
  &VIO_7SEG_C1,
  &VIO_7SEG_C2,
  &VIO_7SEG_C3,
};
#define DIGIT_SIZE (sizeof(_7SEG_COMMON_PINS) / sizeof(*_7SEG_COMMON_PINS))

/*MY_SRAM_LOCATION*/static char __ram[DIGIT_SIZE * 2 + 1];

sevenSeg_t sevenSeg = {
  .ram              = __ram,
  .ramSize          = sizeof(__ram),
  .SIGNALS          = _7SEG_SIGNAL_PINS,
  .COMMONS          = _7SEG_COMMON_PINS,
  .NUM_OF_DIGITS    = DIGIT_SIZE,
  .NUM_OF_LEDS      = sizeof(_7SEG_SIGNAL_PINS) / sizeof(*_7SEG_SIGNAL_PINS),
  .signalType       = pinActiveType_High,
  .commonType       = pinActiveType_Low,
  .initFlag         = false,
  .refreshCounter   = 0,
};

/* Driver Implementation */
void sevenSegwritePin (const vio_t* VIO, bool status) {
  if (status == true) {
    LL_GPIO_SetOutputPin(LL_VIO((*VIO)));
  }
  else {
    LL_GPIO_ResetOutputPin(LL_VIO((*VIO)));
  }
}
