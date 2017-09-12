/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!  
 *        \file  errno.c
 *
 *      \author  klaus.popp@men.de
 *        $Date: 2003/06/06 09:29:41 $
 *    $Revision: 1.3 $
 * 
 * 	   \project  MDIS4Linux USR_OSS lib
 *
 *  	 \brief  Error code function
 *
 *    \switches  none
 */
/*-------------------------------[ History ]---------------------------------
 *
 * $Log: errno.c,v $
 * Revision 1.3  2003/06/06 09:29:41  kp
 * Changed headers for doxygen
 *
 * Revision 1.2  2003/02/21 13:24:04  kp
 * added UOS_ErrnoSet
 *
 * Revision 1.1  2001/01/19 14:39:40  kp
 * Initial Revision
 *
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
static const char RCSid[]="$Id: errno.c,v 1.3 2003/06/06 09:29:41 kp Exp $";

#include "uos_int.h"

/**********************************************************************/
/** Get global error code (task/process specific errno)
 *	
 * \copydoc usr_oss_specification.c::UOS_ErrnoGet()
 * \sa UOS_ErrnoSet, UOS_ErrStringTs, UOS_ErrString
 */
u_int32 UOS_ErrnoGet( void )
{
	return(errno);
}

/**********************************************************************/
/** Set global error code (task/process specific errno)
 * 
 * \copydoc usr_oss_specification.c::UOS_ErrnoSet()
 * \sa UOS_ErrnoGet
 */
u_int32 UOS_ErrnoSet( u_int32 errCode )
{
	errno = errCode;
	return(errCode);
}

