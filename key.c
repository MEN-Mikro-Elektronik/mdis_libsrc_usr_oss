/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!  
 *        \file  key.c
 *
 *      \author  klaus.popp@men.de
 *        $Date: 2012/05/23 17:23:07 $
 *    $Revision: 1.4 $
 * 
 * 	   \project  MDIS4Linux USR_OSS lib
 *
 *  	 \brief  Check for key pressed
 *
 *    \switches  none
 */
/*-------------------------------[ History ]---------------------------------
 *
 * $Log: key.c,v $
 * Revision 1.4  2012/05/23 17:23:07  ts
 * R: Compiler warning about unused variable res on Ubuntu 12.04
 * M: removed variable and reformatted code such that result of read() is used
 *
 * Revision 1.3  2009/09/24 09:57:05  CRuff
 * R: compiler warning on linux system
 * M: fix compiler warning
 *
 * Revision 1.2  2003/06/06 09:29:47  kp
 * Changed headers for doxygen
 *
 * Revision 1.1  2001/01/19 14:39:43  kp
 * Initial Revision
 *
 *---------------------------------------------------------------------------
 * (c) Copyright 2000-2003 by MEN mikro elektronik GmbH, Nuremberg, Germany 
 ******************************************************************************/
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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
static const char RCSid[]="$Id: key.c,v 1.4 2012/05/23 17:23:07 ts Exp $";

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
