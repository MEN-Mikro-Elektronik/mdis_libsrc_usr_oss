/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!  
 *        \file  ident.c
 *
 *      \author  klaus.popp@men.de
 * 
 * 	   \project  MDISforLinux USR_OSS lib
 *
 *  	 \brief  USR_OSS global edition history 
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

/*! \mainpage 
 
 This is the documentation of the MEN USR_OSS library (User state
 Operating System Services) for Linux in user land.

 Refer to the \ref usrosscommonspec "USR_OSS Common Specification" for the
 plain common specification.

 For Linux, the USR_OSS module is compiled as a static or shared library
 \c libusr_oss.a or \c libusr_oss.so, that is linked to application.

 The Linux implementation does not add any specific calls to the USR_OSS
 library.
*/

/*! \page ossdummy MEN logo
 \menimages
*/

static const char IdentString[]=MENT_XSTR(MAK_REVISION);

/**********************************************************************/
/** Return ident string of UOS module
 * \copydoc usr_oss_specification.c::UOS_Ident()
 */
char* UOS_Ident( void )
{
	return( (char*) IdentString);
}






