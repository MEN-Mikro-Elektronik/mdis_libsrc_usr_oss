/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!
 *        \file  mdelay.c
 *
 *      \author  klaus.popp@men.de
 *        $Date: 2004/05/28 16:03:53 $
 *    $Revision: 1.4 $
 *
 * 	   \project  MDISforLinux USR_OSS lib
 *
 *  	 \brief  Mikrodelay routines
 *
 *    \switches  none
 */
/*
 *---------------------------------------------------------------------------
 * Copyright (c) 2000-2019, MEN Mikro Elektronik GmbH
 ******************************************************************************/
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "uos_int.h"
#include <time.h>

#define TRYS 3
#define LOOPS 4000
/*--------------------------------------+
|   GLOBALS                             |
+--------------------------------------*/
static u_int32 G_mDelayLoops;

/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/
static void BusyLoop( u_int32 loopCount );

/**********************************************************************/
/** Calibrates the loop counter for UOS_MikroDelay
 *
 * \copydoc usr_oss_specification.c::UOS_MikroDelayInit()
 *
 * \linux Since we don't have a timer that we can use, we try to measure
 * a loop counter three times. The minimum time is used and then doubled
 * to get at least the required delay.
 *
 * \sa UOS_MikroDelay
 */
int32 UOS_MikroDelayInit()
{
	u_int32 loopCount, minLoops = 0xffffffff;
	int i;
	u_int32 msTick, msTick2;

	for(i=0; i<TRYS; i++){

		/*--- wait for tick to change ---*/
		msTick2 = UOS_MsecTimerGet();
		while( (msTick=UOS_MsecTimerGet()) == msTick2 )
			;

		loopCount = 0;

		/*--- perform busy loop for 200ms ---*/
		while( UOS_MsecTimerGet() < msTick+200 ){
			BusyLoop( LOOPS );
			loopCount++;
		}
		DBGCMD(printf("UOS_MikroDelayInit: try %d loops=%d\n", i,
					  (unsigned int)loopCount));
		if( loopCount < minLoops )
			minLoops = loopCount;
	}

	G_mDelayLoops = minLoops * 2;

	DBGCMD(printf("UOS_MikroDelayInit: G_mDelayLoops=%d\n", (unsigned int)G_mDelayLoops ));

	return 0;
}

/**********************************************************************/
/** Busy sleep for specified time
 *
 * \copydoc usr_oss_specification.c::UOS_MikroDelay()
 * \sa UOS_MikroDelayInit
 */
int32 UOS_MikroDelay(u_int32 usec)
{
	u_int32 i, loops;

	/*--- check if UOS_MikroDelayInit has been called before ---*/
	if( G_mDelayLoops == 0 ){
		errno = ERR_UOS_NO_MIKRODELAY;
		return ERR_UOS_NO_MIKRODELAY;
	}

	/*--- check for maximum time ---*/
	if( usec > UOS_MAX_USEC){
		errno = ERR_UOS_ILL_PARAM;
		return ERR_UOS_ILL_PARAM;
	}
	/*--- perform busy loops ---*/
	loops = usec * G_mDelayLoops / 200000;

	for(i=0; i<loops; i++ )
		BusyLoop( LOOPS );

	return 0;
}

static void BusyLoop( u_int32 loopCount )
{
	volatile int i;

	for(i=loopCount; i--; )
		;
}
