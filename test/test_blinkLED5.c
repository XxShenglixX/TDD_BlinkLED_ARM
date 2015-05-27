#include "unity.h"
#include "blinkLED5.h"
#include "mock_justMock_IO.h"
#include "mock_stm32f4xx_hal_gpio.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_blinkLED5_noUserInput_should_not_blink(void)
{
	int Time_LED5 = _200ms ;
	
	State state_1 = START;
	
	turnOffLED_Expect(LED5); // initial START state , nextState = CHECK_BUTTON
	
	readUserInput_ExpectAndReturn(0); // CHECK_BUTTON  state, nextState = BUTTON_NOT_PRESSED
	 // go to BUTTON_NOT_PRESSED state , nextState = CHECK_BUTTON state 
	readUserInput_ExpectAndReturn(0); //go back to CHECK_BUTTON state , nextState = BUTTON_NOT_PRESSED
	// go to BUTTON_NOT_PRESSED state , nextState = CHECK_BUTTON state

	TEST_ASSERT_EQUAL(state_1,START);
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_NOT_PRESSED);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_NOT_PRESSED);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
}

void test_blinkLED5_UserInput_true_and_once_should_blink_5_times()
{
	int Time_LED5 = _200ms ;
	
	State state_1 = START;
	
	turnOffLED_Expect(LED5); // initial START state , nextState = CHECK_BUTTON
	
	readUserInput_ExpectAndReturn(1); // CHECK_BUTTON  state, nextState = BUTTON_PRESSED
	
	turnOffLED_Expect(LED5); // LED_OFF state , nextState = LED_ON
	
	turnOnLED_Expect(LED5); //LED_ON state, nextState = CHECK_BUTTON
	turnOffLED_Expect(LED5);
	
/* LED5 blinked 1 times */	
	
	readUserInput_ExpectAndReturn(0); // CHECK_BUTTON  state, nextState = BUTTON_NOT_PRESSED
	turnOffLED_Expect(LED5); // LED_OFF state , nextState = LED_ON
	
	turnOnLED_Expect(LED5); //LED_ON state, nextState = CHECK_BUTTON
	turnOffLED_Expect(LED5);
	
/* LED5 blinked 2 times */		

	readUserInput_ExpectAndReturn(0); // CHECK_BUTTON  state, nextState = BUTTON_NOT_PRESSED
	turnOffLED_Expect(LED5); // LED_OFF state , nextState = LED_ON
	
	turnOnLED_Expect(LED5); //LED_ON state, nextState = CHECK_BUTTON
	turnOffLED_Expect(LED5);
	
/* LED5 blinked 3 times */

	readUserInput_ExpectAndReturn(0); // CHECK_BUTTON  state, nextState = BUTTON_NOT_PRESSED
	turnOffLED_Expect(LED5); // LED_OFF state , nextState = LED_ON
	
	turnOnLED_Expect(LED5); //LED_ON state, nextState = CHECK_BUTTON
	turnOffLED_Expect(LED5);
	
/* LED5 blinked 4 times */	

	readUserInput_ExpectAndReturn(0); // CHECK_BUTTON  state, nextState = BUTTON_NOT_PRESSED
	turnOffLED_Expect(LED5); // LED_OFF state , nextState = LED_ON
	
	turnOnLED_Expect(LED5); //LED_ON state, nextState = CHECK_BUTTON
	turnOffLED_Expect(LED5);
	
/* LED5 blinked 5 times */					

	readUserInput_ExpectAndReturn(0); // CHECK_BUTTON  state, nextState = BUTTON_NOT_PRESSED
	

/*__________________________________________________________*/

	TEST_ASSERT_EQUAL(state_1,START);
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_PRESSED);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_OFF);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_ON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
	
/* LED5 blinked 1 times */
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_NOT_PRESSED);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_OFF);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_ON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
/* LED5 blinked 2 times */	

	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_NOT_PRESSED);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_OFF);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_ON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
/* LED5 blinked 3 times */

	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_NOT_PRESSED);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_OFF);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_ON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
/* LED5 blinked 4 times */

	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_NOT_PRESSED);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_OFF);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_ON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
/* LED5 blinked 5 times */

	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_NOT_PRESSED);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
}

void test_blinkLED5_UserInput_true_and_hold_should_blink_5_times()
{
	int Time_LED5 = _200ms ;
	
	State state_1 = START;
	
	turnOffLED_Expect(LED5); // initial START state , nextState = CHECK_BUTTON
	
	readUserInput_ExpectAndReturn(1); // CHECK_BUTTON  state, nextState = BUTTON_PRESSED
	
	turnOffLED_Expect(LED5); // LED_OFF state , nextState = LED_ON
	
	turnOnLED_Expect(LED5); //LED_ON state, nextState = CHECK_BUTTON
	turnOffLED_Expect(LED5);
	
/* LED5 blinked 1 times */	
	
	readUserInput_ExpectAndReturn(1); // CHECK_BUTTON  state, nextState = BUTTON_PRESSED
	turnOffLED_Expect(LED5); // LED_OFF state , nextState = LED_ON
	
	turnOnLED_Expect(LED5); //LED_ON state, nextState = CHECK_BUTTON
	turnOffLED_Expect(LED5);
	
/* LED5 blinked 2 times */		

	readUserInput_ExpectAndReturn(1); // CHECK_BUTTON  state, nextState = BUTTON_PRESSED
	turnOffLED_Expect(LED5); // LED_OFF state , nextState = LED_ON
	
	turnOnLED_Expect(LED5); //LED_ON state, nextState = CHECK_BUTTON
	turnOffLED_Expect(LED5);
	
/* LED5 blinked 3 times */

	readUserInput_ExpectAndReturn(1); // CHECK_BUTTON  state, nextState = BUTTON_PRESSED
	turnOffLED_Expect(LED5); // LED_OFF state , nextState = LED_ON
	
	turnOnLED_Expect(LED5); //LED_ON state, nextState = CHECK_BUTTON
	turnOffLED_Expect(LED5);
	
/* LED5 blinked 4 times */	

	readUserInput_ExpectAndReturn(1); // CHECK_BUTTON  state, nextState = BUTTON_PRESSED
	turnOffLED_Expect(LED5); // LED_OFF state , nextState = LED_ON
	
	turnOnLED_Expect(LED5); //LED_ON state, nextState = CHECK_BUTTON
	turnOffLED_Expect(LED5);
	
/* LED5 blinked 5 times */					

	readUserInput_ExpectAndReturn(1); // CHECK_BUTTON  state, nextState = BUTTON_PRESSED
	turnOffLED_Expect(LED5); // return to START state , nextState = CHECK_BUTTON
	readUserInput_ExpectAndReturn(1); // CHECK_BUTTON  state, nextState = BUTTON_PRESSED
	turnOffLED_Expect(LED5); // return to START state , nextState = CHECK_BUTTON
/*__________________________________________________________*/

	TEST_ASSERT_EQUAL(state_1,START);
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_PRESSED);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_OFF);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_ON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
	
/* LED5 blinked 1 times */
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_PRESSED);
		
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_OFF);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_ON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
/* LED5 blinked 2 times */	

	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_PRESSED);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_OFF);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_ON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
/* LED5 blinked 3 times */

	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_PRESSED);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_OFF);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_ON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
/* LED5 blinked 4 times */

	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_PRESSED);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_OFF);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,LED_ON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
/* LED5 blinked 5 times */

	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_PRESSED);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,START);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,BUTTON_PRESSED);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,START);
	
	SM_LED(&state_1,LED5,&Time_LED5);
	TEST_ASSERT_EQUAL(state_1,CHECK_BUTTON);
}
