#ifndef justMOCK_IO_H
#define justMOCK_IO_H

#include "stm32f4xx_hal_gpio.h"

int readUserInput();
void turnOffLED(int LED);
void turnOnLED(int LED);

#endif // justMOCK_IO_H
