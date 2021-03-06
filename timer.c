/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!  
 *        \file  timer.c
 *
 *      \author  klaus.popp@men.de
 * 
 * 	   \project  MDISforLinux USR_OSS lib
 *
 *  	 \brief  Timer routines
 *
 *    \switches  none
 */
/*
 *---------------------------------------------------------------------------
 * Copyright 2000-2019, MEN Mikro Elektronik GmbH
 ******************************************************************************/
/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "uos_int.h"
#include <sys/time.h>

/**********************************************************************/
/** Read the current timer value in mseconds
 *
 * \copydoc usr_oss_specification.c::UOS_MsecTimerGet()
 * kp note: Wrap around safe. Verified with timer_test.c
 * \sa UOS_MsecTimerResolution
 */
u_int32 UOS_MsecTimerGet(void)
{
	struct timeval tv;

	if( gettimeofday( &tv, NULL ) < 0 )
		return 0;
	
	return (tv.tv_sec * 1000) + (tv.tv_usec/1000);
}

/**********************************************************************/
/** Get timer resolution of UOS_MsecTimerGet()
 *
 * \copydoc usr_oss_specification.c::UOS_MsecTimerResolution()
 * \sa UOS_MsecTimerGet
 */
u_int32 UOS_MsecTimerResolution(void)
{
	return(1);					/* resolution of ftime (I hope) */
}


