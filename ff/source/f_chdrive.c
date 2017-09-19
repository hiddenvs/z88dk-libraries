/*----------------------------------------------------------------------------/
/  FatFs - Generic FAT Filesystem Module  R0.13p2                             /
/-----------------------------------------------------------------------------/
/
/ Copyright (C) 2017, ChaN, all right reserved.
/
/ FatFs module is an open source software. Redistribution and use of FatFs in
/ source and binary forms, with or without modification, are permitted provided
/ that the following condition is met:
/
/ 1. Redistributions of source code must retain the above copyright notice,
/    this condition and the following disclaimer.
/
/ This software is provided by the copyright holder and contributors "AS IS"
/ and any warranties related to this software are DISCLAIMED.
/ The copyright owner or contributors be NOT LIABLE for any damages caused
/ by use of this software.
/
/----------------------------------------------------------------------------*/

#include "ff.h"         /* FatFs Public API */
#include "ffprivate.h"  /* FatFs Private Functions */
#include "ffunicode.h"  /* FatFS Unicode */

#include "__ffstore.h"          /* extern for system storage */
#include "__ffunicodestore.h"   /* extern for LFN system storage */


/*-----------------------------------------------------------------------*/
/* Change Current Directory or Current Drive, Get Current Directory      */
/*-----------------------------------------------------------------------*/
#if FF_FS_RPATH >= 1
#if FF_VOLUMES >= 2

FRESULT f_chdrive (
    const TCHAR* path        /* Drive number */
)
{
    int vol;


    /* Get logical drive number */
    vol = get_ldnumber(&path);
    if (vol < 0) return FR_INVALID_DRIVE;

    CurrVol = (BYTE)vol;    /* Set it as current volume */

    return FR_OK;
}

#endif
#endif /* FF_FS_RPATH >= 1 */

