#***************************  M a k e f i l e  *******************************
#  
#         Author: kp
#                      
#    Description: Makefile descriptor file for USR_OSS lib
#                      
#-----------------------------------------------------------------------------
#   Copyright (c) 2000-2019, MEN Mikro Elektronik GmbH
#*****************************************************************************
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General License
# along with this program. If not, see <http://www.gnu.org/licenses/>.


MAK_NAME=usr_oss
# the next line is updated during the MDIS installation
STAMPED_REVISION="mdis_libsrc_usr_oss_02_25-9-gbd01809-dirty_2019-05-28"

DEF_REVISION=MAK_REVISION=$(STAMPED_REVISION)

MAK_SWITCH= \
		$(SW_PREFIX)$(DEF_REVISION)


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



