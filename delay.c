/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!  
 *        \file  delay.c
 *
 *      \author  klaus.popp@men.de
 *        $Date: 2009/09/25 19:19:56 $
 *    $Revision: 1.7 $
 * 
 * 	   \project  MDISforLinux USR_OSS lib
 *
 *  	 \brief  Delay function
 *
 *    \switches  none
 */
/*
 *---------------------------------------------------------------------------
 * (c) Copyright 2000-2003 by MEN mikro elektronik GmbH, Nuremberg, Germany 
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

/**********************************************************************/
/** Let a process sleep for a specified time
 *
 * \copydoc usr_oss_specification.c::UOS_Delay()
 *
 * \sa UOS_MikroDelay
 */
int32 UOS_Delay(u_int32 msec)
{
	struct timespec request, remain;
	u_int32 current, start, expires;
	int32 left;

	start = current = UOS_MsecTimerGet();
	expires = current + msec;

	while( (left = expires - current) > 0 ) { 

		/*printf("UOS_Delay: msec=%d\n", msec );*/
		request.tv_sec = left / 1000;
		request.tv_nsec = (left % 1000) * 1000000;

		nanosleep( &request, &remain );
		
		current = UOS_MsecTimerGet();
	} 

	return current-start;
}


