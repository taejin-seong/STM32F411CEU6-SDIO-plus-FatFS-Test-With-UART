/*
 * fatfs.c
 *
 *  Created on: 2021. 4. 3.
 *      Author: sungt
 */


#include "fatfs.h"
#include "uart.h"

#ifdef _USE_HW_FATFS
#include "ff_gen_drv.h"
#include "sd_diskio.h"


static bool is_init = false;

FATFS SDFatFs;  /* File system object for SD card logical drive */
char SDPath[4]; /* SD card logical drive path */


bool fatfsInit(void)
{
  bool ret = true;

  /* TODO FATFS32 초기화 단계에서 mount를 진행 , 무조건 moun 먼저 수행해야한다. (먼저 드라이버부터 잡아줘야함) */
  if(FATFS_LinkDriver(&SD_Driver, SDPath) == 0)
  {
    if(f_mount(&SDFatFs, (TCHAR const*)SDPath, 0) == FR_OK)
    {
      is_init = true;
    }
  }
  return ret;
}





#endif /* _USE_HW_FATFS */
