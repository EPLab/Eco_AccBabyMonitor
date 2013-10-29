#include "debug.h"
#include "datatypes.h"
#include "timers.h"
#include "system.h"

/** \brief Timer pool used to keep information about available timers
 *	
 *  This timer pool is extensively used by most of the modules of the 
 * 	OpenTCP project. All timers that are used are allocated from this
 * 	pool. Maximum number of timers that can be used at any given time
 *	is defined by the #NUMTIMERS define.
 */
struct
{
	UINT32 value;
	UINT8 free;
} timer_pool[NUMTIMERS];

/** \brief Initialize timer pool
 *	\ingroup core_initializer
 * 	\author 
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 18.07.2001
 *	\warning
 *		\li This function <b>must</b> be invoked at startup before
 *		any other timer function is used.
 *
 *	This function resets all timer counter to zero and initializes all 
 *	timers to available (free) state.
 *
 */
void timer_pool_init (void)
{
	UINT8 i;

	for( i=0; i < NUMTIMERS; i++) {
		timer_pool[i].value = 0;
		timer_pool[i].free = TRUE;
		
	}
		

}


/** \brief Obtain a timer from timer pool
 * 	\author 
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 18.07.2001
 *	\return Handle to a free timer
 *	\warning
 *		\li Timers are considered to be critical resources, so if there is 
 *		no available timer and get_timer is invoked, system will reset.
 *
 *	Invoke this function to obtain a free timer (it's handle that is) from
 *	the timer pool.
 */
UINT8 get_timer (void)
{
	
	UINT8 i;
	UINT8 first_match;
	
	
	for( i=0; i < NUMTIMERS; i++) {
		if( timer_pool[i].free == TRUE ) {
			/* We found a free timer! */
			/* Mark is reserved		  */
			
			timer_pool[i].free = FALSE;
			first_match = i;
			return first_match;		/* Return Handle	*/
		}
	
	}
	
	/* Error Check	*/
	
	TMR_DEBUGOUT("No Timers, Resetting..\n\r");
	RESET_SYSTEM();
	

}


/** \brief Release timer back to free timer pool
 * 	\author 
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 18.07.2001
 *	\param nbr handle to timer beeing released
 *
 *	This function releases the timer who's handle is supplied as parameter.
 *	Use this when timer is not needed any more and other applications might
 *	use it.
 */
void free_timer (UINT8 nbr)
{
	/* Make a simple check */
	
	if( nbr > (NUMTIMERS-1) ) 
		return; 

	timer_pool[nbr].free = TRUE;

}
				 

/** \brief Initialize timer to a given time-out value
 * 	\author 
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 18.07.2001
 *	\param nbr handle of timer who's value we're setting
 *	\param tout time-out value to set for this timer
 *
 *	Invoke this function to set timeout value for a timer with
 *	a given handle.
 *
 *	#TIMERTIC defines how quickly the timers' values are decremented so is
 *	it to initialize timers to correct timeouts.
 */
void init_timer ( UINT8 nbr, UINT32 tout )
{
	/* Make a simple check */
	
	UINT32 val;
	
	if( nbr > (NUMTIMERS-1) ) 
		return; 

	if( timer_pool[nbr].free == TRUE ) 
		return;
		
	/* All OK				*/
	
	val = tout;
	
	OS_EnterCritical();
	
	/* Normalize seconds to timer tics	*/
	
	timer_pool[nbr].value = val;

	OS_ExitCritical();

} 

/** \brief Return the value of a given timer
 * 	\author 
 *		\li Jari Lahti (jari.lahti@violasystems.com)
 *	\date 18.07.2001
 *	\param nbr timer handle who's value is to be returned
 *	\return timer value
 *	\warning 
 *		\li Interrupts are not disabled when fetching the value, therefore
 *		returned value possibly has an error component +/- #TIMERTIC.
 *
 *	Function simply returns timer value of a given timer. No checks are
 *	made in order to make the function as fast as possible.
 */
UINT32 check_timer (UINT8 nbr)
{
	return timer_pool[nbr].value;
}


/** \brief Decrement all timers' values by one
 * 	\author 
 *		\li Vladan Jovanovic (vladan.jovanovic@violasystems.com)
 *	\date 18.07.2001
 *
 *	Invoke this function from timer interrupt to decrement timer counter values
 */
void decrement_timers (void)
{
	UINT8 i;

	/* Go Through Timers */
	
	for( i=0; i<NUMTIMERS; i++ ) {
		if( (timer_pool[i].free == FALSE) && (timer_pool[i].value != 0))
			timer_pool[i].value --;
	}
}
