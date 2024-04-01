
#include "sevenSeg.h"
#include "string.h"
#include "ctype.h"

/* Private APIs */
//----------------------------------------------------------------------------------------
static uint8_t __sevenSegDecoder (const char CHAR) {
  uint8_t ans = 0;
  switch (CHAR) {
    case '0':
      ans = 0x3F;
      break;
    case '1':
      ans = 0x06;
      break;
    case '2':
      ans = 0x5B;
      break;
    case '3':
      ans = 0x4F;
      break;
    case '4':
      ans = 0x66;
      break;
    case '5':
      ans = 0x6D;
      break;
    case '6':
      ans = 0x7C;
      break;
    case '7':
      ans = 0x0F;
      break;
    case '8':
      ans = 0x7F;
      break;
    case '9':
      ans = 0x67;
      break;
    case ' ':
      ans = 0x00;
      break;
  };
  return ans;
}
//----------------------------------------------------------------------------------------

/* Public APIs */
//----------------------------------------------------------------------------------------
bool sevenSegment_init (sevenSeg_t* p7seg) {
  if (
      p7seg->ram == NULL || (p7seg->ramSize * 2) < p7seg->NUM_OF_DIGITS ||
      p7seg->COMMONS == NULL ||
      p7seg->SIGNALS == NULL || 
      (p7seg->commonType != pinActiveType_High && p7seg->commonType != pinActiveType_Low) ||
      (p7seg->signalType != pinActiveType_High && p7seg->signalType != pinActiveType_Low) ||
      p7seg->NUM_OF_DIGITS == 0 || p7seg->NUM_OF_LEDS < 7 || p7seg->NUM_OF_LEDS > 8) {
    return false;
  }
  bool status = true;
  for (uint8_t i = 0; i < p7seg->NUM_OF_LEDS; i++) {
    status = status && vio_init(p7seg->SIGNALS[i], true);
  }
  for (uint8_t i = 0; i < p7seg->NUM_OF_DIGITS; i++) {
    status = status && vio_init(p7seg->COMMONS[i], true);
  }
  memset(p7seg->ram, 0x00, p7seg->ramSize);
  p7seg->refreshCounter = 0;
  p7seg->initFlag = status;
  return status;
}
//----------------------------------------------------------------------------------------
void sevenSegment_write (sevenSeg_t* p7seg, const char* STR) {
  if (strlen(STR) >= p7seg->ramSize || p7seg->initFlag == false) {
    return;
  }
  for (uint8_t i = 0; i < p7seg->ramSize; i++) {
    p7seg->ram[i] = toupper(STR[i]);
  }
  p7seg->ram[p7seg->ramSize - 1] = '\0';
  p7seg->refreshCounter = 0;
}
//----------------------------------------------------------------------------------------
void sevenSegment_refresh (sevenSeg_t* p7seg) {
  if (p7seg->initFlag == false) {
    return;
  }
  p7seg->refreshCounter = (p7seg->refreshCounter >= p7seg->NUM_OF_DIGITS - 1)? 0 : p7seg->refreshCounter + 1;
  //Disable All Common Outputs
  //Write Data
  //Enable Single Output pin
}


