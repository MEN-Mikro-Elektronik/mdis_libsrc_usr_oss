/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!  
 *        \file  random.c
 *
 *      \author  klaus.popp@men.de
 *        $Date: 2003/06/06 09:30:15 $
 *    $Revision: 1.2 $
 * 
 * 	   \project  MDIS4Linux USR_OSS lib
 *
 *  	 \brief  Create random integers
 *
 *    \switches  none
 */
/*-------------------------------[ History ]---------------------------------
 *
 * $Log: random.c,v $
 * Revision 1.2  2003/06/06 09:30:15  kp
 * Changed headers for doxygen
 *
 * Revision 1.1  2001/01/19 14:39:39  kp
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

static char RCSid[]="$Header: /dd2/CVSR/LINUX/LIBSRC/USR_OSS/random.c,v 1.2 2003/06/06 09:30:15 kp Exp $";

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <MEN/men_typs.h>
#include <MEN/usr_oss.h>


/*--------------------------------------+
|   PROTOTYPES                          |
+--------------------------------------*/

/**********************************************************************/
/** Create a new pseudo random integer value
 * 
 * \copydoc usr_oss_specification.c::UOS_Random()
 * \sa UOS_RandomMap
 */
u_int32 UOS_Random(u_int32 old)
{
	register u_int32 a = old;
			 
	a <<= 11;
	a += old;
	a <<= 2;
	old += a;
	old += 13849;
	return old;
}

/**********************************************************************/
/** Map created integer value into specified range
 *
 * \copydoc usr_oss_specification.c::UOS_RandomMap()
 * 
 * \sa UOS_Random
 */
u_int32 UOS_RandomMap(u_int32 val, u_int32 ra, u_int32 re)
{
   double  f;
   u_int32 r;

   f = (double)val / 0xffffffff;      			/* make double 0..1 */
   r = (f * (double)(re-ra)) + 0.5 + ra;    	/* expand to set, add offset */

   return(r);
}





