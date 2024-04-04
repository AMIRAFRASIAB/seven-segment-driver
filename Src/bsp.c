
#include "bsp.h"
#include "al.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_bus.h"

/*             NAME       = { PORT      PIN       MODE              AF      SPEED           PULL        OUTTYPE }; */
/*-----------------------------------------------------------------------------------------------------------------*/
const vio_t VIO_7SEG_A    = { PORT(A)   PIN(0)    MODE(OUTPUT)      AF(7)   SPEED(MEDIUM)   PULL(NO)    TYPE(PUSHPULL)  };
const vio_t VIO_7SEG_B    = { PORT(A)   PIN(1)    MODE(OUTPUT)      AF(7)   SPEED(MEDIUM)   PULL(NO)    TYPE(PUSHPULL)  };
const vio_t VIO_7SEG_C    = { PORT(A)   PIN(2)    MODE(OUTPUT)      AF(7)   SPEED(MEDIUM)   PULL(NO)    TYPE(PUSHPULL)  };
const vio_t VIO_7SEG_D    = { PORT(A)   PIN(3)    MODE(OUTPUT)      AF(7)   SPEED(MEDIUM)   PULL(NO)    TYPE(PUSHPULL)  };
const vio_t VIO_7SEG_E    = { PORT(A)   PIN(4)    MODE(OUTPUT)      AF(7)   SPEED(MEDIUM)   PULL(NO)    TYPE(PUSHPULL)  };
const vio_t VIO_7SEG_F    = { PORT(A)   PIN(5)    MODE(OUTPUT)      AF(7)   SPEED(MEDIUM)   PULL(NO)    TYPE(PUSHPULL)  };
const vio_t VIO_7SEG_G    = { PORT(A)   PIN(6)    MODE(OUTPUT)      AF(7)   SPEED(MEDIUM)   PULL(NO)    TYPE(PUSHPULL)  };
const vio_t VIO_7SEG_H    = { PORT(A)   PIN(7)    MODE(OUTPUT)      AF(7)   SPEED(MEDIUM)   PULL(NO)    TYPE(PUSHPULL)  };

const vio_t VIO_7SEG_C0   = { PORT(B)   PIN(0)    MODE(OUTPUT)      AF(7)   SPEED(MEDIUM)   PULL(NO)    TYPE(PUSHPULL)  };
const vio_t VIO_7SEG_C1   = { PORT(B)   PIN(1)    MODE(OUTPUT)      AF(7)   SPEED(MEDIUM)   PULL(NO)    TYPE(PUSHPULL)  };
const vio_t VIO_7SEG_C2   = { PORT(B)   PIN(2)    MODE(OUTPUT)      AF(7)   SPEED(MEDIUM)   PULL(NO)    TYPE(PUSHPULL)  };
const vio_t VIO_7SEG_C3   = { PORT(B)   PIN(10)   MODE(OUTPUT)      AF(7)   SPEED(MEDIUM)   PULL(NO)    TYPE(PUSHPULL)  };


//------------------------------------------------------------------------------------------------------------------------
/* Static APIs */
static void __vio_clockEnable (const vio_t* const PVIO) {
  switch ((uintptr_t)(PVIO->port)) {
    case (uintptr_t)GPIOA:
      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
      break;
    case (uintptr_t)GPIOB:
      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
      break;
    case (uintptr_t)GPIOC:
      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
      break;
    case (uintptr_t)GPIOD:
      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
      break;
    case (uintptr_t)GPIOE:
      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);
      break;
//    case (uintptr_t)GPIO:
//      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);
//      break;
//    case (uintptr_t)GPIOG:
//      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOG);
//      break;
    case (uintptr_t)GPIOH:
      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOH);
      break;
//    case (uintptr_t)GPIOI:
//      LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOI);
//      break;
  };
  __DSB();
}
//------------------------------------------------------------------------------------------------------
/* Public APIs */
bool vio_init (const vio_t* const PVIO, bool lock/*?*/) {
  __vio_clockEnable(PVIO);
  bool status = true;
  /* Mode */
  LL_GPIO_SetPinMode(LL_VIO((*PVIO)), PVIO->mode);
  __DSB();
  status = status && LL_GPIO_GetPinMode(LL_VIO((*PVIO))) == PVIO->mode;
  /* AF */
  if (PVIO->pin < LL_GPIO_PIN_8) {
    LL_GPIO_SetAFPin_0_7(LL_VIO((*PVIO)), PVIO->af);
    __DSB();
    status = status && LL_GPIO_GetAFPin_0_7(LL_VIO((*PVIO))) == PVIO->af;
  }
  else {
    LL_GPIO_SetAFPin_8_15(LL_VIO((*PVIO)), PVIO->af);
    __DSB();
    status = status && LL_GPIO_GetAFPin_8_15(LL_VIO((*PVIO))) == PVIO->af;
  }
  /* Pull */
  LL_GPIO_SetPinPull(LL_VIO((*PVIO)), PVIO->pull);
  __DSB();
  status = status && LL_GPIO_GetPinPull(LL_VIO((*PVIO))) == PVIO->pull;
  /* Speed */
  LL_GPIO_SetPinSpeed(LL_VIO((*PVIO)), PVIO->speed);
  __DSB();
  status = status && LL_GPIO_GetPinSpeed(LL_VIO((*PVIO))) == PVIO->speed;
  /* Output Type */
  LL_GPIO_SetPinOutputType(LL_VIO((*PVIO)), PVIO->outType);
  __DSB();
  status = status && LL_GPIO_GetPinOutputType(LL_VIO((*PVIO))) == PVIO->outType;
  /* Lock */
  if (lock == true) {
    LL_GPIO_LockPin(LL_VIO((*PVIO)));
    __DSB();
    status = status && LL_GPIO_IsPinLocked(LL_VIO((*PVIO)));
  }
  return status;
}
//------------------------------------------------------------------------------------------------------
