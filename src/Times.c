#include "Times.h"

uint32_t getCurrentTime()
{
	static uint32_t counter = 0 ;
	static uint32_t currentTime = 0 ;

	if (counter++ >= 100)
	{
		counter = 0 ;
		currentTime ++ ;
	}

	return currentTime ;
}


