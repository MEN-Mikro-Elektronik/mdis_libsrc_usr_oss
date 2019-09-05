/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!  
 *        \file  key.c
 *
 *      \author  klaus.popp@men.de
 * 
 * 	   \project  MDISforLinux USR_OSS lib
 *
 *  	 \brief  Check for key pressed
 *
 *    \switches  none
 */
/*
 *---------------------------------------------------------------------------
 * Copyright (c) 2000-2019, MEN Mikro Elektronik GmbH
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
#include <unistd.h>
#include <sys/ioctl.h>
#ifndef NCCS
# include <asm/termbits.h>
#endif

struct termios G_oldTerm;

static void SetRawMode()
{
	struct termios new;

	ioctl( 0, TCGETS, &G_oldTerm );
	new = G_oldTerm;
	new.c_lflag &= ~ICANON;
	ioctl( 0, TCSETS, &new );
}

static void RestoreMode()
{
	ioctl( 0, TCSETS, &G_oldTerm );
}

/**********************************************************************/
/** Check if any key pressed on console
 * 
 * \copydoc usr_oss_specification.c::UOS_KeyPressed()
 *
 * \linux temporarily switches console to raw mode
 *
 * \sa UOS_KeyWait
 */
int32 UOS_KeyPressed( void )
{
	char c;
	int nread=0;

	SetRawMode();
	ioctl( 0, FIONREAD, &nread );
	if( nread > 0 ){
	  if (read(0,&c,1)) {	/* read this char */
	    RestoreMode();
	    return c;
	  } else {
	    RestoreMode();
	    return -1;
	  }
	}
	
	RestoreMode();
	return -1;
}

/**********************************************************************/
/** Wait until any key pressed on console
 * 
 * \copydoc usr_oss_specification.c::UOS_KeyWait()
 *
 * \linux temporarily switches console to raw mode
 *
 * \linux If a signal is caught while the call is executing then
 * the call may return even without any keypress. Therefor, it
 * is recommended to use instead UOS_KeyPressed() within a while loop
 * until a character was received (!=-1).
 *
 * \sa UOS_KeyPressed
 */
int32 UOS_KeyWait( void )
{
	char c;

	SetRawMode();

	if (read(0,&c,1) == -1){	/*  wait for one char - read error ? */
		RestoreMode();
		return(-1);				/* all done. */
	}
	else {
		RestoreMode();
		return((int32)c);		/* return char */
	}
}

