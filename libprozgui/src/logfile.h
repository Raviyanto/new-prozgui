/******************************************************************************
 libprozilla - a download accelerator library
 Copyright (C) 2001 Kalum Somaratna
 
 libprozgui - a download accelerator library
 Copyright (C) 2011 Raviyanto Ahmad

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3 of the License.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
******************************************************************************/

#ifndef LOGFILE_H
#define LOGFILE_H

#include "common.h"
#include "prozilla.h"
#include "download.h"


#ifdef __cplusplus
extern "C" {
#endif


  int log_create_logfile(int num_connections, int file_size, char *url,
			 download_t * download);



#ifdef __cplusplus
}
#endif
#endif
