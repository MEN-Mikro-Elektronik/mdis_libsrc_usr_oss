#***************************  M a k e f i l e  *******************************
#  
#         Author: kp
#          $Date: 2003/06/06 09:29:49 $
#      $Revision: 1.2 $
#                      
#    Description: Makefile descriptor file for USR_OSS lib
#                      
#---------------------------------[ History ]---------------------------------
#
#   $Log: library.mak,v $
#   Revision 1.2  2003/06/06 09:29:49  kp
#   added dl_list
#
#   Revision 1.1  2001/01/19 14:39:44  kp
#   Initial Revision
#
#-----------------------------------------------------------------------------
#   (c) Copyright 2000 by MEN mikro elektronik GmbH, Nuernberg, Germany 
#*****************************************************************************
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


MAK_NAME=usr_oss

MAK_SWITCH=


MAK_INCL=$(MEN_INC_DIR)/usr_oss.h \
		 $(MEN_INC_DIR)/usr_err.h \
		 $(MEN_INC_DIR)/mdis_api.h \
		 $(MEN_INC_DIR)/../../NATIVE/MEN/usr_os.h \
		 $(MEN_MOD_DIR)/uos_int.h


MAK_INP01 = errno$(INP_SUFFIX)
MAK_INP02 = delay$(INP_SUFFIX)
MAK_INP03 = key$(INP_SUFFIX)
MAK_INP04 = 
MAK_INP05 = 
MAK_INP06 = signal$(INP_SUFFIX)
MAK_INP07 = random$(INP_SUFFIX)
MAK_INP08 = timer$(INP_SUFFIX)
MAK_INP09 = mdelay$(INP_SUFFIX)
MAK_INP10 = dl_list$(INP_SUFFIX)
MAK_INP11 = ident$(INP_SUFFIX)
MAK_INP12 = errstr$(INP_SUFFIX)

MAK_INP = $(MAK_INP01) $(MAK_INP02) $(MAK_INP03) $(MAK_INP04) \
		  $(MAK_INP05) $(MAK_INP06) $(MAK_INP07) $(MAK_INP08) \
		  $(MAK_INP09) $(MAK_INP10) $(MAK_INP11) $(MAK_INP12) 



