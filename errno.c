/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!  
 *        \file  errno.c
 *
 *      \author  klaus.popp@men.de
 * 
 * 	   \project  MDISforLinux USR_OSS lib
 *
 *  	 \brief  Error code function
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
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

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

