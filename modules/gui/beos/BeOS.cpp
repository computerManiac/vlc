/*****************************************************************************
 * beos.cpp : BeOS plugin for vlc
 *****************************************************************************
 * Copyright (C) 2000, 2001 VideoLAN
 * $Id: BeOS.cpp,v 1.12 2003/06/17 16:09:16 gbazin Exp $
 *
 * Authors: Jean-Marc Dressler <polux@via.ecp.fr>
 *          Samuel Hocevar <sam@zoy.org>
 *          Stephan Aßmus <stippi@yellowbites.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
 *****************************************************************************/

/*****************************************************************************
 * Preamble
 *****************************************************************************/
#include <stdlib.h>                                      /* malloc(), free() */
#include <string.h>

#include <vlc/vlc.h>

/*****************************************************************************
 * External prototypes
 *****************************************************************************/
int  E_(OpenIntf)     ( vlc_object_t * );
void E_(CloseIntf)    ( vlc_object_t * );

int  E_(OpenAudio)    ( vlc_object_t * );
void E_(CloseAudio)   ( vlc_object_t * );

int  E_(OpenVideo)    ( vlc_object_t * );
void E_(CloseVideo)   ( vlc_object_t * );

/*****************************************************************************
 * Module descriptor
 *****************************************************************************/
static char * ppsz_screenshotformat[] = { "TGA", "PPM", "PNG", "JPEG", "BMP", NULL };

vlc_module_begin();
    add_bool( "beos-dvdmenus", 0, NULL, "Use DVD Menus", "", VLC_TRUE );
    add_string( "beos-screenshotpath", "/boot/home/", NULL, "Screenshot Path", "", VLC_TRUE );
    add_string_from_list( "beos-screenshotformat", "PNG", ppsz_screenshotformat, NULL, "Screenshot Format", "", VLC_TRUE );
    set_description( _("BeOS standard API interface") );
    set_capability( "interface", 100 );
    set_callbacks( E_(OpenIntf), E_(CloseIntf) );

    add_submodule();                                     
        set_capability( "video output", 100 );
        set_callbacks( E_(OpenVideo), E_(CloseVideo) );
    add_submodule();
        set_capability( "audio output", 100 );
        set_callbacks( E_(OpenAudio), E_(CloseAudio) );
vlc_module_end();
