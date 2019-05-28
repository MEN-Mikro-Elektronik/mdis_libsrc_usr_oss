/*********************  P r o g r a m  -  M o d u l e ***********************/
/*!  
 *        \file  dl_list.c
 *
 *      \author  klaus.popp@men.de
 *        $Date: 2003/06/06 09:28:29 $
 *    $Revision: 1.1 $
 * 
 *  	 \brief  Double linked list routines
 *      
 *	   \project  MDISforLinux
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
/** Initialize list header
 * \copydoc oss_specification.c::UOS_DL_NewList()
 */
UOS_DL_LIST *UOS_DL_NewList( UOS_DL_LIST *l )
{
	l->head = (UOS_DL_NODE *)&l->tail;
	l->tailpred = (UOS_DL_NODE *)&l->head;
	l->tail = (UOS_DL_NODE *)NULL;
	return l;
}

/**********************************************************************/
/** Remove a node from a list
 * \copydoc oss_specification.c::UOS_DL_Remove()
 */
UOS_DL_NODE *UOS_DL_Remove( UOS_DL_NODE *n )
{
	n->next->prev = n->prev;
	n->prev->next = n->next;
	return n;
}

/**********************************************************************/
/** Remove a node from the head of the list
 * \copydoc oss_specification.c::UOS_DL_RemHead()
 */
UOS_DL_NODE *UOS_DL_RemHead( UOS_DL_LIST *l )
{
	UOS_DL_NODE *n;
	if( l->head->next == NULL ) return NULL; /* list empty */

	n = l->head;
	l->head = n->next;
	n->next->prev = (UOS_DL_NODE *)&(l->head);

	return n;
}

/**********************************************************************/
/** Add a node at tail of list
 * \copydoc oss_specification.c::UOS_DL_AddTail()
 */
UOS_DL_NODE *UOS_DL_AddTail( UOS_DL_LIST *l, UOS_DL_NODE *n )
{
	n->prev = l->tailpred;
	l->tailpred = n;
	n->next = n->prev->next;
	n->prev->next = n;
	return n;
}
	
