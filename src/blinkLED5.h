#ifndef blinkLED5_H
#define blinkLED5_H

#define STM32F429xx
#define STM32F429ZI

#define _120ms 120
#define _100ms 100
#define _200ms 200
#define _1s 1000


enum {
				LED3 = 0,
				LED4,
				LED5,
				LED6
};

typedef enum {
				START,
				LED_OFF,
				LED_ON,
				CHECK_BUTTON,
				BUTTON_NOT_PRESSED,
				BUTTON_PRESSED
}State;

int readUserInput();
void turnOffLED(int LED);
void turnOnLED(int LED);
void SM_LED(State *state,int LED,int *Time);


#endif // blinkLED5_H
